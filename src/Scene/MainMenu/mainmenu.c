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
 
#include "mainmenu.h"

MainMenu * MainMenu_new() {
	MainMenu * menu = malloc(sizeof(MainMenu));
	menu->text = GAME_NAME;
	return menu;
}

void Scene_MainMenuUpdate(void * manager_ptr, void * object_ptr, float delta) {
	if(IsKeyDown(KEY_ENTER)) SceneManager_push(manager_ptr, SCENE_LOBBY);
}

void Scene_MainMenuDraw(void * manager_ptr, void * object_ptr) {
	MainMenu * menu = object_ptr;

	int text_width = MeasureText(menu->text, 20);
	
	DrawText(menu->text, GetScreenWidth()/2 - text_width/2, GetScreenHeight()/2 - 20/2, 20, WHITE);
}

Scene * Scene_MainMenuConstruct() {
	Scene * scene = Scene_new();
	scene->update = Scene_MainMenuUpdate;
	scene->draw = Scene_MainMenuDraw;

	MainMenu * menu = MainMenu_new();

	scene->object_ptr = menu;

	return scene;
}