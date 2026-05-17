#include "rclcpp/rclcpp.hpp"
#include "action_interfaces/msg/arm_state.hpp"
#include "action_interfaces/srv/check_limits.hpp"

class ArmMonitor: public rclcpp::Node{
    public:
        ArmMonitor():Node("arm_monitor"){
            RCLCPP_INFO(this->get_logger(), "ArmMonitor node has been started.");
            arm_state_subscription_ = this->create_subscription<action_interfaces::msg::ArmState>("arm_state", 10, std::bind(&ArmMonitor::handleArmState, this, std::placeholders::_1));
            this->declare_parameter("shoulder_threshold", std::vector<double>{-90.0, 90.0});
            this->declare_parameter("elbow_threshold", std::vector<double>{0.0, 135.0});
            this->declare_parameter("wrist_threshold", std::vector<double>{-90.0, 90.0});

            arm_check_server = this->create_service<action_interfaces::srv::CheckLimits>(
                "check_limits",
                 std::bind(&ArmMonitor::handleCheckArm, this, std::placeholders::_1, std::placeholders::_2)
            );

        }
        void handleCheckArm(const std::shared_ptr<action_interfaces::srv::CheckLimits::Request> request, std::shared_ptr<action_interfaces::srv::CheckLimits::Response> response){
            auto ShdA = request->shoulder_angle;
            auto ElbA = request->elbow_angle; 
            auto WstA = request->wrist_angle; 

            std::vector<double> shoulder_threshold = this->get_parameter("shoulder_threshold").as_double_array();
            std::vector<double> elbow_threshold = this->get_parameter("elbow_threshold").as_double_array();
            std::vector<double> wrist_threshold = this->get_parameter("elbow_threshold").as_double_array();

            if((ShdA >= shoulder_threshold[0] && ShdA <= shoulder_threshold[1]) && (ElbA >= elbow_threshold[0] && ElbA <= elbow_threshold[1])){
                RCLCPP_INFO(this->get_logger(), "Arm angles within limits: Shoulder: %f deg  Elbow: %f deg", ShdA, ElbA);
                response->is_safe = true;
            } else {
                RCLCPP_WARN(this->get_logger(), "Arm angles out of bounds: Shoulder: %f deg  Elbow: %f deg", ShdA, ElbA);
                response->is_safe = false;
            }
            
        }
    
    private:
        rclcpp::Subscription<action_interfaces::msg::ArmState>::SharedPtr arm_state_subscription_;
        rclcpp::Service<action_interfaces::srv::CheckLimits>::SharedPtr arm_check_server;

        float current_shoulder_angle_;
        float current_elbow_angle_;
        
        void handleArmState(const action_interfaces::msg::ArmState::SharedPtr msg){
            auto ShdA = msg->shoulder_angle;
            auto ElbA = msg->elbow_angle; 

            current_shoulder_angle_ = ShdA;
            current_elbow_angle_ = ElbA;

            std::vector<double> shoulder_threshold = this->get_parameter("shoulder_threshold").as_double_array();
            std::vector<double> elbow_threshold = this->get_parameter("elbow_threshold").as_double_array();

            if(ShdA < shoulder_threshold[0]  || ShdA > shoulder_threshold[1]){
                RCLCPP_WARN(this->get_logger(), "Shoulder angle out of bounds: %f", ShdA);
            }
            if(ElbA < elbow_threshold[0]  || ElbA > elbow_threshold[1]){
                RCLCPP_WARN(this->get_logger(), "Elbow angle out of bounds: %f", ElbA);
            }

        }
};

int main(int argc, char** argv){
    rclcpp::init(argc,argv);
    auto arm_monitor_node = std::make_shared<ArmMonitor>();
    rclcpp::spin(arm_monitor_node);
    rclcpp::shutdown();
    return 0;
}