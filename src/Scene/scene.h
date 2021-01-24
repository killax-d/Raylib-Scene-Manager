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

#define SCENE_COUNT 1
#define SCENE_MAIN_MENU 0

#include <stdlib.h>
#include <raylib.h>


/**
 * Define an update method
 * @param scene The Scene to update
 * @param delta The current deltaTime
 */
typedef void (*updateSceneMethod)(void * scene_ptr, float delta);
// Declare all update functions
extern void Scene_MainMenuUpdate(void * scene_ptr, float delta);


/**
 * Define an draw method
 * @param scene The Scene to draw
 */
typedef void (*drawSceneMethod)(void * scene_ptr);
// Declare all draw functions
extern void Scene_MainMenuDraw(void * scene_ptr);



/**
 * Struct to represent a Scene
 */
typedef struct Scene {
	updateSceneMethod update;
	drawSceneMethod draw;
	void * object_pointer;
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
 * Return a pointer casted into Scene object
 * @param scene_ptr A Scene pointer
 * @return A pointer to the Scene
 */
Scene * Scene_get(void * scene_ptr);

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