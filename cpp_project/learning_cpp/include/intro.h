#ifndef INTRO_H
#define INTRO_H

#include <iostream>
#include <Godot.hpp>
#include <Control.hpp>
#include <SceneTree.hpp>
#include <ResourceLoader.hpp>
#include <Ref.hpp>
#include <PackedScene.hpp>
#include <Viewport.hpp>


namespace godot
{
    class Intro: public Control
    {
	private:
		GODOT_CLASS(Intro, Control)
	public:
		static void _register_methods();
		void _init();
		Intro();
		~Intro();
		
	public:
		void _ready();
		
	public:
		void _on_button_pressed(Variant body);
	};
}


















#endif
