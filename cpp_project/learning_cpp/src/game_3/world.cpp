#include "world.h"


using namespace godot;


void World::_register_methods()
{
	register_method((char*)"_ready", &World::_ready);
	register_method((char*)"_physics_process", &World::_physics_process);
	
	register_method((char*)"_on_platform_exit_viewport", &World::_on_platform_exit_viewport);
}

void World::_init(){}
World::World(){}
World::~World(){}



void World::_ready()
{
	platforms_node2D = Object::cast_to<Node2D>(get_node("platforms"));
	
	
	
	
	get_viewport_and_draw_platforms();
	
}

void World::_physics_process()
{
	
	handl_player_movment();
	
	if(I->is_action_just_pressed("ui_up") && !is_game_beggin)
	{
		is_game_beggin= true;
	}
	if(is_game_beggin)
	{
		move_platforms_prent();
	}
	
	if(platforms_node2D->get_global_position().y - platforms_parent_last_pos.y == 100)
	{
		long unsigned int i = paltforms_arr.size() + 1;
		while(paltforms_arr.size() < i)
		{
			
			int x = (paltforms_arr.back()->get_global_position().x - ((64 * 4) *6.5)) + (std::rand() % 
			(int)(paltforms_arr.back()->get_global_position().x + ((64 * 
			4) *6.5))) ;
			
			if(x < 64*2 || x > windows_size.x-64*2)
			{
				continue;
			}
		
		paltforms_arr.push_back( instance_platforms(Vector2(x, paltforms_arr.back()->get_global_position().y - 100)) );
		
		}
		
		
		
	
	}
}




void World::get_viewport_and_draw_platforms()
{
	the_right_windows_size = get_viewport()->get_size();
	windows_size = get_viewport()->get_size();
	
	
	while( ( (int) windows_size.y % (int)floor(windows_size.y/100)*100 ) != 0)
	{
		std::cout<<"while window_size"<<std::endl;
		windows_size.y--;
	}
	
	
	paltforms_arr.push_back(instance_platforms());
	
	while(paltforms_arr.size()<windows_size.y/100 + 1)
	{
		
		
		srand((unsigned int)time(NULL));
		
// 		int x = (paltforms_arr[paltforms_arr.size()-1]->get_global_position().x - ((64 * 4) *6.5)) + (std::rand() % 
// (int)(paltforms_arr[paltforms_arr.size()-1]->get_global_position().x + ((64 * 
//   4) *6.5))) ;
 
		
		RandomNumberGenerator rand;
		rand.randomize();
		float x = rand.randf_range(paltforms_arr[paltforms_arr.size()-1]->get_global_position().x - ((64 * 4) *2), 
(paltforms_arr[paltforms_arr.size()-1]->get_global_position().x + ((64 * 
4) *2)));
		
		std::cout<<x<<std::endl;
		
		
		if(x < 64*2 || x > the_right_windows_size.x-64*2)
		{
			continue;
		}
// 		
// 		std::cout<<"while_loop: "<<windows_size.y/100<<std::endl;
		int last_platform_y_pos =  paltforms_arr.back()->get_position().y;
		paltforms_arr.push_back( instance_platforms(Vector2(x, last_platform_y_pos - 100)) );
// 		
	}
	
	
	current_platform_pos = Vector2(0 + (rand() % (int)the_right_windows_size.x),0);
}



StaticBody2D* World::instance_platforms()
{

	ResourceLoader* reLo = ResourceLoader::get_singleton();
	Ref<PackedScene> res = reLo->load("res://game 4/platform.tscn");
	Node* res_node = res->instance();
	StaticBody2D* res_static_body2D = Object::cast_to<StaticBody2D>(res_node);
	platforms_node2D->add_child(res_static_body2D);
	res_static_body2D->set_global_position(Vector2(0 + (rand() % (int)the_right_windows_size.x),the_right_windows_size.y-12.8/2));
	
	std::cout<<res_static_body2D->get_global_position().x<<std::endl;
	
	res = reLo->load("res://game 4/player.tscn");
	res_node = res->instance();
	player= Object::cast_to<KinematicBody2D>(res_node);
	platforms_node2D->get_node("player_layer")->add_child(player);
	
	
	
	player->set_global_position(Vector2( (int)res_static_body2D->get_global_position().x ,(int) res_static_body2D->get_global_position().y - 64/2 - 64 * 0.2 
));
	
	
	platforms_parent_last_pos=platforms_node2D->get_global_position();
	
	Array params{};
	params.push_back(res_static_body2D);
	res_static_body2D->get_node("VisibilityNotifier2D")->connect("viewport_exited", this, "_on_platform_exit_viewport", params);
	
	
	
	return res_static_body2D;
}



StaticBody2D* World::instance_platforms(Vector2 pos)
{
	ResourceLoader* reLo = ResourceLoader::get_singleton();
	Ref<PackedScene> res = reLo->load("res://game 4/platform.tscn");
	Node* res_node = res->instance();
	StaticBody2D* res_static_body2D = Object::cast_to<StaticBody2D>(res_node);
	platforms_node2D->add_child(res_static_body2D);
	res_static_body2D->set_global_position(pos);
	platforms_parent_last_pos=platforms_node2D->get_global_position();
	
	Array params{};
	params.push_back(res_static_body2D);
	res_static_body2D->get_node("VisibilityNotifier2D")->connect("viewport_exited", this, "_on_platform_exit_viewport", params);
	
	return res_static_body2D;
}







void World::_on_platform_exit_viewport(Variant vp, Variant platform)
{
	for(long unsigned int i=0; i<paltforms_arr.size(); i++)
	{
		if(paltforms_arr[i]==nullptr)
		{
			continue;
		}
		
		paltforms_arr[i]=nullptr;
		break;
	}
	
	Object::cast_to<StaticBody2D>(platform.operator Object*())->queue_free();
}








void World::move_platforms_prent()
{
	platforms_node2D->set_global_position(Vector2(platforms_node2D->get_global_position().x, platforms_node2D->get_global_position().y+1));;
}







void World::handl_player_movment()
{
	player_vilocity = player->move_and_slide(player_vilocity);
	
	if(I->is_action_just_pressed("ui_up"))
	{
		player_vilocity.y-=450;
	}
	
	player_vilocity.x= ( I->get_action_strength("ui_right") - I->get_action_strength("ui_left") ) * 200;
	
	player_vilocity.y+=10;
}
