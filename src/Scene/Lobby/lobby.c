/**
 * @file lobby.c
 *
 * @author Killax-D | Dylan DONNE
 *
 * @brief Lobby is a Scene, used to display start menu ingame
 *
 * This file contains all declarations and function regarding Lobby Scene
 *
 */
 
#include "lobby.h"

Lobby * Lobby_new() {
	Lobby * menu = malloc(sizeof(Lobby));
	menu->text = "IN GAME";
	return menu;
}

void Scene_LobbyUpdate(void * manager_ptr, void * object_ptr, float delta) {
	
}

void Scene_LobbyDraw(void * manager_ptr, void * object_ptr) {
	Lobby * menu = object_ptr;

	DrawRectangle(GetScreenWidth()/2 - GetScreenWidth()/4, GetScreenHeight()/2 - GetScreenHeight()/4, GetScreenWidth()/2, GetScreenHeight()/2, GREEN);

	int text_width = MeasureText(menu->text, 20);
	
	DrawText(menu->text, GetScreenWidth()/2 - text_width/2, GetScreenHeight()/2 - 20/2, 20, WHITE);
}

Scene * Scene_LobbyConstruct() {
	Scene * scene = Scene_new();
	scene->update = Scene_LobbyUpdate;
	scene->draw = Scene_LobbyDraw;

	Lobby * menu = Lobby_new();

	scene->object_ptr = menu;

	return scene;
}