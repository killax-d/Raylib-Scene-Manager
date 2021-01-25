/**
 * @file scene.c
 *
 * @author Killax-D | Dylan DONNE
 *
 * @brief Scene is like a Pane inside game, SceneManager is used to switch between different Scene
 *
 * This file contains all declarations and function regarding Scene
 *
 */
 
#include "scene.h"

Scene * Scene_new() {
	Scene * scene = malloc(sizeof(Scene));
	return scene;
}

void Scene_updateScene(Scene * scene, float delta) {
	scene->update(scene->object_ptr, delta);
}

void Scene_drawScene(Scene * scene) {
	scene->draw(scene->object_ptr);
}