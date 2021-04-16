#include "test.h"
#include "player.h"
#include "road.h" 
#include "border_area2d.h"
#include "game_1/game_1_border.h"
#include "game_1/game_1_xo.h"
#include "main.h"
#include "intro.h"
#include "world.h"
#include "ping_pong.h"

using namespace godot;

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options * o) {
	Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options * o) {
	Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle) {
	Godot::nativescript_init(handle);
	register_class<Player>();
	register_class<Node_test>();
	register_class<Road>();
	register_class<Border_area2d>();
	register_class<Game_1_border>();
	register_class<Main>();
	register_class<Intro>();
	register_class<World>();
	register_class<Ping_pong>();

}
 
