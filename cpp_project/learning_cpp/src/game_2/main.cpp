#include "main.h"


using namespace godot;


void Main::_register_methods()
{
	
	register_method((char*)"_ready", &Main::_ready);
	register_method((char*)"_physics_process", &Main::_physics_process);
	register_method((char*)"handel_window_size_changed", &Main::handel_window_size_changed);
	register_method((char*)"handel_window_size_changed_for_platform_and_ball", &Main::handel_window_size_changed_for_platform_and_ball);
	register_method((char*)"calc_ball_bumping_with_platform_bounce", &Main::calc_ball_bumping_with_platform_bounce);
	
	
}
void Main::_init(){}
Main::Main(){}
Main::~Main(){}


void Main::_ready()
{
	
	get_tree()->get_root()->connect("size_changed", this, "handel_window_size_changed");
	
	
	
	for(int i=0; i<3; i++)
	{
		
		walls_arr.push_back(Object::cast_to<Node2D>(get_child(i)));
	}
	
	get_window_size_and_draw_blocks();
	calc_and_draw_platform_and_ball();
	
	platform=Object::cast_to<KinematicBody2D>(get_node("platform"));
	ball=Object::cast_to<KinematicBody2D>(get_node("ball"));
	
	I = Input::get_singleton();
	
	
	get_node("./ball/Area2D")->connect("body_entered", this, "calc_ball_bumping_with_platform_bounce");
	
	
}

