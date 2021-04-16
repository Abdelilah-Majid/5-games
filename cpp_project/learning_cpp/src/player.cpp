#include "player.h"
#include <Godot.hpp>

using namespace godot;


void Player::_register_methods()
{
	register_method((char*) "_physics_process", &Player::_physics_process);
	register_method((char*) "_ready", &Player::_ready);
}

void Player::_init(){}
Player::Player(){}
Player::~Player(){}

void Player::_ready()
{
	
	motion=Vector2(0,0);
}


void Player::_physics_process ( float delta )
{
	Player::update_motion();
	motion=move_and_slide(motion, Vector2().UP);
}


void Player::update_motion()
{
	

	Vector2 now_pos_y=get_global_position();
  	if((pos_y.y - now_pos_y.y) > (87.6237 - 1) && !is_double_jump)
  	{
		motion.y=-700;
		is_double_jump=true;
	}
	if(is_on_floor() && is_double_jump)
	{
		is_double_jump=false;
	}
	Input* i=Input::get_singleton();
	
	motion.y+=50;
	
	
	motion.x=(i->is_action_pressed("ui_right") - i->is_action_pressed("ui_left")) * speed;
	
	
	
	if(i->is_action_just_pressed("ui_up"))
	{
		pos_y=get_global_position();
		motion.y=-700;
	}
	
	if(i->is_action_just_released("ui_up") && !is_on_floor())
	{
		motion.y=0;
	}
}
