#include "Player.h"

using namespace godot;

void Player::_register_methods() {
	register_method((char*)"_process", &Player::_process);
	//register_method((char*)"_ready", &Player::_ready);
}

void Player::_init() { }

Player::Player() {
	motion = Vector2(0, 0);
}
Player::~Player() { }

void Player::_process(float delta) {
	UpdateMotionFromInput();
	move_and_slide(motion);
}

void Player::UpdateMotionFromInput() {
	motion = Vector2(0, 0);
	Input* i = Input::get_singleton();

	if (i->is_action_pressed("ui_up")) {
		motion.y -= SPEED;
	}
	if (i->is_action_pressed("ui_down")) {
		motion.y += SPEED;
	}
	if (i->is_action_pressed("ui_left")) {
		motion.x -= SPEED;
	}
	if (i->is_action_pressed("ui_right")) {
		motion.x += SPEED;
	}
}

/*void Player::_ready() {
	const godot::String gsCamera2D = "Camera2D";
	Node* n;
	godot::Array a = owner->get_children();
	int_64_t childCount = owner->get_child_count();

	for (int64t x = 0; x < childCount; x++) {
		n = owner->get_child(x);
		if (gsCamera2D == n->get_name()) {
			pCamera = (Camera2D*)n);
		}
	}

	Root::pPlayer = this;
}*/