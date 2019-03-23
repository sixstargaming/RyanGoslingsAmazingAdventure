#include "Door.h""

using namespace godot;

void Door::_register_methods() {
	register_method((char*)"_on_Area2D_body_entered", &Door::_on_Area2D_body_entered);
}

void Door::_init() { return; }

void Door::_on_Area2D_body_entered(Variant) {
	TextureRect* t = (TextureRect*)Root::pCanvas->get_child(0);
	t->set_visible(true);
}

Door::Door() { }
Door::~Door() { }