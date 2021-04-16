#ifndef PING_PONG_H
#define PING_PONG_H


#include <Godot.hpp>
#include <Node2D.hpp>
#include <Input.hpp>
#include <KinematicBody2D.hpp>
#include <StaticBody2D.hpp>

namespace godot
{
	class Ping_pong: public Node2D 
	{
	private:
		GODOT_CLASS(Ping_pong, Node2D)
		
	public:
		static void _register_methods();
		void _init();
		Ping_pong();
		~Ping_pong();
		
	public:
		void _ready();
		void _physics_process();
		
		
	public:
		void move_ball();
		void move_borders();
		
		
	public:
		Input* I = Input::get_singleton();
		bool is_game_started = false;
		
		Vector2 ball_velocity = Vector2(300, 150);
		KinematicBody2D* ball;
		
		StaticBody2D* border_left;
		StaticBody2D* border_right;
		
	};

}





















#endif
