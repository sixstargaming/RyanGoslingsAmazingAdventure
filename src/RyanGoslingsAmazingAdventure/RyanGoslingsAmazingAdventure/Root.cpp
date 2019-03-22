#include "Root.h"

using namespace godot;

Player* Root::pPlayer;
Node2D* Root::pInnerWallContainerNode;

void Root::_register_methods() {
	//register_method((char*)"_input", &Root::HandleInputEvent);
}

Root::Root() { }
Root::~Root() { }

// Parse Input Events
/*void Root::HandleInputEvent(Variant v) {
	Object* o = v;
	InputEvent* e = (InputEvent*)o;
	const godot::String gsIEMB = "InputEventMouseButton";
	godot::String gsClass = e->get_class();
	if (gsClass == gsIEMB) {
		ProcessMWheel((InputEventMouseButton*)o);
	}
}*/

// MouseWheel
void Root::ProcessMWheel(InputEventMouseButton* e) {
	int64_t buttonIndex = e->get_button_index();
	if (e->is_pressed()) {
		if (buttonIndex == GlobalConstants::BUTTON_WHEEL_DOWN) {

		}
		else if (buttonIndex == GlobalConstants::BUTTON_WHEEL_UP) {

		}

	}
}