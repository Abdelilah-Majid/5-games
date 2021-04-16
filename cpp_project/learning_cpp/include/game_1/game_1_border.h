#ifndef GAME_1_BORDER
#define GAME_1_BORDER

#include <String.hpp>
#include <vector>
#include <GDNative.hpp>
#include <Godot.hpp>
#include <Node2D.hpp>
#include <InputEvent.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <Ref.hpp>
#include <Node.hpp>
#include <Sprite.hpp>
#include <Label.hpp>
#include <SceneTree.hpp> 
#include <Viewport.hpp>


namespace godot
{
	class Game_1_border: public Node2D
	{
	private:
		GODOT_CLASS(Game_1_border, Node2D)
	public:
		static void _register_methods();
		void _init();
		Game_1_border();
		~Game_1_border();
	
	public:
		void _ready();
		void _physics_process();
		
	public:
		void _on_area_2D_input(Variant viewport, Variant event, int shape_idx, Variant node);
		void  how_to_instance_children(Vector2 index);
		void _on_replay_button_pressed();
		
	public:
		int player_x_or_o = 1;
		std::vector<int> state_arr{0, 0, 0, 0, 0, 0, 0, 0, 0};
		godot::String winer_message="hello";
		bool someone_wins=false;
	};
}






 











#endif
