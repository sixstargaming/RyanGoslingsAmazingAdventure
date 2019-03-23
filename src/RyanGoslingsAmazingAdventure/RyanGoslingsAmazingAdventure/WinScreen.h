#include <core/Godot.hpp>
#include <TextureRect.hpp>
#include <SceneTree.hpp>
#include <Tree.hpp>
#include "Root.h"

namespace godot {
	class WinScreen : public TextureRect {
		GODOT_CLASS(WinScreen, TextureRect)
	public:
		static void _register_methods();

		void _init();

		WinScreen();
		~WinScreen();

		void _on_QuitButton_pressed(Variant v);
		void _on_AgainButton_pressed(Variant v);
	};
}
