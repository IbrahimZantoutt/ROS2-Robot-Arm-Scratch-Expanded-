cmake_minimum_required(VERSION 3.8)
project(main_arm_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(action_interfaces REQUIRED)
find_package(sensor_msgs REQUIRED)


add_executable(ArmController src/ArmController.cpp)
add_executable(ArmMonitor src/ArmMonitor.cpp)
add_executable(ArmMover src/ArmMover.cpp)
add_executable(ArmClient src/ArmClient.cpp)
target_include_directories(ArmController PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(ArmController PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

ament_target_dependencies(ArmController rclcpp action_interfaces sensor_msgs)
ament_target_dependencies(ArmMonitor rclcpp action_interfaces)
ament_target_dependencies(ArmMover rclcpp rclcpp_action action_interfaces)
ament_target_dependencies(ArmClient rclcpp rclcpp_action action_interfaces)

install(TARGETS 
ArmController
ArmMonitor
ArmMover
ArmClient
  DESTINATION lib/${PROJECT_NAME})

#launch files
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

#urdf files
install(DIRECTORY urdf
  DESTINATION share/${PROJECT_NAME})

#rviz config
install(DIRECTORY rviz
  DESTINATION share/${PROJECT_NAME})

# gazebo world files
# install(DIRECTORY worlds
#   DESTINATION share/${PROJECT_NAME})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
