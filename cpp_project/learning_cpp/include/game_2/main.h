#ifndef GAME_2_MAIN_H
#define GAME_2_MAIN_H


#include <Godot.hpp>
#include <Node2D.hpp>
#include <Viewport.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <Ref.hpp>
#include <StaticBody2D.hpp>
#include <SceneTree.hpp>
#include <vector>
#include <KinematicBody2D.hpp>
#include <Input.hpp>
#include <KinematicCollision2D.hpp>
#include <WeakRef.hpp>

namespace godot
{
	class Main: public Node2D
	{
	private:
		GODOT_CLASS(Main, Node2D)
	public:
		static void _register_methods();
		void _init();
		Main();
		~Main();
		
	public:
		void _ready();
		void _physics_process();
		
	public:
		void handel_window_size_changed();
		void get_window_size_and_draw_blocks();
		void calc_and_draw_platform_and_ball();
		void handel_window_size_changed_for_platform_and_ball();
		void calc_ball_velocity_bouncing();
		void handl_platform_moving_input();
		void calc_ball_bumping_with_platform_bounce(Variant body);
		
	public:
		Vector2 windows_size;
		
		StaticBody2D* res_static_body2D;
		
		std::vector<StaticBody2D*> blocks_arr;
		
		std::vector<Vector2> blocks_positions_arr;
		std::vector<Vector2> blocks_global_position_arr;
		
		Vector2 the_right_windows_size;
		
		KinematicBody2D* platform;
		
		Vector2 platform_pos;
		
		Vector2 platform_pos_to_window_size_ratio;
		
		KinematicBody2D* ball;
		
		Vector2 ball_pos;
		
		Vector2 ball_pos_to_window_size_ratio;
		
		bool block__physics_process=false;
		
		Input* I;
		
		bool is_first_shot_has_been_made=false;
		
		Vector2 ball_velocity = Vector2(0, 0);
		
		
		
		Vector2 old_ball_pos;
		Vector2 new_ball_pos;
		bool block_old_pos_calc=false;
		bool block_handel_window_size_changed_for_platform_and_ball=false;
		int max_j=0;
		int max_y=0; 
		
		
		
		std::vector<Node2D*> walls_arr;
		std::vector<Vector2> walls_pos_to_window_size_ratio = {Vector2(), Vector2(), Vector2()};
		
	};
}



















#endif
