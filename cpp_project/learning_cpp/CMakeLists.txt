cmake_minimum_required(VERSION 3.0)

project(learning_cpp)



include_directories(/home/ain/projects/godot_cpp_projects/godot_cpp_linux_debug/include include include/game_1 include/game_2 include/game_3 include/game_4  
/home/ain/projects/godot_cpp_projects/godot_cpp_linux_debug/include/gen /home/ain/projects/godot_cpp_projects/godot_cpp_linux_debug/include/core 
/home/ain/projects/godot_cpp_projects/godot_cpp_linux_debug/godot-headers)

add_library(learning_cpp SHARED  src/border_area2d.cpp src/GodotLibrary.cpp src/player.cpp src/road.cpp src/Root.cpp src/test.cpp src/game_1/game_1_border.cpp)

install(TARGETS learning_cpp RUNTIME DESTINATION bin)
 
 
