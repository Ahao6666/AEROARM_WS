# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "sim2real: 1 messages, 1 services")

set(MSG_I_FLAGS "-Isim2real:/home/ahao/catkin_ws/src/sim2real/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(sim2real_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/ahao/catkin_ws/src/sim2real/msg/position_pub.msg" NAME_WE)
add_custom_target(_sim2real_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "sim2real" "/home/ahao/catkin_ws/src/sim2real/msg/position_pub.msg" ""
)

get_filename_component(_filename "/home/ahao/catkin_ws/src/sim2real/srv/cmd_mode.srv" NAME_WE)
add_custom_target(_sim2real_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "sim2real" "/home/ahao/catkin_ws/src/sim2real/srv/cmd_mode.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(sim2real
  "/home/ahao/catkin_ws/src/sim2real/msg/position_pub.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sim2real
)

### Generating Services
_generate_srv_cpp(sim2real
  "/home/ahao/catkin_ws/src/sim2real/srv/cmd_mode.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sim2real
)

### Generating Module File
_generate_module_cpp(sim2real
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sim2real
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(sim2real_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(sim2real_generate_messages sim2real_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ahao/catkin_ws/src/sim2real/msg/position_pub.msg" NAME_WE)
add_dependencies(sim2real_generate_messages_cpp _sim2real_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/sim2real/srv/cmd_mode.srv" NAME_WE)
add_dependencies(sim2real_generate_messages_cpp _sim2real_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sim2real_gencpp)
add_dependencies(sim2real_gencpp sim2real_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sim2real_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(sim2real
  "/home/ahao/catkin_ws/src/sim2real/msg/position_pub.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/sim2real
)

### Generating Services
_generate_srv_eus(sim2real
  "/home/ahao/catkin_ws/src/sim2real/srv/cmd_mode.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/sim2real
)

### Generating Module File
_generate_module_eus(sim2real
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/sim2real
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(sim2real_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(sim2real_generate_messages sim2real_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ahao/catkin_ws/src/sim2real/msg/position_pub.msg" NAME_WE)
add_dependencies(sim2real_generate_messages_eus _sim2real_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/sim2real/srv/cmd_mode.srv" NAME_WE)
add_dependencies(sim2real_generate_messages_eus _sim2real_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sim2real_geneus)
add_dependencies(sim2real_geneus sim2real_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sim2real_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(sim2real
  "/home/ahao/catkin_ws/src/sim2real/msg/position_pub.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sim2real
)

### Generating Services
_generate_srv_lisp(sim2real
  "/home/ahao/catkin_ws/src/sim2real/srv/cmd_mode.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sim2real
)

### Generating Module File
_generate_module_lisp(sim2real
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sim2real
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(sim2real_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(sim2real_generate_messages sim2real_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ahao/catkin_ws/src/sim2real/msg/position_pub.msg" NAME_WE)
add_dependencies(sim2real_generate_messages_lisp _sim2real_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/sim2real/srv/cmd_mode.srv" NAME_WE)
add_dependencies(sim2real_generate_messages_lisp _sim2real_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sim2real_genlisp)
add_dependencies(sim2real_genlisp sim2real_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sim2real_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(sim2real
  "/home/ahao/catkin_ws/src/sim2real/msg/position_pub.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/sim2real
)

### Generating Services
_generate_srv_nodejs(sim2real
  "/home/ahao/catkin_ws/src/sim2real/srv/cmd_mode.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/sim2real
)

### Generating Module File
_generate_module_nodejs(sim2real
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/sim2real
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(sim2real_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(sim2real_generate_messages sim2real_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ahao/catkin_ws/src/sim2real/msg/position_pub.msg" NAME_WE)
add_dependencies(sim2real_generate_messages_nodejs _sim2real_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/sim2real/srv/cmd_mode.srv" NAME_WE)
add_dependencies(sim2real_generate_messages_nodejs _sim2real_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sim2real_gennodejs)
add_dependencies(sim2real_gennodejs sim2real_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sim2real_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(sim2real
  "/home/ahao/catkin_ws/src/sim2real/msg/position_pub.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sim2real
)

### Generating Services
_generate_srv_py(sim2real
  "/home/ahao/catkin_ws/src/sim2real/srv/cmd_mode.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sim2real
)

### Generating Module File
_generate_module_py(sim2real
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sim2real
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(sim2real_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(sim2real_generate_messages sim2real_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ahao/catkin_ws/src/sim2real/msg/position_pub.msg" NAME_WE)
add_dependencies(sim2real_generate_messages_py _sim2real_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/sim2real/srv/cmd_mode.srv" NAME_WE)
add_dependencies(sim2real_generate_messages_py _sim2real_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sim2real_genpy)
add_dependencies(sim2real_genpy sim2real_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sim2real_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sim2real)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sim2real
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(sim2real_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/sim2real)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/sim2real
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(sim2real_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sim2real)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sim2real
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(sim2real_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/sim2real)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/sim2real
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(sim2real_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sim2real)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sim2real\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sim2real
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(sim2real_generate_messages_py std_msgs_generate_messages_py)
endif()
