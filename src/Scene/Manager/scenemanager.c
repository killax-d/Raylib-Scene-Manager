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
	manager->currentScene = 0x0;
	manager->nextScene = 0x0;

	manager->scenes[SCENE_MAIN_MENU] = Scene_MainMenuConstruct();
	manager->scenes[SCENE_LOBBY] = Scene_LobbyConstruct();

	manager->transition = Transition_new();

	SceneManager_push(manager, SCENE_MAIN_MENU);
}

void SceneManager_update(SceneManager * manager, float delta) {
	// Update Transition
	if (manager->transition->direction != NONE) {
		if (manager->transition->direction == OUT) {
				manager->transition->opacity += 5;
			if (manager->transition->opacity >= 255) SceneManager_transition(manager, IN);

		} else {
			manager->transition->opacity -= 5;
			if (manager->transition->opacity <= 0) SceneManager_transition(manager, NONE);
		}
	}

	// Update Scene
	if (manager->currentScene) Scene_updateScene(manager, manager->currentScene, delta);
}

void SceneManager_draw(SceneManager * manager) {
	// Draw Scene
	if (manager->currentScene) Scene_drawScene(manager, manager->currentScene);

	// Draw Transition
	if (manager->transition->direction != NONE)
		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), (Color) {0, 0, 0, manager->transition->opacity});
}

void SceneManager_push(SceneManager * manager, int sceneID) {
	if (sceneID >= 0 && sceneID < SCENE_COUNT) {
		manager->nextScene = manager->scenes[sceneID];
		SceneManager_transition(manager, manager->currentScene ? OUT : IN);
	}
}

void SceneManager_transition(SceneManager * manager, TransitionDirection direction) {
	if (direction == IN) {
		manager->currentScene = manager->nextScene;
		manager->nextScene = 0x0;
	}

	manager->transition->direction = direction;

	if (direction == OUT) manager->transition->opacity = 0;
	else if (direction == IN) manager->transition->opacity = 255;
	else manager->transition->opacity = -1;
}