void Main::_physics_process()
{
	// NOTE:: keep the code bellow at the end of this function
	if(block__physics_process)
	{
		return;
	}
	
	
	calc_ball_velocity_bouncing();
	
	
	
	handl_platform_moving_input();
	
	
	if(I->is_action_just_pressed("ui_accept") && !is_first_shot_has_been_made)
	{
		
		ball_velocity=Vector2(-350 + (std::rand() % (350 - - 350 + 1)), -350);
		is_first_shot_has_been_made=true;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	platform_pos=platform->get_global_position();
	platform_pos_to_window_size_ratio.x = the_right_windows_size.x/platform_pos.x;
	platform_pos_to_window_size_ratio.y = the_right_windows_size.y/platform_pos.y;
	
	ball_pos=ball->get_global_position();
	ball_pos_to_window_size_ratio.x = the_right_windows_size.x/ball_pos.x;
	ball_pos_to_window_size_ratio.y = the_right_windows_size.y/ball_pos.y;
	
	for(int i=0; i<3; i++)
	{
		
		walls_pos_to_window_size_ratio[i].x = the_right_windows_size.x/walls_arr[i]->get_global_position().x;
		walls_pos_to_window_size_ratio[i].y = the_right_windows_size.y/walls_arr[i]->get_global_position().y;
		
	}
}



void Main::get_window_size_and_draw_blocks()
{
	
	windows_size = get_viewport()->get_size();
	the_right_windows_size = get_viewport()->get_size();
	
	
	
	while((int)windows_size.x%128!=0)
	{
		windows_size.x--;
	}
	for(float i=0.0f; i < ((int)windows_size.y/3)/12.8; i++)
	{
		for(int j=0; j < (int)windows_size.x/128; j++)
		{
			ResourceLoader* reLo = ResourceLoader::get_singleton();
			Ref<PackedScene> res = reLo->load("res://game 3/block.tscn");
			Node* res_node = res->instance();
			res_static_body2D = Object::cast_to<StaticBody2D>(res_node);
			add_child(res_static_body2D);
			res_static_body2D->set_position(Vector2(j*128+64+(((int)the_right_windows_size.x%128)/2),i*12.8+(12.8/2)+2*i));
			
			blocks_arr.push_back(res_static_body2D);
			blocks_positions_arr.push_back(Vector2(j, i));
			blocks_global_position_arr.push_back(res_static_body2D->get_global_position());
			
		}
	}
	
	
}


void Main::calc_and_draw_platform_and_ball()
{
	ResourceLoader* reLo = ResourceLoader::get_singleton();
	Ref<PackedScene> res = reLo->load("res://game 3/platform.tscn");
	Node* res_node = res->instance();
	KinematicBody2D* res_static_kinimatic_body2D = Object::cast_to<KinematicBody2D>(res_node);
	add_child(res_static_kinimatic_body2D);
	res_static_kinimatic_body2D->set_position(Vector2(the_right_windows_size.x/2,the_right_windows_size.y/1.1));
	
	res = reLo->load("res://game 3/ball.tscn");
	res_node = res->instance();
	KinematicBody2D* res_static_rigid_body2D = Object::cast_to<KinematicBody2D>(res_node);
	add_child(res_static_rigid_body2D);
	res_static_rigid_body2D->set_position(Vector2(the_right_windows_size.x/2,the_right_windows_size.y/1.1-19.2/2-25.6/2-40));
}


void Main::handel_window_size_changed()
{
	block__physics_process=true;
	block_handel_window_size_changed_for_platform_and_ball=true;
	the_right_windows_size = get_viewport()->get_size();
	
	for(int i=0; i<(int)blocks_positions_arr.size(); i++)
	{
		if((int)blocks_positions_arr[i].x<max_j)
		{
			break;
		}if((int)blocks_positions_arr[i].y<max_y)
		{
			break;
		}
		max_j=(int)blocks_positions_arr[i].x;
		max_y=(int)blocks_positions_arr[i].y;
	}
	for(int i=0; i < (int)blocks_arr.size(); i++)
	{
		
		if(blocks_arr[i]==nullptr)
		{
			continue;
		}
	
		std::cout<<blocks_positions_arr[i].x<<" "<<blocks_positions_arr[i].y<<std::endl;
		std::cout<<blocks_positions_arr[i].x*128+((the_right_windows_size.x-max_j*128)/2)<<std::endl;
		

blocks_arr[i]->set_position(Vector2(blocks_positions_arr[i].x*128+((the_right_windows_size.x-max_j*128)/2),blocks_positions_arr[i].y*12.8+(12.8/2)+2*
blocks_positions_arr[i].y));
		

	}
	block_handel_window_size_changed_for_platform_and_ball=false;
	handel_window_size_changed_for_platform_and_ball();
	
	block__physics_process=false;
}




void Main::handel_window_size_changed_for_platform_and_ball()
{
	block__physics_process=true;
	if(block_handel_window_size_changed_for_platform_and_ball)
	{
		return;
	}
	the_right_windows_size = get_viewport()->get_size();
	
	platform->set_global_position(Vector2(the_right_windows_size.x/platform_pos_to_window_size_ratio.x,the_right_windows_size.y/platform_pos_to_window_size_ratio.y));
	
	
	ball->set_global_position(Vector2(the_right_windows_size.x/ball_pos_to_window_size_ratio.x,the_right_windows_size.y/ball_pos_to_window_size_ratio.y));
	
	for(int i=0; i<3; i++)
	{
		
		walls_arr[i]->set_global_position(Vector2(the_right_windows_size.x/walls_pos_to_window_size_ratio[i].x,the_right_windows_size.y/walls_pos_to_window_size_ratio[i].y));
	}
	
	block__physics_process=false;
}





void Main::calc_ball_velocity_bouncing()
{
	if(block_old_pos_calc)
	{
		return;
	}
	ball->move_and_slide(ball_velocity, Vector2::UP);
	
	if(ball->get_collision_layer_bit(0))
	{
		// NOTE:: USE IS_ON_FLOOR AND IS_ON_CIELING AND IS_ON_WALL
		if(ball->is_on_floor())
		{
			ball_velocity=Vector2(ball_velocity.x, ball_velocity.y*-1);
		}if(ball->is_on_ceiling())
		{
			ball_velocity=Vector2(ball_velocity.x, ball_velocity.y*-1);
		}if(ball->is_on_wall())
		{
			ball_velocity=Vector2(ball_velocity.x*-1, ball_velocity.y);
		}
		
		if(ball->get_collision_layer_bit(0)>0)
		{
			if(ball->get_slide_count()>0)
			{
				Node2D* collided_body = Object::cast_to<Node2D>(ball->get_slide_collision(0)->get_collider());
					std::string body_name;
					for(int i=0; i<4; i++)
					{
						body_name+=collided_body->get_name()[i];
					}
					
					if(body_name!="@blo")
					{
						return;
					}
				
				for(int i=0; i<(int)blocks_arr.size(); i++)
				{
					if(blocks_global_position_arr[i]==collided_body->get_global_position())
					{
						blocks_arr[i]=nullptr;
					}
					
				}
				
				collided_body->queue_free();
			}
		}
	}
}


void Main::handl_platform_moving_input()
{
	if(I->is_action_pressed("ui_left"))
	{
		platform->move_and_slide(Vector2(-300, 0));
	}
	if(I->is_action_pressed("ui_right"))
	{
		platform->move_and_slide(Vector2(300, 0));
	}
}



void Main::calc_ball_bumping_with_platform_bounce(Variant body)
{
	Node2D* body_node2D=Object::cast_to<Node2D>(body.operator Object*());
	if(body_node2D->get_name()!="platform")
	{
		return;
	}

ball_velocity=Vector2(350 * ((ball->get_global_position().x - platform->get_global_position().x) / ((64*3)/2) ), -350);
}
