#include "WinScreen.h"

using namespace godot;

void WinScreen::_register_methods() {
	register_method((char*)"_on_QuitButton_pressed", &WinScreen::_on_QuitButton_pressed);
	register_method((char*)"_on_AgainButton_pressed", &WinScreen::_on_AgainButton_pressed);
}

void WinScreen::_on_QuitButton_pressed(Variant) {
	get_tree()->quit();
}

void WinScreen::_on_AgainButton_pressed(Variant) {
	get_tree()->reload_current_scene();
}

void WinScreen::_init() { return; }

WinScreen::WinScreen() { }
WinScreen::~WinScreen(){ }
