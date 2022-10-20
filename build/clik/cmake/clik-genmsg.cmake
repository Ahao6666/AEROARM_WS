# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "clik: 2 messages, 3 services")

set(MSG_I_FLAGS "-Iclik:/home/ahao/catkin_ws/src/clik/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(clik_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/traj_solver_msg.srv" NAME_WE)
add_custom_target(_clik_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "clik" "/home/ahao/catkin_ws/src/clik/srv/traj_solver_msg.srv" ""
)

get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/msg/position_pub.msg" NAME_WE)
add_custom_target(_clik_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "clik" "/home/ahao/catkin_ws/src/clik/msg/position_pub.msg" ""
)

get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/msg/action.msg" NAME_WE)
add_custom_target(_clik_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "clik" "/home/ahao/catkin_ws/src/clik/msg/action.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/manipulator_mode.srv" NAME_WE)
add_custom_target(_clik_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "clik" "/home/ahao/catkin_ws/src/clik/srv/manipulator_mode.srv" ""
)

get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/traj_out_msg.srv" NAME_WE)
add_custom_target(_clik_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "clik" "/home/ahao/catkin_ws/src/clik/srv/traj_out_msg.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(clik
  "/home/ahao/catkin_ws/src/clik/msg/position_pub.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clik
)
_generate_msg_cpp(clik
  "/home/ahao/catkin_ws/src/clik/msg/action.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clik
)

### Generating Services
_generate_srv_cpp(clik
  "/home/ahao/catkin_ws/src/clik/srv/traj_solver_msg.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clik
)
_generate_srv_cpp(clik
  "/home/ahao/catkin_ws/src/clik/srv/traj_out_msg.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clik
)
_generate_srv_cpp(clik
  "/home/ahao/catkin_ws/src/clik/srv/manipulator_mode.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clik
)

