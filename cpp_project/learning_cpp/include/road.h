#ifndef ROAD_H
#define ROAD_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <binders.h>
#include<PackedScene.hpp>
#include <Ref.hpp>
#include <ResourceLoader.hpp>

namespace godot
{
	class Road: public Node2D
	{
	private:
		GODOT_CLASS(Road, Node2D)
	public:
		
		static void _register_methods();
		void _init();
		
		Road();
		~Road();
		
	public:
		void _physics_process();
		void _ready();
 		void _on_border_left_Area2D_body_entered(Variant body); 
	public:
		void how_to_instance_children();
		void get_first_child();
	public:
		
		Vector2 speed=Vector2(0,0);
		Node2D* first_child_node;
		Node2D* last_first_child_node;
		bool get_delet_and_add_child_node_if_lock;
		
	};
}














#endif
