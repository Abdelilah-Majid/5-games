#ifndef BORDER_AREA2D_H
#define BORDER_AREA2D_H


#include <Godot.hpp>
#include <Area2D.hpp>

namespace godot
{
	class Border_area2d: public Area2D
	{
	private:
		GODOT_CLASS(Border_area2d, Area2D)
	public:
		static void _register_methods();
		void _init();
		Border_area2d();
		~Border_area2d();
		
	public:
		void _ready();
		void _physics_process();
		
	public:
		Array body_entered_signal_params {};
		
	};
}







#endif
