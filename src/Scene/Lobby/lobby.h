/**
 * @file lobby.h
 *
 * @author Killax-D | Dylan DONNE
 *
 * @brief Lobby is a Scene, used to display start menu ingame
 *
 * This file contains all declarations and function regarding Lobby Scene
 *
 */

#ifndef SCENE_LOBBY_H
#define SCENE_LOBBY_H

#include "../../Env/env.h"
#include "../scene.h"

/**
 * Struct to represent a Scene
 */
typedef struct Lobby {
    char * text;
} Lobby;

/**
 * Create a Lobby and return the pointer
 * @return A pointer to the Lobby
 */
Lobby * Lobby_new();

/**
 * Define an draw method, should be defined as "updateSceneMethod" from scene.h
 * @param object_ptr The object_ptr contained in Scene Object
 */
void Scene_LobbyUpdate(void * manager_ptr, void * object_ptr, float delta);

/**
 * Define an draw method, should be defined as "drawSceneMethod" from scene.h
 * @param object_ptr The object_ptr contained in Scene Object
 */
void Scene_LobbyDraw(void * manager_ptr, void * object_ptr);

#endif