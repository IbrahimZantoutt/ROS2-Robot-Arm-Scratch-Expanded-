# generated from rosidl_generator_py/resource/_idl.py.em
# with input from action_interfaces:action/MoveArm.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MoveArm_Goal(type):
    """Metaclass of message 'MoveArm_Goal'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interfaces.action.MoveArm_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm__goal

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArm_Goal(metaclass=Metaclass_MoveArm_Goal):
    """Message class 'MoveArm_Goal'."""

    __slots__ = [
        '_target_x',
        '_target_y',
        '_target_z',
        '_configuration',
    ]

    _fields_and_field_types = {
        'target_x': 'float',
        'target_y': 'float',
        'target_z': 'float',
        'configuration': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.target_x = kwargs.get('target_x', float())
        self.target_y = kwargs.get('target_y', float())
        self.target_z = kwargs.get('target_z', float())
        self.configuration = kwargs.get('configuration', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.target_x != other.target_x:
            return False
        if self.target_y != other.target_y:
            return False
        if self.target_z != other.target_z:
            return False
        if self.configuration != other.configuration:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def target_x(self):
        """Message field 'target_x'."""
        return self._target_x

    @target_x.setter
    def target_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'target_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._target_x = value

    @builtins.property
    def target_y(self):
        """Message field 'target_y'."""
        return self._target_y

    @target_y.setter
    def target_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'target_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._target_y = value

    @builtins.property
    def target_z(self):
        """Message field 'target_z'."""
        return self._target_z

    @target_z.setter
    def target_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'target_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._target_z = value

    @builtins.property
    def configuration(self):
        """Message field 'configuration'."""
        return self._configuration

    @configuration.setter
    def configuration(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'configuration' field must be of type 'str'"
        self._configuration = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveArm_Result(type):
    """Metaclass of message 'MoveArm_Result'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interfaces.action.MoveArm_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArm_Result(metaclass=Metaclass_MoveArm_Result):
    """Message class 'MoveArm_Result'."""

    __slots__ = [
        '_shoulder_angle_rs',
        '_elbow_angle_rs',
        '_wrist_angle_rs',
        '_spin_angle_rs',
    ]

    _fields_and_field_types = {
        'shoulder_angle_rs': 'float',
        'elbow_angle_rs': 'float',
        'wrist_angle_rs': 'float',
        'spin_angle_rs': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.shoulder_angle_rs = kwargs.get('shoulder_angle_rs', float())
        self.elbow_angle_rs = kwargs.get('elbow_angle_rs', float())
        self.wrist_angle_rs = kwargs.get('wrist_angle_rs', float())
        self.spin_angle_rs = kwargs.get('spin_angle_rs', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.shoulder_angle_rs != other.shoulder_angle_rs:
            return False
        if self.elbow_angle_rs != other.elbow_angle_rs:
            return False
        if self.wrist_angle_rs != other.wrist_angle_rs:
            return False
        if self.spin_angle_rs != other.spin_angle_rs:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def shoulder_angle_rs(self):
        """Message field 'shoulder_angle_rs'."""
        return self._shoulder_angle_rs

    @shoulder_angle_rs.setter
    def shoulder_angle_rs(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'shoulder_angle_rs' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'shoulder_angle_rs' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._shoulder_angle_rs = value

    @builtins.property
    def elbow_angle_rs(self):
        """Message field 'elbow_angle_rs'."""
        return self._elbow_angle_rs

    @elbow_angle_rs.setter
    def elbow_angle_rs(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'elbow_angle_rs' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'elbow_angle_rs' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._elbow_angle_rs = value

    @builtins.property
    def wrist_angle_rs(self):
        """Message field 'wrist_angle_rs'."""
        return self._wrist_angle_rs

    @wrist_angle_rs.setter
    def wrist_angle_rs(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'wrist_angle_rs' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'wrist_angle_rs' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._wrist_angle_rs = value

    @builtins.property
    def spin_angle_rs(self):
        """Message field 'spin_angle_rs'."""
        return self._spin_angle_rs

    @spin_angle_rs.setter
    def spin_angle_rs(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'spin_angle_rs' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'spin_angle_rs' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._spin_angle_rs = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveArm_Feedback(type):
    """Metaclass of message 'MoveArm_Feedback'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interfaces.action.MoveArm_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArm_Feedback(metaclass=Metaclass_MoveArm_Feedback):
    """Message class 'MoveArm_Feedback'."""

    __slots__ = [
        '_shoulder_angle_fb',
        '_elbow_angle_fb',
        '_wrist_angle_fb',
        '_spin_angle_fb',
    ]

    _fields_and_field_types = {
        'shoulder_angle_fb': 'float',
        'elbow_angle_fb': 'float',
        'wrist_angle_fb': 'float',
        'spin_angle_fb': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.shoulder_angle_fb = kwargs.get('shoulder_angle_fb', float())
        self.elbow_angle_fb = kwargs.get('elbow_angle_fb', float())
        self.wrist_angle_fb = kwargs.get('wrist_angle_fb', float())
        self.spin_angle_fb = kwargs.get('spin_angle_fb', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.shoulder_angle_fb != other.shoulder_angle_fb:
            return False
        if self.elbow_angle_fb != other.elbow_angle_fb:
            return False
        if self.wrist_angle_fb != other.wrist_angle_fb:
            return False
        if self.spin_angle_fb != other.spin_angle_fb:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def shoulder_angle_fb(self):
        """Message field 'shoulder_angle_fb'."""
        return self._shoulder_angle_fb

    @shoulder_angle_fb.setter
    def shoulder_angle_fb(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'shoulder_angle_fb' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'shoulder_angle_fb' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._shoulder_angle_fb = value

    @builtins.property
    def elbow_angle_fb(self):
        """Message field 'elbow_angle_fb'."""
        return self._elbow_angle_fb

    @elbow_angle_fb.setter
    def elbow_angle_fb(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'elbow_angle_fb' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'elbow_angle_fb' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._elbow_angle_fb = value

    @builtins.property
    def wrist_angle_fb(self):
        """Message field 'wrist_angle_fb'."""
        return self._wrist_angle_fb

    @wrist_angle_fb.setter
    def wrist_angle_fb(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'wrist_angle_fb' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'wrist_angle_fb' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._wrist_angle_fb = value

    @builtins.property
    def spin_angle_fb(self):
        """Message field 'spin_angle_fb'."""
        return self._spin_angle_fb

    @spin_angle_fb.setter
    def spin_angle_fb(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'spin_angle_fb' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'spin_angle_fb' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._spin_angle_fb = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveArm_SendGoal_Request(type):
    """Metaclass of message 'MoveArm_SendGoal_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interfaces.action.MoveArm_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm__send_goal__request

            from action_interfaces.action import MoveArm
            if MoveArm.Goal.__class__._TYPE_SUPPORT is None:
                MoveArm.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArm_SendGoal_Request(metaclass=Metaclass_MoveArm_SendGoal_Request):
    """Message class 'MoveArm_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'action_interfaces/MoveArm_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['action_interfaces', 'action'], 'MoveArm_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from action_interfaces.action._move_arm import MoveArm_Goal
        self.goal = kwargs.get('goal', MoveArm_Goal())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from action_interfaces.action._move_arm import MoveArm_Goal
            assert \
                isinstance(value, MoveArm_Goal), \
                "The 'goal' field must be a sub message of type 'MoveArm_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveArm_SendGoal_Response(type):
    """Metaclass of message 'MoveArm_SendGoal_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interfaces.action.MoveArm_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArm_SendGoal_Response(metaclass=Metaclass_MoveArm_SendGoal_Response):
    """Message class 'MoveArm_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_MoveArm_SendGoal(type):
    """Metaclass of service 'MoveArm_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interfaces.action.MoveArm_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__move_arm__send_goal

            from action_interfaces.action import _move_arm
            if _move_arm.Metaclass_MoveArm_SendGoal_Request._TYPE_SUPPORT is None:
                _move_arm.Metaclass_MoveArm_SendGoal_Request.__import_type_support__()
            if _move_arm.Metaclass_MoveArm_SendGoal_Response._TYPE_SUPPORT is None:
                _move_arm.Metaclass_MoveArm_SendGoal_Response.__import_type_support__()


class MoveArm_SendGoal(metaclass=Metaclass_MoveArm_SendGoal):
    from action_interfaces.action._move_arm import MoveArm_SendGoal_Request as Request
    from action_interfaces.action._move_arm import MoveArm_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveArm_GetResult_Request(type):
    """Metaclass of message 'MoveArm_GetResult_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interfaces.action.MoveArm_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArm_GetResult_Request(metaclass=Metaclass_MoveArm_GetResult_Request):
    """Message class 'MoveArm_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveArm_GetResult_Response(type):
    """Metaclass of message 'MoveArm_GetResult_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interfaces.action.MoveArm_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm__get_result__response

            from action_interfaces.action import MoveArm
            if MoveArm.Result.__class__._TYPE_SUPPORT is None:
                MoveArm.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArm_GetResult_Response(metaclass=Metaclass_MoveArm_GetResult_Response):
    """Message class 'MoveArm_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'action_interfaces/MoveArm_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['action_interfaces', 'action'], 'MoveArm_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from action_interfaces.action._move_arm import MoveArm_Result
        self.result = kwargs.get('result', MoveArm_Result())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from action_interfaces.action._move_arm import MoveArm_Result
            assert \
                isinstance(value, MoveArm_Result), \
                "The 'result' field must be a sub message of type 'MoveArm_Result'"
        self._result = value


class Metaclass_MoveArm_GetResult(type):
    """Metaclass of service 'MoveArm_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interfaces.action.MoveArm_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__move_arm__get_result

            from action_interfaces.action import _move_arm
            if _move_arm.Metaclass_MoveArm_GetResult_Request._TYPE_SUPPORT is None:
                _move_arm.Metaclass_MoveArm_GetResult_Request.__import_type_support__()
            if _move_arm.Metaclass_MoveArm_GetResult_Response._TYPE_SUPPORT is None:
                _move_arm.Metaclass_MoveArm_GetResult_Response.__import_type_support__()


class MoveArm_GetResult(metaclass=Metaclass_MoveArm_GetResult):
    from action_interfaces.action._move_arm import MoveArm_GetResult_Request as Request
    from action_interfaces.action._move_arm import MoveArm_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveArm_FeedbackMessage(type):
    """Metaclass of message 'MoveArm_FeedbackMessage'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interfaces.action.MoveArm_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__move_arm__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__move_arm__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__move_arm__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__move_arm__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__move_arm__feedback_message

            from action_interfaces.action import MoveArm
            if MoveArm.Feedback.__class__._TYPE_SUPPORT is None:
                MoveArm.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveArm_FeedbackMessage(metaclass=Metaclass_MoveArm_FeedbackMessage):
    """Message class 'MoveArm_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'action_interfaces/MoveArm_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['action_interfaces', 'action'], 'MoveArm_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from action_interfaces.action._move_arm import MoveArm_Feedback
        self.feedback = kwargs.get('feedback', MoveArm_Feedback())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from action_interfaces.action._move_arm import MoveArm_Feedback
            assert \
                isinstance(value, MoveArm_Feedback), \
                "The 'feedback' field must be a sub message of type 'MoveArm_Feedback'"
        self._feedback = value


class Metaclass_MoveArm(type):
    """Metaclass of action 'MoveArm'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interfaces.action.MoveArm')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__move_arm

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from action_interfaces.action import _move_arm
            if _move_arm.Metaclass_MoveArm_SendGoal._TYPE_SUPPORT is None:
                _move_arm.Metaclass_MoveArm_SendGoal.__import_type_support__()
            if _move_arm.Metaclass_MoveArm_GetResult._TYPE_SUPPORT is None:
                _move_arm.Metaclass_MoveArm_GetResult.__import_type_support__()
            if _move_arm.Metaclass_MoveArm_FeedbackMessage._TYPE_SUPPORT is None:
                _move_arm.Metaclass_MoveArm_FeedbackMessage.__import_type_support__()


class MoveArm(metaclass=Metaclass_MoveArm):

    # The goal message defined in the action definition.
    from action_interfaces.action._move_arm import MoveArm_Goal as Goal
    # The result message defined in the action definition.
    from action_interfaces.action._move_arm import MoveArm_Result as Result
    # The feedback message defined in the action definition.
    from action_interfaces.action._move_arm import MoveArm_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from action_interfaces.action._move_arm import MoveArm_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from action_interfaces.action._move_arm import MoveArm_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from action_interfaces.action._move_arm import MoveArm_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
