#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <Input.hpp>
#include <Node2D.hpp>
#include <Transform2D.hpp>

namespace godot
{
	class Player: public KinematicBody2D
	{
	private:
		GODOT_CLASS(Player,KinematicBody2D)
	public:
		static void _register_methods();
		void _init();
		Player();
		~Player();
		
	public:
		void _physics_process(float delta);
		void _ready();
	public:
		void update_motion();
		
		
	public:
		const float speed=300.0f;
		bool is_double_jump=false;
 		Vector2 pos_y; 
	private:
		Vector2 motion;
		
	};

}










#endif
