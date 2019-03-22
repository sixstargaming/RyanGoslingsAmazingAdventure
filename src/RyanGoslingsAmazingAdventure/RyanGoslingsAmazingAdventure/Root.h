#ifndef ROOT_H
#define ROOT_H

// Godot includes
#include <core/Godot.hpp>
#include <Node2D.hpp>
#include <InputEvent.hpp>
#include <InputEvent.hpp>
#include <InputEventAction.hpp>
#include <InputEventMouseButton.hpp>
#include <GlobalConstants.hpp>

// stdio
#include <stdio.h>

// Project Includes
#include "Player.h"

namespace godot {
	class Player;
	class Root : public Node2D {
		GODOT_CLASS(Root, Node2D)
	private:
	public:
		static Node2D* pInnerWallContainerNode;
		static Player* pPlayer;

		static void _register_methods();

		Root();
		~Root();

		//void _init(); // Initializer called by Godot

		void HandleInputEvent(Variant v);
		void ProcessMWheel(InputEventMouseButton* e);
	};
}

#endif