#include "Root.h"

using namespace godot;

Player* Root::pPlayer;
Node2D* Root::pCereals;
CanvasItem* Root::pCanvas;

void Root::_register_methods() {
	register_method((char*)"_input", &Root::_input);
	register_method((char*)"_ready", &Root::_ready);
}

void Root::_init() { return; }

Root::Root() { }
Root::~Root() { }

// Parse Input Events
void Root::_input(InputEvent* e) {
	const godot::String gsIEMB = "InputEventMouseButton";
	godot::String gsClass = e->get_class();
	if (gsClass == gsIEMB) {
		ProcessMouseWheel((InputEventMouseButton*)e);
	}
	const godot::String gsIEK = "InputEventKey";
	if (gsClass == gsIEK) {
		InputEventKey* k = (InputEventKey*)e;
		if (k->get_scancode() == GlobalConstants::KEY_ESCAPE) {
			get_tree()->quit();
		}
	}
}

// MouseWheel
void Root::ProcessMouseWheel(InputEventMouseButton* e) {
	int64_t buttonIndex = e->get_button_index();
	if (e->is_pressed()) {
		if (buttonIndex == GlobalConstants::BUTTON_WHEEL_DOWN) {
			Vector2 v = pPlayer->pCamera->get_zoom();
			v.x = v.y = (v.x * 10.0f / 9.0f);
			if (v.x > 1.25) {
				v.x = v.y = 1.25;
			}
			pPlayer->pCamera->set_zoom(v);
		} else if (buttonIndex == GlobalConstants::BUTTON_WHEEL_UP) {
			Vector2 v = pPlayer->pCamera->get_zoom();
			v.x = v.y = (v.x * 0.9f);
			pPlayer->pCamera->set_zoom(v);
		}
		

	}
}

void Root::_ready() {
	const godot::String gsExit = "Exit";
	const godot::String gsCereals = "Cereals";
	const godot::String gsCanvas = "CanvasLayer";
	Node* n;
	godot::Array a = get_children();
	int64_t childCount = get_child_count();

	for (int64_t x = 0; x < childCount; x++) {
		n = get_child(x);
		if (gsExit == n->get_name()) {
			pExit = (Node2D*)n; // Win
		} else if (gsCereals == n->get_name()) {
			pCereals = (Node2D*)n; // Loose TODO: Make player loose
		} else if (gsCanvas == n->get_name()) {
			pCanvas = (CanvasItem*)n;
		}
	}
}