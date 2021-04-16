#ifndef GAME_1_XO_H
#define GAME_1_XO_H

#include <Godot.hpp>
#include <Sprite.hpp>

namespace godot
{
	class Game_1_xo: public Sprite
	{
	private:
		GODOT_CLASS(Game_1_xo, Sprite)
	public:
		static void _register_methods();
		void _init();
		Game_1_xo();
		~Game_1_xo();
		
	public:
		void _ready();
		
	};
}





















#endif
