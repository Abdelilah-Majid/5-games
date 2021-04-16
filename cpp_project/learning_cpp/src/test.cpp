#include <iostream>
#include "test.h"
#include <Godot.hpp>
#include<Node2D.hpp>

using namespace godot;

void Node_test::_register_methods()
{
	register_method((char*)"_process", &Node_test::_process);
}

void Node_test::_init() {}

Node_test::Node_test(){}
Node_test::~Node_test(){}


void Node_test::_process(float delta)
{
	
} 
