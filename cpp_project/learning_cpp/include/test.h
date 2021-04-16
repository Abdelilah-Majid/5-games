#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <Godot.hpp>
#include<Node2D.hpp>

namespace godot
{
	class Node_test: public Node2D
	{
		

private:
	GODOT_CLASS(Node_test, Node2D)
public:
static void _register_methods();

void _init();

Node_test();
~Node_test();


void _process(float delta);


	};
}




#endif
