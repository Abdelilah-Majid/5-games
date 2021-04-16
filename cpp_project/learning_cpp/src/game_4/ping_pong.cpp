#include <ping_pong.h>




using namespace godot;



void Ping_pong::_register_methods()
{
	register_method("_ready", &Ping_pong::_ready);
	register_method("_physics_process", &Ping_pong::_physics_process);
}
void Ping_pong::_init(){}
Ping_pong::Ping_pong(){}
Ping_pong::~Ping_pong(){}




void Ping_pong::_ready()
{
	ball = Object::cast_to<KinematicBody2D>(get_node("ball"));
	border_left = Object::cast_to<StaticBody2D>(get_node("border_left"));
	border_right = Object::cast_to<StaticBody2D>(get_node("border_right"));
}





void Ping_pong::_physics_process()
{
	if(I->is_action_just_released("ui_accept") && !is_game_started)
	{
		is_game_started = true;
	}
	
	if(is_game_started)
	{
		move_ball();
		move_borders();
	}
	
}




void Ping_pong::move_ball()
{
	
	
	ball->move_and_slide(ball_velocity, Vector2::UP);
	
	
	if(ball->get_slide_count())
	{
		if(ball->is_on_ceiling() || ball->is_on_floor())
		{
			ball_velocity.y = ball_velocity.y * -1;
		}
		if(ball->is_on_wall())
		{
			ball_velocity.x = ball_velocity.x * -1;
		}
	}
}




void Ping_pong::move_borders()
{
	if(I->is_action_pressed("ui_up"))
	{
		border_right->set_global_position( Vector2(0, border_right->get_global_position().y-3) );
	}
	if(I->is_action_pressed("ui_down"))
	{
		border_right->set_global_position( Vector2(0, border_right->get_global_position().y+3) );
	}
	
	if(I->is_action_pressed("i"))
	{
		border_left->set_global_position( Vector2(0, border_left->get_global_position().y-3) );
	}
	if(I->is_action_pressed("k"))
	{
		border_left->set_global_position( Vector2(0, border_left->get_global_position().y+3) );
	}
}
