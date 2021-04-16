#source code
src_o_code= o_files/test.o o_files/Root.o o_files/road.o o_files/player.o o_files/GodotLibrary.o o_files/border_area2d.o o_files/game_1_border.o o_files/game_1_xo.o o_files/main.o o_files/intro.o o_files/world.o o_files/ping_pong.o



src_code= src/*.cpp src/**/*.cpp







#linux stuff
#include
include_linux=-I/home/ain/projects/godot_cpp_projects/godot_cpp_linux_debug/include/  -I/home/ain/projects/godot_cpp_projects/godot_cpp_linux_debug/include/gen/ -I/home/ain/projects/godot_cpp_projects/godot_cpp_linux_debug/include/core/ -I/home/ain/projects/godot_cpp_projects/godot_cpp_linux_debug/godot-headers/ -Iinclude/ -Iinclude/game_1/ -Iinclude/game_2/ -Iinclude/game_3/ -Iinclude/game_4/

#libgodot-cpp
#debug
linux_godot_lib_path_debug=-L/home/ain/projects/godot_cpp_projects/godot_cpp_linux_debug/lib/
linux_godot_lib_debug=-lgodot-cpp.linux.debug.64

#release
linux_godot_lib_path_release=-L/home/ain/projects/godot_cpp_projects/godot_cpp_linux_release/lib/
linux_godot_lib_release=-lgodot-cpp.linux.release.64










#windows stuff
#include
include_windows=-I/home/ain/projects/godot_cpp_projects/godot_cpp_windows_debug/godot-headers/ -I/home/ain/projects/godot_cpp_projects/godot_cpp_windows_debug/include/ -I/home/ain/projects/godot_cpp_projects/godot_cpp_windows_debug/include/gen/ -I/home/ain/projects/godot_cpp_projects/godot_cpp_windows_debug/include/core/ -Iinclude/ -Iinclude/game_1/ -Iinclude/game_2/ -Iinclude/game_3/ -Iinclude/game_4/

#libgodot-cpp
#debug
windows_godot_lib_path_debug=-L/home/ain/projects/godot_cpp_projects/godot_cpp_windows_debug/lib/
windows_godot_lib_debug=-lgodot-cpp.windows.debug.64

#release
windows_godot_lib_path_release=-L/home/ain/projects/godot_cpp_projects/godot_cpp_windows_release/lib/
windows_godot_lib_release=-lgodot-cpp.windows.release.64










#compile all

release: linux_release windows_release

debug: linux_debug windows_debug


#
#note the text bellow works with only executables note shared libs
#
#PGO

#GCC has Profile-Guided Optimisations features. There isn't a lot of precise GCC documentation about it, but nevertheless getting it to run is quite #straightforward.

#first compile your program with -fprofile-generate.
#let the program run (the execution time will be significantly slower as the code is also generating profile information into .gcda files).
#recompile the program with -fprofile-use. If your application is multi-threaded also add the -fprofile-correction flag.
#PGO with GCC can give amazing results and really significantly boost performance (I've seen a 15-20% speed increase on one of the projects I was #recently working on). Obviously the issue here is to have some data that is sufficiently representative of your application's execution, which is #not always available or easy to obtain.
#



#compile for linux
linux_debug: $(src_o_code)
	g++ -std=c++14 -g3 -Wall -m64 -march=x86-64    -fPIC -shared -o /home/ain/projects/godot_cpp_projects/godot_learning_cpp/code/lib/lib_godot_debug.so -shared -g3   $(src_o_code)  $(include_linux) $(linux_godot_lib_path_debug) $(linux_godot_lib_debug)

linux_release: 
	g++ -std=c++14  -Wall -m64 -march=x86-64   -fPIC -shared -O3 -o /home/ain/projects/godot_cpp_projects/godot_learning_cpp/code/lib/lib_godot_release.so -shared    -O3 $(src_code)  $(include_linux) $(linux_godot_lib_path_release) $(linux_godot_lib_release)



















#compile for windows
windows_debug: 
	x86_64-w64-mingw32-g++ -std=c++14 -g3 -Wall -m64 -march=x86-64    -static-libstdc++ -static-libgcc  -fPIC -shared -o /home/ain/projects/godot_cpp_projects/godot_learning_cpp/code/lib/lib_godot_debug.dll   -shared -g3   $(src_code) $(include_windows)  $(windows_godot_lib_path_debug) $(windows_godot_lib_debug)