### Generating Module File
_generate_module_cpp(clik
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clik
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(clik_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(clik_generate_messages clik_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/traj_solver_msg.srv" NAME_WE)
add_dependencies(clik_generate_messages_cpp _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/msg/position_pub.msg" NAME_WE)
add_dependencies(clik_generate_messages_cpp _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/msg/action.msg" NAME_WE)
add_dependencies(clik_generate_messages_cpp _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/manipulator_mode.srv" NAME_WE)
add_dependencies(clik_generate_messages_cpp _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/traj_out_msg.srv" NAME_WE)
add_dependencies(clik_generate_messages_cpp _clik_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(clik_gencpp)
add_dependencies(clik_gencpp clik_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS clik_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(clik
  "/home/ahao/catkin_ws/src/clik/msg/position_pub.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/clik
)
_generate_msg_eus(clik
  "/home/ahao/catkin_ws/src/clik/msg/action.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/clik
)

### Generating Services
_generate_srv_eus(clik
  "/home/ahao/catkin_ws/src/clik/srv/traj_solver_msg.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/clik
)
_generate_srv_eus(clik
  "/home/ahao/catkin_ws/src/clik/srv/traj_out_msg.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/clik
)
_generate_srv_eus(clik
  "/home/ahao/catkin_ws/src/clik/srv/manipulator_mode.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/clik
)

### Generating Module File
_generate_module_eus(clik
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/clik
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(clik_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(clik_generate_messages clik_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/traj_solver_msg.srv" NAME_WE)
add_dependencies(clik_generate_messages_eus _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/msg/position_pub.msg" NAME_WE)
add_dependencies(clik_generate_messages_eus _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/msg/action.msg" NAME_WE)
add_dependencies(clik_generate_messages_eus _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/manipulator_mode.srv" NAME_WE)
add_dependencies(clik_generate_messages_eus _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/traj_out_msg.srv" NAME_WE)
add_dependencies(clik_generate_messages_eus _clik_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(clik_geneus)
add_dependencies(clik_geneus clik_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS clik_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(clik
  "/home/ahao/catkin_ws/src/clik/msg/position_pub.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clik
)
_generate_msg_lisp(clik
  "/home/ahao/catkin_ws/src/clik/msg/action.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clik
)

### Generating Services
_generate_srv_lisp(clik
  "/home/ahao/catkin_ws/src/clik/srv/traj_solver_msg.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clik
)
_generate_srv_lisp(clik
  "/home/ahao/catkin_ws/src/clik/srv/traj_out_msg.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clik
)
_generate_srv_lisp(clik
  "/home/ahao/catkin_ws/src/clik/srv/manipulator_mode.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clik
)

### Generating Module File
_generate_module_lisp(clik
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clik
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(clik_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(clik_generate_messages clik_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/traj_solver_msg.srv" NAME_WE)
add_dependencies(clik_generate_messages_lisp _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/msg/position_pub.msg" NAME_WE)
add_dependencies(clik_generate_messages_lisp _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/msg/action.msg" NAME_WE)
add_dependencies(clik_generate_messages_lisp _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/manipulator_mode.srv" NAME_WE)
add_dependencies(clik_generate_messages_lisp _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/traj_out_msg.srv" NAME_WE)
add_dependencies(clik_generate_messages_lisp _clik_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(clik_genlisp)
add_dependencies(clik_genlisp clik_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS clik_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(clik
  "/home/ahao/catkin_ws/src/clik/msg/position_pub.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/clik
)
_generate_msg_nodejs(clik
  "/home/ahao/catkin_ws/src/clik/msg/action.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/clik
)

### Generating Services
_generate_srv_nodejs(clik
  "/home/ahao/catkin_ws/src/clik/srv/traj_solver_msg.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/clik
)
_generate_srv_nodejs(clik
  "/home/ahao/catkin_ws/src/clik/srv/traj_out_msg.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/clik
)
_generate_srv_nodejs(clik
  "/home/ahao/catkin_ws/src/clik/srv/manipulator_mode.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/clik
)

### Generating Module File
_generate_module_nodejs(clik
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/clik
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(clik_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(clik_generate_messages clik_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/traj_solver_msg.srv" NAME_WE)
add_dependencies(clik_generate_messages_nodejs _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/msg/position_pub.msg" NAME_WE)
add_dependencies(clik_generate_messages_nodejs _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/msg/action.msg" NAME_WE)
add_dependencies(clik_generate_messages_nodejs _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/manipulator_mode.srv" NAME_WE)
add_dependencies(clik_generate_messages_nodejs _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/traj_out_msg.srv" NAME_WE)
add_dependencies(clik_generate_messages_nodejs _clik_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(clik_gennodejs)
add_dependencies(clik_gennodejs clik_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS clik_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(clik
  "/home/ahao/catkin_ws/src/clik/msg/position_pub.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clik
)
_generate_msg_py(clik
  "/home/ahao/catkin_ws/src/clik/msg/action.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clik
)

### Generating Services
_generate_srv_py(clik
  "/home/ahao/catkin_ws/src/clik/srv/traj_solver_msg.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clik
)
_generate_srv_py(clik
  "/home/ahao/catkin_ws/src/clik/srv/traj_out_msg.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clik
)
_generate_srv_py(clik
  "/home/ahao/catkin_ws/src/clik/srv/manipulator_mode.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clik
)

### Generating Module File
_generate_module_py(clik
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clik
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(clik_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(clik_generate_messages clik_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/traj_solver_msg.srv" NAME_WE)
add_dependencies(clik_generate_messages_py _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/msg/position_pub.msg" NAME_WE)
add_dependencies(clik_generate_messages_py _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/msg/action.msg" NAME_WE)
add_dependencies(clik_generate_messages_py _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/manipulator_mode.srv" NAME_WE)
add_dependencies(clik_generate_messages_py _clik_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ahao/catkin_ws/src/clik/srv/traj_out_msg.srv" NAME_WE)
add_dependencies(clik_generate_messages_py _clik_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(clik_genpy)
add_dependencies(clik_genpy clik_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS clik_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clik)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clik
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(clik_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/clik)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/clik
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(clik_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clik)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clik
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(clik_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/clik)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/clik
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(clik_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clik)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clik\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clik
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(clik_generate_messages_py std_msgs_generate_messages_py)
endif()
