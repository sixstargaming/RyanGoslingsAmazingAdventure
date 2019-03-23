#include <core/Godot.hpp>
#include <Node.hpp>
#include <TextureRect.hpp>
#include "Root.h"

namespace godot {
	class Door : public Node2D {
		GODOT_CLASS(Door, Node2D)
	public:
		static void _register_methods();

		void _init();
		void _on_Area2D_body_entered(Variant v);

		Door();
		~Door();
	};
}