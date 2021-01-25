/**
 * @file mainmenu.h
 *
 * @author Killax-D | Dylan DONNE
 *
 * @brief MainMenu is a Scene, used to display start menu ingame
 *
 * This file contains all declarations and function regarding MainMenu Scene
 *
 */
 
#ifndef SCENE_MAIN_MENU_H_
#define SCENE_MAIN_MENU_H_

#include "../../Env/env.h"
#include "../scene.h"
#include "../Manager/scenemanager.h"

/**
 * Struct to represent a Scene
 */
typedef struct MainMenu {
    char * text;
} MainMenu;

/**
 * Create a MainMenu and return the pointer
 * @return A pointer to the MainMenu
 */
MainMenu * MainMenu_new();

/**
 * Define an draw method, should be defined as "updateSceneMethod" from scene.h
 * @param object_ptr The object_ptr contained in Scene Object
 */
void Scene_MainMenuUpdate(void * manager_ptr, void * object_ptr, float delta);

/**
 * Define an draw method, should be defined as "drawSceneMethod" from scene.h
 * @param object_ptr The object_ptr contained in Scene Object
 */
void Scene_MainMenuDraw(void * manager_ptr, void * object_ptr);

#endif