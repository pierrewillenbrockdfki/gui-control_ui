# CMakeLists.txt has to be located in the project folder and cmake has to be
# executed from 'project/build' with 'cmake ../'.
cmake_minimum_required(VERSION 3.1)
project(control_ui VERSION 0.1)
find_package(Rock)
rock_init()
rock_feature(NOCURDIR)
 
include(RockRuby)
rock_standard_layout()

install(PROGRAMS bin/rock-control_bot
    DESTINATION bin)

install(PROGRAMS bin/bldc_control_joints_gui bin/bldc_control_joints_gui_new
    DESTINATION bin)
