# CMake generated Testfile for 
# Source directory: /home/ahao/catkin_ws/src/DecompROS/DecompUtil
# Build directory: /home/ahao/catkin_ws/build/decomp_util
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_seed_decomp "test_seed_decomp")
add_test(test_line_segment "test_line_segment" "/home/ahao/catkin_ws/src/DecompROS/DecompUtil/data/obstacles.txt")
add_test(test_ellipsoid_decomp "test_ellipsoid_decomp" "/home/ahao/catkin_ws/src/DecompROS/DecompUtil/data/obstacles.txt")
add_test(test_iterative_decomp "test_iterative_decomp" "/home/ahao/catkin_ws/src/DecompROS/DecompUtil/data/obstacles.txt")
