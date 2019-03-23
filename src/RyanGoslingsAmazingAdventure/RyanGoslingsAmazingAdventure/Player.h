#ifndef PLAYER_H
#define PLAYER_H

#include "Root.h"
#include <KinematicBody2D.hpp>
#include <Camera2D.hpp>
#include <Input.hpp>

namespace godot {
	class Player : public KinematicBody2D {
		GODOT_CLASS(Player, KinematicBody2D)
	private:
		Vector2 motion;
	public:
		Camera2D* pCamera;
		const int SPEED = 300;

		static void _register_methods();
		void _init();
		void _process(float delta);
		void _ready();

		void UpdateMotionFromInput();
		Player();
		~Player();
	};
}

#endif