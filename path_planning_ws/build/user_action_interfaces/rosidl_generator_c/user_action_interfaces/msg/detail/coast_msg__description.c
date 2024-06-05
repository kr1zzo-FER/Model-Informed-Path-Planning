// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from user_action_interfaces:msg/CoastMsg.idl
// generated code does not contain a copyright notice

#include "user_action_interfaces/msg/detail/coast_msg__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_user_action_interfaces
const rosidl_type_hash_t *
user_action_interfaces__msg__CoastMsg__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x4b, 0xa0, 0x1f, 0xee, 0x56, 0x52, 0xb8, 0x12,
      0xd8, 0xaa, 0x9d, 0x16, 0x66, 0xad, 0x1d, 0x40,
      0x39, 0x8c, 0x85, 0xeb, 0x5a, 0x52, 0x53, 0x61,
      0xaf, 0x4c, 0xb5, 0xd9, 0xdc, 0xb1, 0x81, 0xc1,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/float32_multi_array__functions.h"
#include "std_msgs/msg/detail/multi_array_layout__functions.h"
#include "std_msgs/msg/detail/header__functions.h"
#include "std_msgs/msg/detail/multi_array_dimension__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t std_msgs__msg__Float32MultiArray__EXPECTED_HASH = {1, {
    0x05, 0x99, 0xf6, 0xf8, 0x5b, 0x4b, 0xfc, 0xa3,
    0x79, 0x87, 0x3a, 0x0b, 0x43, 0x75, 0xa0, 0xac,
    0xa0, 0x22, 0x15, 0x6b, 0xd2, 0xd7, 0x02, 0x12,
    0x75, 0xd1, 0x16, 0xed, 0x1f, 0xa8, 0xbf, 0xe0,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
static const rosidl_type_hash_t std_msgs__msg__MultiArrayDimension__EXPECTED_HASH = {1, {
    0x5e, 0x77, 0x3a, 0x60, 0xa4, 0xc7, 0xfc, 0x8a,
    0x54, 0x98, 0x5f, 0x30, 0x7c, 0x78, 0x37, 0xaa,
    0x29, 0x94, 0x25, 0x2a, 0x12, 0x6c, 0x30, 0x19,
    0x57, 0xa2, 0x4e, 0x31, 0x28, 0x2c, 0x9c, 0xbe,
  }};
static const rosidl_type_hash_t std_msgs__msg__MultiArrayLayout__EXPECTED_HASH = {1, {
    0x4c, 0x66, 0xe6, 0xf7, 0x8e, 0x74, 0x0a, 0xc1,
    0x03, 0xa9, 0x4c, 0xf6, 0x32, 0x59, 0xf9, 0x68,
    0xe4, 0x8c, 0x61, 0x7e, 0x76, 0x99, 0xe8, 0x29,
    0xb6, 0x3c, 0x21, 0xa5, 0xcb, 0x50, 0xda, 0xc6,
  }};
#endif

static char user_action_interfaces__msg__CoastMsg__TYPE_NAME[] = "user_action_interfaces/msg/CoastMsg";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Float32MultiArray__TYPE_NAME[] = "std_msgs/msg/Float32MultiArray";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";
static char std_msgs__msg__MultiArrayDimension__TYPE_NAME[] = "std_msgs/msg/MultiArrayDimension";
static char std_msgs__msg__MultiArrayLayout__TYPE_NAME[] = "std_msgs/msg/MultiArrayLayout";