windows_release: 
	x86_64-w64-mingw32-g++ -std=c++14  -Wall -m64 -march=x86-64   -static-libstdc++ -static-libgcc  -fPIC -shared -O3 -o /home/ain/projects/godot_cpp_projects/godot_learning_cpp/code/lib/lib_godot_release.dll   -shared   -O3  $(src_code) $(include_windows)  $(windows_godot_lib_path_release) $(windows_godot_lib_release)



















#compile o files

o_files/test.o: src/test.cpp
	g++ -std=c++14 -Wall -m64 -march=x86-64 -fPIC -shared -g3    -o o_files/test.o -shared -g3 -c src/test.cpp $(include_linux) $(linux_godot_lib_path_debug) $(linux_godot_lib_debug)

o_files/Root.o: src/Root.cpp
	g++ -std=c++14 -Wall -m64 -march=x86-64 -fPIC -shared -g3   -o o_files/Root.o -shared -g3 -c src/Root.cpp $(include_linux) $(linux_godot_lib_path_debug) $(linux_godot_lib_debug)

o_files/road.o: src/road.cpp
	g++ -std=c++14 -Wall -m64 -march=x86-64 -fPIC -shared -g3   -o o_files/road.o -shared -g3 -c src/road.cpp $(include_linux) $(linux_godot_lib_path_debug) $(linux_godot_lib_debug)

o_files/player.o: src/player.cpp
	g++ -std=c++14 -Wall -m64 -march=x86-64 -fPIC -shared -g3   -o o_files/player.o -shared -g3 -c src/player.cpp  $(include_linux) $(linux_godot_lib_path_debug) $(linux_godot_lib_debug)

o_files/GodotLibrary.o: src/GodotLibrary.cpp
	g++ -std=c++14 -Wall -m64 -march=x86-64 -fPIC -shared -g3   -o o_files/GodotLibrary.o -shared -g3 -c src/GodotLibrary.cpp  $(include_linux) $(linux_godot_lib_path_debug) $(linux_godot_lib_debug)

o_files/border_area2d.o: src/border_area2d.cpp
	g++ -std=c++14 -Wall -m64 -march=x86-64 -fPIC -shared -g3   -o o_files/border_area2d.o -shared -g3 -c src/border_area2d.cpp  $(include_linux) $(linux_godot_lib_path_debug) $(linux_godot_lib_debug)

o_files/game_1_border.o: src/game_1/game_1_border.cpp
	g++ -std=c++14 -Wall -m64 -march=x86-64 -fPIC -shared -g3   -o o_files/game_1_border.o -shared -g3 -c src/game_1/game_1_border.cpp  $(include_linux) $(linux_godot_lib_path_debug) $(linux_godot_lib_debug)

o_files/game_1_xo.o: src/game_1/game_1_xo.cpp
	g++ -std=c++14 -Wall -m64 -march=x86-64 -fPIC -shared -g3   -o o_files/game_1_xo.o -shared -g3 -c src/game_1/game_1_xo.cpp  $(include_linux) $(linux_godot_lib_path_debug) $(linux_godot_lib_debug)

o_files/main.o: src/game_2/main.cpp
	g++ -std=c++14 -Wall -m64 -march=x86-64 -fPIC -shared -g3   -o o_files/main.o -shared -g3 -c src/game_2/main.cpp  $(include_linux) $(linux_godot_lib_path_debug) $(linux_godot_lib_debug)

o_files/intro.o: src/intro.cpp
	g++ -std=c++14 -Wall -m64 -march=x86-64 -fPIC -shared -g3   -o o_files/intro.o -shared -g3 -c src/intro.cpp  $(include_linux) $(linux_godot_lib_path_debug) $(linux_godot_lib_debug)

o_files/world.o: src/game_3/world.cpp
	g++ -std=c++14 -Wall -m64 -march=x86-64 -fPIC -shared -g3   -o o_files/world.o -shared -g3 -c src/game_3/world.cpp  $(include_linux) $(linux_godot_lib_path_debug) $(linux_godot_lib_debug)

o_files/ping_pong.o: src/game_4/ping_pong.cpp
	g++ -std=c++14 -Wall -m64 -march=x86-64 -fPIC -shared -g3   -o o_files/ping_pong.o -shared -g3 -c src/game_4/ping_pong.cpp  $(include_linux) $(linux_godot_lib_path_debug) $(linux_godot_lib_debug)
























