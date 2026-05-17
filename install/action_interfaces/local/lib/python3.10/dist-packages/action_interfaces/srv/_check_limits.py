# generated from rosidl_generator_py/resource/_idl.py.em
# with input from action_interfaces:srv/CheckLimits.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CheckLimits_Request(type):
    """Metaclass of message 'CheckLimits_Request'."""

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
                'action_interfaces.srv.CheckLimits_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__check_limits__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__check_limits__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__check_limits__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__check_limits__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__check_limits__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CheckLimits_Request(metaclass=Metaclass_CheckLimits_Request):
    """Message class 'CheckLimits_Request'."""

    __slots__ = [
        '_shoulder_angle',
        '_elbow_angle',
        '_wrist_angle',
    ]

    _fields_and_field_types = {
        'shoulder_angle': 'float',
        'elbow_angle': 'float',
        'wrist_angle': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.shoulder_angle = kwargs.get('shoulder_angle', float())
        self.elbow_angle = kwargs.get('elbow_angle', float())
        self.wrist_angle = kwargs.get('wrist_angle', float())

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
        if self.shoulder_angle != other.shoulder_angle:
            return False
        if self.elbow_angle != other.elbow_angle:
            return False
        if self.wrist_angle != other.wrist_angle:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def shoulder_angle(self):
        """Message field 'shoulder_angle'."""
        return self._shoulder_angle

    @shoulder_angle.setter
    def shoulder_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'shoulder_angle' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'shoulder_angle' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._shoulder_angle = value

    @builtins.property
    def elbow_angle(self):
        """Message field 'elbow_angle'."""
        return self._elbow_angle

    @elbow_angle.setter
    def elbow_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'elbow_angle' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'elbow_angle' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._elbow_angle = value

    @builtins.property
    def wrist_angle(self):
        """Message field 'wrist_angle'."""
        return self._wrist_angle

    @wrist_angle.setter
    def wrist_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'wrist_angle' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'wrist_angle' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._wrist_angle = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_CheckLimits_Response(type):
    """Metaclass of message 'CheckLimits_Response'."""

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
                'action_interfaces.srv.CheckLimits_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__check_limits__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__check_limits__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__check_limits__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__check_limits__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__check_limits__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CheckLimits_Response(metaclass=Metaclass_CheckLimits_Response):
    """Message class 'CheckLimits_Response'."""

    __slots__ = [
        '_is_safe',
        '_message',
    ]

    _fields_and_field_types = {
        'is_safe': 'boolean',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.is_safe = kwargs.get('is_safe', bool())
        self.message = kwargs.get('message', str())

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
        if self.is_safe != other.is_safe:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def is_safe(self):
        """Message field 'is_safe'."""
        return self._is_safe

    @is_safe.setter
    def is_safe(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_safe' field must be of type 'bool'"
        self._is_safe = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_CheckLimits(type):
    """Metaclass of service 'CheckLimits'."""

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
                'action_interfaces.srv.CheckLimits')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__check_limits

            from action_interfaces.srv import _check_limits
            if _check_limits.Metaclass_CheckLimits_Request._TYPE_SUPPORT is None:
                _check_limits.Metaclass_CheckLimits_Request.__import_type_support__()
            if _check_limits.Metaclass_CheckLimits_Response._TYPE_SUPPORT is None:
                _check_limits.Metaclass_CheckLimits_Response.__import_type_support__()


class CheckLimits(metaclass=Metaclass_CheckLimits):
    from action_interfaces.srv._check_limits import CheckLimits_Request as Request
    from action_interfaces.srv._check_limits import CheckLimits_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
