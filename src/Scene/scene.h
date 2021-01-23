/**
 * @file scene.h
 *
 * @author Killax-D | Dylan DONNE
 *
 * @brief Scene is like a Pane inside game, SceneManager is used to switch between different Scene
 *
 * This file contains all declarations and function regarding Scene
 *
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <stdlib.h>
#include <raylib.h>


/**
 * Define an update method
 * @param scene The Scene to update
 * @param delta The current deltaTime
 */
typedef void (*updateSceneMethod)(float delta);
// Declare all update functions
void Scene_MainMenuUpdate(float delta);


/**
 * Define an draw method
 * @param scene The Scene to draw
 */
typedef void (*drawSceneMethod)();
// Declare all draw functions
void Scene_MainMenuDraw();



/**
 * Struct to represent a Scene
 */
typedef struct Scene {
	updateSceneMethod update;
	drawSceneMethod draw;
} Scene;



/**
 * Define an construction method for all Scene
 */
Scene * Scene_MainMenuConstruct();



/**
 * Create a Scene and return the pointer
 * @return A pointer to the Scene
 */
Scene * Scene_new();

/**
 * Update the current Scene active
 * @param scene The Scene to update
 * @param delta The current deltaTime
 */
void Scene_updateScene(Scene * scene, float delta);

/**
 * Draw the current Scene active
 * @param scene The Scene to draw
 */
void Scene_drawScene(Scene * scene);

#endif