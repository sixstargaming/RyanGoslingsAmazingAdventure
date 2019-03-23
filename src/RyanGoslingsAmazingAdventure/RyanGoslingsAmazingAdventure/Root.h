#ifndef ROOT_H
#define ROOT_H

// Godot includes
#include <core/Godot.hpp>
#include <Node2D.hpp>
#include <Input.hpp>
#include <InputEvent.hpp>
#include <InputEventKey.hpp>
//#include <InputEventAction.hpp>
#include <InputEventMouseButton.hpp>
#include <SceneTree.hpp>
#include <GlobalConstants.hpp>
#include <CanvasItem.hpp>

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
		static Player* pPlayer;
		static Node2D* pCereals;
		static CanvasItem* pCanvas;

		Node2D* pExit;

		static void _register_methods();

		void _init();
		void _ready();

		Root();
		~Root();

		//void _init(); // Initializer called by Godot

		void _input(InputEvent* e);
		void ProcessMouseWheel(InputEventMouseButton* e);
	};
}

#endif