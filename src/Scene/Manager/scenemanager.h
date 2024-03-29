/**
 * @file scenemanager.h
 *
 * @author Killax-D | Dylan DONNE
 *
 * @brief Scene Manager, used to switch game Scene with interactions
 *
 * This file contains all declarations and function regarding SceneManager
 *
 */

#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

#include <stdlib.h>
#include "../scene.h"
#include "../../Env/Logger/logger.h"
#include "Transition/transition.h"


/**
 * Struct to represent a SceneManager
 */
typedef struct SceneManager {
	Scene * scenes[SCENE_COUNT]; /**< The Scene list */
	Scene * currentScene; /**< The current Scene active */
	Scene * nextScene; /**< The next Scene to activate */
	Transition * transition; /**< The transition between two Scene */
} SceneManager;

/**
 * Create a SceneManager and return the pointer
 * @return A pointer to the SceneManager
 */
SceneManager * SceneManager_new();

/**
 * Initialize a SceneManager with all Scene availables
 * @param manager The SceneManager to initialize
 */
void SceneManager_init(SceneManager * manager);

/**
 * Update the current Scene active in SceneManager
 * @param manager The SceneManager currently used in game
 * @param delta The current deltaTime
 */
void SceneManager_update(SceneManager * manager, float delta);

/**
 * Draw the current Scene active in SceneManager
 * @param manager The SceneManager currently used in game
 */
void SceneManager_draw(SceneManager * manager);

/**
 * Push a new Scene to display
 * @param manager The SceneManager currently used in game
 * @param sceneID The Scene to push
 */
 void SceneManager_push(SceneManager * manager, int sceneID);

 /**
 * Call a transition between scene
 * @param manager The SceneManager currently used in game
 * @param direction The TransitionDirection to animate (IN, OUT, NONE)
 */
 void SceneManager_transition(SceneManager * manager, TransitionDirection direction);

#endif