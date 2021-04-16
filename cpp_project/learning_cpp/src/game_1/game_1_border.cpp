#include "game_1/game_1_border.h"

using namespace godot;
 
void Game_1_border::_register_methods()
{
	register_method((char*)"_ready", &Game_1_border::_ready);
	register_method((char*)"_physics_process", &Game_1_border::_physics_process);
	register_method((char*)"_on_area_2D_input", &Game_1_border::_on_area_2D_input);
	register_method((char*)"_on_replay_button_pressed", &Game_1_border::_on_replay_button_pressed);
}

void Game_1_border::_init(){}
Game_1_border::Game_1_border(){}
Game_1_border::~Game_1_border(){}


void Game_1_border::_ready()
{
	// just to showcase
	std::cout<<state_arr[5]<<std::endl;
	std::cout<<state_arr[30]<<std::endl;
	for(int i=0; i < get_parent()->get_child_count(); i++)
	{
		if(i==0)
			continue;
		if(i>9)
			continue;
		
		Array name{};
		name.push_back(get_parent()->get_child(i));
		// name.push_back(String(get_parent()->get_child(i)->get_name()).alloc_c_string());
		
		get_parent()->get_child(i)->connect("input_event", this, "_on_area_2D_input", name);
		get_node("../Button")->connect("pressed", this, "_on_replay_button_pressed");
	}
}

void Game_1_border::_physics_process()
{
	
}

void Game_1_border::_on_area_2D_input(Variant viewport, Variant event, int shape_idx ,Variant node)
{
	if(!someone_wins)
{
		
	InputEvent* event_IE=Object::cast_to<InputEvent>(event);
	if(event_IE->is_pressed())
	{
		Node2D* node_2D = Object::cast_to<Node2D>(node.operator Object*());
		
		
		
		
		//instatcing x_o children
		if(String(node_2D->get_name()).alloc_c_string()[6]=='1')
		{
			if(state_arr[4]!=0)
				return;
			state_arr[4]=player_x_or_o;
			how_to_instance_children(Vector2(1,1));
		}if(String(node_2D->get_name()).alloc_c_string()[6]=='2')
		{
			if(state_arr[1]!=0)
				return;
			state_arr[1]=player_x_or_o;
			how_to_instance_children(Vector2(1,0));
		}if(String(node_2D->get_name()).alloc_c_string()[6]=='3')
		{
			if(state_arr[0]!=0)
				return;
			state_arr[0]=player_x_or_o;
			how_to_instance_children(Vector2(0,0));
		}if(String(node_2D->get_name()).alloc_c_string()[6]=='4')
		{
			if(state_arr[3]!=0)
				return;
			state_arr[3]=player_x_or_o;
			how_to_instance_children(Vector2(0,1));
		}if(String(node_2D->get_name()).alloc_c_string()[6]=='5')
		{
			if(state_arr[6]!=0)
				return;
			state_arr[6]=player_x_or_o;
			how_to_instance_children(Vector2(0,2));
		}if(String(node_2D->get_name()).alloc_c_string()[6]=='6')
		{
			if(state_arr[7]!=0)
				return;
			state_arr[7]=player_x_or_o;
			how_to_instance_children(Vector2(1,2));
		}if(String(node_2D->get_name()).alloc_c_string()[6]=='7')
		{
			if(state_arr[8]!=0)
				return;
			state_arr[8]=player_x_or_o;
			how_to_instance_children(Vector2(2,2));
		}if(String(node_2D->get_name()).alloc_c_string()[6]=='8')
		{
			if(state_arr[5]!=0)
				return;
			state_arr[5]=player_x_or_o;
			how_to_instance_children(Vector2(2,1));
		}if(String(node_2D->get_name()).alloc_c_string()[6]=='9')
		{
			if(state_arr[2]!=0)
				return;
			state_arr[2]=player_x_or_o;
			how_to_instance_children(Vector2(2,0));
		}
		
		//cheking for winers
 		for(int i=0; i<9; i++)
 		{
 			if((state_arr[i] == state_arr[i+1] && state_arr[i+1] == state_arr[i+2] && state_arr[i]!=0) && (i==0 || i==3 || i==6))
			{
 				winer_message=state_arr[i]==1?"red player wins":"blue player wins";
				someone_wins=true;
				
			}
 			if((state_arr[i] == state_arr[i+3] && state_arr[i+3] == state_arr[i+3+3] && state_arr[i]!=0) && (i==0 || i==1 || i==2))
			{
 				winer_message=state_arr[i]==1?"red player wins":"blue player wins";
				someone_wins=true;
			}
 			if(state_arr[i] == state_arr[i+4] && state_arr[i+4] == state_arr[i+4+4] && state_arr[i]!=0 && i==0)
			{
				winer_message=state_arr[i]==1?"red player wins":"blue player wins";
				someone_wins=true;
			}
 			if(state_arr[i] == state_arr[i+2] && state_arr[i+2] == state_arr[i+2+2] && state_arr[i]!=0 && i==2)
			{
 				winer_message=state_arr[i]==1?"red player wins":"blue player wins";
				someone_wins=true;
			}
 		
 		}
		
		if(player_x_or_o==1)
		{
			player_x_or_o=2;
		}else
		{
			player_x_or_o=1;
		}
		
	}
}else
{
	Object::cast_to<Label>(get_node("../Label"))->set_text(winer_message);;
}
}



void  Game_1_border::how_to_instance_children(Vector2 index)
{
	ResourceLoader* reLo = ResourceLoader::get_singleton();
	Ref<PackedScene> res = reLo->load("res://game 2/xo.tscn");
	Node* res_node = res->instance();
	Sprite* res_sprite = Object::cast_to<Sprite>(res_node);
	add_child(res_sprite);
	res_sprite->set_position(Vector2(82.005333333 * index.x + 41,82.005333333 * index.y + 41));
	if(player_x_or_o==1)
	{
		res_sprite->set_self_modulate(Color(1,0,0));
	}
	
}


void Game_1_border::_on_replay_button_pressed()
{
	get_tree()->get_current_scene()->queue_free();
	ResourceLoader* reLo = ResourceLoader::get_singleton();
	Ref<PackedScene> res = reLo->load("res://game 2/borders.tscn");
	Node* next_scene = res->instance();

	get_tree()->get_root()->add_child(next_scene);
	get_tree()->set_current_scene(next_scene);
}
