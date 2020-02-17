/*
** EPITECH PROJECT, 2020
** my_defender.h
** File description:
** my defender header file
*/

#ifndef MY_DEFENDER_H_
#define MY_DEFENDER_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>

enum game_state {
    PLAY,
    MENU,
    PAUSE
} ;

enum button_state {
    IDLE,
    HOVER,
    CLICK
} ;

typedef struct map {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} map;

typedef struct button {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    int state;
} button;

typedef struct menu_ui {
    button play_btn;
    button hiscore_btn;
    button settings_btn;
    button quit_btn;
} menu_ui;

typedef struct menu_background {
    sfSprite *background_sprite;
    sfTexture *background_texture;
    sfVector2f pos;
} menu_background ;

typedef struct menu_scene {
    sfRenderWindow *window;
    menu_background menu_background;
    menu_ui ui;
} menu_scene;

typedef struct play_scene {
    sfRenderWindow *window;
} play_scene;

typedef struct game_core {
    sfRenderWindow *window;
    play_scene play_scene;
    menu_scene menu_scene;
    sfEvent event;
    int game_state;
} game_core;

void run(void);

//INITIALISATION
void i_game_core(game_core *game_core);
void i_play_scene(play_scene *, sfRenderWindow *);
void i_menu_scene(menu_scene *menu_scene, sfRenderWindow *);
void i_menu_background(menu_background *menu_background);
void i_menu_ui(menu_ui *menu_ui);

//UPDATE
void u_game_core(game_core *game_core);
void u_menu_scene(menu_scene *menu_scene);

//DISPLAY
void d_game_core(game_core *, sfRenderWindow *);
#endif /* !MY_DEFENDER_H_ */
