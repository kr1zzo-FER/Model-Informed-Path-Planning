# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_user_commands_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED user_commands_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(user_commands_FOUND FALSE)
  elseif(NOT user_commands_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(user_commands_FOUND FALSE)
  endif()
  return()
endif()
set(_user_commands_CONFIG_INCLUDED TRUE)

# output package information
if(NOT user_commands_FIND_QUIETLY)
  message(STATUS "Found user_commands: 0.0.0 (${user_commands_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'user_commands' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT user_commands_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(user_commands_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${user_commands_DIR}/${_extra}")
endforeach()
