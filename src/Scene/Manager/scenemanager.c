/**
 * @file scenemanager.c
 *
 * @author Killax-D | Dylan DONNE
 *
 * @brief Scene Manager, used to switch game Scene with interactions
 *
 * This file contains all declarations and function regarding SceneManager
 *
 */
 
#include "scenemanager.h"

SceneManager * SceneManager_new() {
	SceneManager * manager = malloc(sizeof(SceneManager));
	return manager;
}

void SceneManager_init(SceneManager * manager) {
	manager = SceneManager_new();
	manager->scenes[SCENE_MAIN_MENU] = Scene_MainMenuConstruct();
	manager->currentScene = manager->scenes[SCENE_MAIN_MENU];
}

void SceneManager_update(SceneManager * manager, float delta) {
	if (manager->currentScene) Scene_updateScene(manager->currentScene, delta);
}

void SceneManager_draw(SceneManager * manager) {
	if (manager->currentScene) Scene_drawScene(manager->currentScene);
}
