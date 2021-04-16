#include "intro.h"


using namespace godot;


void Intro::_register_methods()
{
	register_method((char*)"_ready", &Intro::_ready);
	register_method((char*)"_on_button_pressed", &Intro::_on_button_pressed);
}

void Intro::_init(){}
Intro::Intro(){}
Intro::~Intro(){}








void Intro::_ready()
{
	for(int i=0; i<get_child_count(); i++)
	{
		Array body{};
		body.push_back(get_child(i));
		get_child(i)->connect("pressed", this, "_on_button_pressed", body);
	}
}




void Intro::_on_button_pressed(Variant body)
{
	Control* body_control= Object::cast_to<Control>(body);
	if(body_control->get_name()[6]=='0')
	{
		get_tree()->get_current_scene()->queue_free();
		ResourceLoader* reLo = ResourceLoader::get_singleton();
		Ref<PackedScene> res = reLo->load("res://scense/Node2D.tscn");
		Node* next_scene = res->instance();
		
		get_tree()->get_root()->add_child(next_scene);
		get_tree()->set_current_scene(next_scene);
	}if(body_control->get_name()[6]=='1')
	{
		get_tree()->get_current_scene()->queue_free();
		ResourceLoader* reLo = ResourceLoader::get_singleton();
		Ref<PackedScene> res = reLo->load("res://game 2/borders.tscn");
		Node* next_scene = res->instance();
		
		get_tree()->get_root()->add_child(next_scene);
		get_tree()->set_current_scene(next_scene);
	}if(body_control->get_name()[6]=='2')
	{
		get_tree()->get_current_scene()->queue_free();
		ResourceLoader* reLo = ResourceLoader::get_singleton();
		Ref<PackedScene> res = reLo->load("res://game 3/main scene.tscn");
		Node* next_scene = res->instance();
		
		get_tree()->get_root()->add_child(next_scene);
		get_tree()->set_current_scene(next_scene);
	}
		if(body_control->get_name()[6]=='3')
	{
		get_tree()->get_current_scene()->queue_free();
		ResourceLoader* reLo = ResourceLoader::get_singleton();
		Ref<PackedScene> res = reLo->load("res://game 4/world.tscn");
		Node* next_scene = res->instance();
		
		get_tree()->get_root()->add_child(next_scene);
		get_tree()->set_current_scene(next_scene);
	}if(body_control->get_name()[6]=='4')
	{
		get_tree()->get_current_scene()->queue_free();
		ResourceLoader* reLo = ResourceLoader::get_singleton();
		Ref<PackedScene> res = reLo->load("res://game 5/ping_pong.tscn");
		Node* next_scene = res->instance();
		
		get_tree()->get_root()->add_child(next_scene);
		get_tree()->set_current_scene(next_scene);
	}
}