// Define type names, field names, and default values
static char user_action_interfaces__msg__CoastMsg__FIELD_NAME__header[] = "header";
static char user_action_interfaces__msg__CoastMsg__FIELD_NAME__frame_id[] = "frame_id";
static char user_action_interfaces__msg__CoastMsg__FIELD_NAME__coast_points_x[] = "coast_points_x";
static char user_action_interfaces__msg__CoastMsg__FIELD_NAME__green_points_x[] = "green_points_x";
static char user_action_interfaces__msg__CoastMsg__FIELD_NAME__red_points_x[] = "red_points_x";
static char user_action_interfaces__msg__CoastMsg__FIELD_NAME__yellow_points_x[] = "yellow_points_x";
static char user_action_interfaces__msg__CoastMsg__FIELD_NAME__coast_points_y[] = "coast_points_y";
static char user_action_interfaces__msg__CoastMsg__FIELD_NAME__green_points_y[] = "green_points_y";
static char user_action_interfaces__msg__CoastMsg__FIELD_NAME__red_points_y[] = "red_points_y";
static char user_action_interfaces__msg__CoastMsg__FIELD_NAME__yellow_points_y[] = "yellow_points_y";
static char user_action_interfaces__msg__CoastMsg__FIELD_NAME__grid_size[] = "grid_size";

static rosidl_runtime_c__type_description__Field user_action_interfaces__msg__CoastMsg__FIELDS[] = {
  {
    {user_action_interfaces__msg__CoastMsg__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {user_action_interfaces__msg__CoastMsg__FIELD_NAME__frame_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {user_action_interfaces__msg__CoastMsg__FIELD_NAME__coast_points_x, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Float32MultiArray__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {user_action_interfaces__msg__CoastMsg__FIELD_NAME__green_points_x, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Float32MultiArray__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {user_action_interfaces__msg__CoastMsg__FIELD_NAME__red_points_x, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Float32MultiArray__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {user_action_interfaces__msg__CoastMsg__FIELD_NAME__yellow_points_x, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Float32MultiArray__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {user_action_interfaces__msg__CoastMsg__FIELD_NAME__coast_points_y, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Float32MultiArray__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {user_action_interfaces__msg__CoastMsg__FIELD_NAME__green_points_y, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Float32MultiArray__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {user_action_interfaces__msg__CoastMsg__FIELD_NAME__red_points_y, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Float32MultiArray__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {user_action_interfaces__msg__CoastMsg__FIELD_NAME__yellow_points_y, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Float32MultiArray__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {user_action_interfaces__msg__CoastMsg__FIELD_NAME__grid_size, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription user_action_interfaces__msg__CoastMsg__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Float32MultiArray__TYPE_NAME, 30, 30},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayDimension__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayLayout__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
user_action_interfaces__msg__CoastMsg__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {user_action_interfaces__msg__CoastMsg__TYPE_NAME, 35, 35},
      {user_action_interfaces__msg__CoastMsg__FIELDS, 11, 11},
    },
    {user_action_interfaces__msg__CoastMsg__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Float32MultiArray__EXPECTED_HASH, std_msgs__msg__Float32MultiArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__Float32MultiArray__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayDimension__EXPECTED_HASH, std_msgs__msg__MultiArrayDimension__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = std_msgs__msg__MultiArrayDimension__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayLayout__EXPECTED_HASH, std_msgs__msg__MultiArrayLayout__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = std_msgs__msg__MultiArrayLayout__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/Header header\n"
  "string frame_id  \n"
  "std_msgs/Float32MultiArray coast_points_x\n"
  "std_msgs/Float32MultiArray green_points_x\n"
  "std_msgs/Float32MultiArray red_points_x\n"
  "std_msgs/Float32MultiArray yellow_points_x\n"
  "std_msgs/Float32MultiArray coast_points_y\n"
  "std_msgs/Float32MultiArray green_points_y\n"
  "std_msgs/Float32MultiArray red_points_y\n"
  "std_msgs/Float32MultiArray yellow_points_y\n"
  "float32 grid_size";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
user_action_interfaces__msg__CoastMsg__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {user_action_interfaces__msg__CoastMsg__TYPE_NAME, 35, 35},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 393, 393},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
user_action_interfaces__msg__CoastMsg__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *user_action_interfaces__msg__CoastMsg__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Float32MultiArray__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    sources[4] = *std_msgs__msg__MultiArrayDimension__get_individual_type_description_source(NULL);
    sources[5] = *std_msgs__msg__MultiArrayLayout__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
