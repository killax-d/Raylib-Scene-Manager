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

#include "../../Env/env.h"
#include "../scene.h"

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
 * Return the pointer casted into MainMenu object
 * @param scene A Scene object originally defined as MainMenu
 * @return A pointer to the MainMenu
 */
MainMenu * MainMenu_get(Scene * scene);