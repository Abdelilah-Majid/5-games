#ifndef WORLD_H
#define WORLD_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Viewport.hpp>
#include <StaticBody2D.hpp>
#include <vector>
#include <ResourceLoader.hpp>
#include <Ref.hpp>
#include <PackedScene.hpp>
#include <KinematicBody2D.hpp>
#include <Input.hpp>
#include <time.h>
#include <RandomNumberGenerator.hpp>

namespace godot 
{
	class World: public Node2D 
	{
	private:
		GODOT_CLASS(World, Node2D)
		
	public:
		static void _register_methods();
		void _init();
		World();
		~World();
		
	public:
		void _ready();
		void _physics_process();
		
	public:
		void get_viewport_and_draw_platforms();
		StaticBody2D* instance_platforms(Vector2 pos);
		StaticBody2D* instance_platforms();
		void _on_platform_exit_viewport(Variant vp, Variant platform);
		void move_platforms_prent();
		void handl_player_movment();
		
		
	public:
		Input* I = Input::get_singleton();
		Vector2 windows_size;
		Vector2 the_right_windows_size;
		Vector2 current_platform_pos;
		std::vector<StaticBody2D*> paltforms_arr;
		Vector2 platforms_parent_last_pos;
		
		Node2D* platforms_node2D;
		
		KinematicBody2D* player;
		Vector2 player_vilocity = Vector2(0, 0);
		
		bool is_game_beggin = false;
	};
}


















#endif
