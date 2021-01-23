/**
 * @file mainmenu.c
 *
 * @author Killax-D | Dylan DONNE
 *
 * @brief MainMenu is a Scene, used to display start menu ingame
 *
 * This file contains all declarations and function regarding MainMenu Scene
 *
 */
 
#include "../scene.h"

void Scene_MainMenuUpdate(float delta) {
	
}

void Scene_MainMenuDraw() {
	DrawRectangle(200, 150, 400, 300, GREEN);
}

Scene * Scene_MainMenuConstruct() {
	Scene * scene = Scene_new();
	scene->update = Scene_MainMenuUpdate;
	scene->draw = Scene_MainMenuDraw;
	return scene;
}
