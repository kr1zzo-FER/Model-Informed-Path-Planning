# generated from rosidl_generator_py/resource/_idl.py.em
# with input from user_action_interfaces:msg/CoastMsg.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CoastMsg(type):
    """Metaclass of message 'CoastMsg'."""

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
            module = import_type_support('user_action_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'user_action_interfaces.msg.CoastMsg')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__coast_msg
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__coast_msg
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__coast_msg
            cls._TYPE_SUPPORT = module.type_support_msg__msg__coast_msg
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__coast_msg

            from sensor_msgs.msg import PointCloud2
            if PointCloud2.__class__._TYPE_SUPPORT is None:
                PointCloud2.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CoastMsg(metaclass=Metaclass_CoastMsg):
    """Message class 'CoastMsg'."""

    __slots__ = [
        '_header',
        '_frame_id',
        '_coast_points',
        '_green_points',
        '_red_points',
        '_yellow_points',
        '_grid_size',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'frame_id': 'string',
        'coast_points': 'sensor_msgs/PointCloud2',
        'green_points': 'sensor_msgs/PointCloud2',
        'red_points': 'sensor_msgs/PointCloud2',
        'yellow_points': 'sensor_msgs/PointCloud2',
        'grid_size': 'int32',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'PointCloud2'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'PointCloud2'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'PointCloud2'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'PointCloud2'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.frame_id = kwargs.get('frame_id', str())
        from sensor_msgs.msg import PointCloud2
        self.coast_points = kwargs.get('coast_points', PointCloud2())
        from sensor_msgs.msg import PointCloud2
        self.green_points = kwargs.get('green_points', PointCloud2())
        from sensor_msgs.msg import PointCloud2
        self.red_points = kwargs.get('red_points', PointCloud2())
        from sensor_msgs.msg import PointCloud2
        self.yellow_points = kwargs.get('yellow_points', PointCloud2())
        self.grid_size = kwargs.get('grid_size', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
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
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.frame_id != other.frame_id:
            return False
        if self.coast_points != other.coast_points:
            return False
        if self.green_points != other.green_points:
            return False
        if self.red_points != other.red_points:
            return False
        if self.yellow_points != other.yellow_points:
            return False
        if self.grid_size != other.grid_size:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if self._check_fields:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def frame_id(self):
        """Message field 'frame_id'."""
        return self._frame_id

    @frame_id.setter
    def frame_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'frame_id' field must be of type 'str'"
        self._frame_id = value

    @builtins.property
    def coast_points(self):
        """Message field 'coast_points'."""
        return self._coast_points

    @coast_points.setter
    def coast_points(self, value):
        if self._check_fields:
            from sensor_msgs.msg import PointCloud2
            assert \
                isinstance(value, PointCloud2), \
                "The 'coast_points' field must be a sub message of type 'PointCloud2'"
        self._coast_points = value

    @builtins.property
    def green_points(self):
        """Message field 'green_points'."""
        return self._green_points

    @green_points.setter
    def green_points(self, value):
        if self._check_fields:
            from sensor_msgs.msg import PointCloud2
            assert \
                isinstance(value, PointCloud2), \
                "The 'green_points' field must be a sub message of type 'PointCloud2'"
        self._green_points = value

    @builtins.property
    def red_points(self):
        """Message field 'red_points'."""
        return self._red_points

    @red_points.setter
    def red_points(self, value):
        if self._check_fields:
            from sensor_msgs.msg import PointCloud2
            assert \
                isinstance(value, PointCloud2), \
                "The 'red_points' field must be a sub message of type 'PointCloud2'"
        self._red_points = value

    @builtins.property
    def yellow_points(self):
        """Message field 'yellow_points'."""
        return self._yellow_points

    @yellow_points.setter
    def yellow_points(self, value):
        if self._check_fields:
            from sensor_msgs.msg import PointCloud2
            assert \
                isinstance(value, PointCloud2), \
                "The 'yellow_points' field must be a sub message of type 'PointCloud2'"
        self._yellow_points = value

    @builtins.property
    def grid_size(self):
        """Message field 'grid_size'."""
        return self._grid_size

    @grid_size.setter
    def grid_size(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'grid_size' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'grid_size' field must be an integer in [-2147483648, 2147483647]"
        self._grid_size = value
