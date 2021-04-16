#include "road.h"


using namespace godot;

void Road::_register_methods()
{
	register_method((char*) "_ready", &Road::_ready);
	register_method((char*) "_physics_process", &Road::_physics_process);
 	register_method((char*) "_on_border_left_Area2D_body_entered", &Road::_on_border_left_Area2D_body_entered);
	
}
void Road::_init(){}

Road::Road(){}
Road::~Road(){}


void Road::_ready(){
	
	Node2D node;
	std::cout<< typeid(node).name() <<std::endl;
	
	get_node("../Area2D")->connect("body_entered", this, "_on_border_left_Area2D_body_entered");
	first_child_node=get_child(0)->cast_to<Node2D>(get_child(0));
	
	
}

void Road::_physics_process()
{
	get_delet_and_add_child_node_if_lock=true;
	set_position(speed);
	speed.x-=0.8;
	
	if((first_child_node->get_global_position().x<-64 && get_delet_and_add_child_node_if_lock) ||       !get_delet_and_add_child_node_if_lock)
	{
		
		how_to_instance_children();
		last_first_child_node=first_child_node;
		get_delet_and_add_child_node_if_lock=false;
		last_first_child_node->queue_free();
		get_first_child();
	}
}


void Road::_on_border_left_Area2D_body_entered(Variant body)
{
	//this is how to convert a Variant to any desired node_type
	Node2D* body_node2D = Object::cast_to<Node2D>(body.operator Object*());
	
	
}

void Road:: how_to_instance_children()
{
	
	ResourceLoader* reLo = ResourceLoader::get_singleton();
	Ref<PackedScene> res = reLo->load("res://objects/road_pice.tscn");
	Node* res_node = res->instance();
	Node2D* res_node2D = Object::cast_to<Node2D>(res_node);
	add_child(res_node2D);
	res_node2D->set_global_position(Vector2(1024,0));
}

void Road::get_first_child()
{
	
	first_child_node=Object::cast_to<Node2D>(get_child(1));
}

