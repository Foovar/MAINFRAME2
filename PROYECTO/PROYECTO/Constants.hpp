//
//  Constants.hpp
//  PROYECTO
//
//  Created by DevJAD on 1/11/17.
//  Copyright © 2017 DevJAD. All rights reserved.
//
#pragma once
#ifndef Header_h
#define Header_h

#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH 1324.0f
#define SCREEN_HEIGHT 1024.0f

#define MEDIUM_SCREEN_SIZE_WIDTH 800.f
#define LARGE_SCREEN_SIZE_WIDTH  1324.f
#define MEDIUM_SCREEN_SIZE_HEIGHT 600.f
#define LARGE_SCREEN_SIZE_HEIGHT  1024.f

#define SHOT_TIME 100.f;

#define SCREEN_SIZE_TYPE_MEDIUM 0
#define SCREEN_SIZE_TYPE_LARGE 1

#define FLASH_SPEED 300.0f
#define GAME_OVER_AFTER_FLASH 900.f

#define GAME_CHARACTER01_PATH "Assets/images/character01.png"
#define GAME_CHARACTER02_PATH "Assets/images/character02.png"
#define GAME_CHARACTER03_PATH "Assets/images/character03.png"

#define GAME_MOVE_TO_UP 0
#define GAME_MOVE_TO_DOWN 1
#define GAME_MOVE_TO_LEFT 2
#define GAME_MOVE_TO_RIGTH 3
#define IS_SWIMMING 4
#define IS_ATTACKING 5
#define IS_DEAD 6
#define IS_GAME_OVER 7
#define IS_PLAYING 8
// PERSONAJES
#define CHARACTER_STATE_WALK 0
#define CHARACTER_STATE_JUMPING 1
#define CHARACTER_STATE_HANG 2
#define CHARACTER_STATE_SWIM 3
#define CHARACTER_STATE_ATTACK 4
#define CHARACTER_STATE_DEAD 5

#define CHARACTER_MOVE_UP 20
#define CHARACTER_MOVE_DOWN 21
#define CHARACTER_MOVE_LEFT 22
#define CHARACTER_MOVE_RIGTH 23

#define CHARACTER_MOVE_SPEED 450.f
// ESCENARIOS

#define SCOREBAR_FILEPATH "Assets/images/scorebar.png"
#define SCOREBAR_FONT_FILEPATH "Assets/fonts/display.ttf"
// splash
#define SPASH_BACKGROUND_FILEPATH ""
#define SPLASH_EXTRA_FILEPATH "Assets/images/extra_splash.png"
#define SPLASH_LOGO_FILEPATH "Assets/images/logo_splash.png"
#define SPLASH_DURATION 4.0

// main
#define MAIN_BACKGROUND_FILEPATH "Assets/images/main_background.jpg"
#define MAIN_MENU_FILEPATH "Assets/images/main_menu_sprite.png"
#define MAIN_TITLE_FILEPATH "Assets/images/main_title.png"
#define MAIN_SOUND_BACKGROUND "Assets/sounds/main-sound.wav"
#define MAIN_SOUND_CLICK "Assets/sounds/main-click.wav"
#define MAIN_SOUND_HOVER "Assets/sounds/main-hover.wav"
// forest
#define FOREST_BACKGROUND_FILEPATH "Assets/images/forest_background.jpg"

// sea
#define SEA_BACKGROUND_FILEPATH "Assets/images/sea_background.png"
#define SEA_CORAL_FILEPATH "Assets/images/sea_coral.png"
#define SEA_SOUND_BACKGROUND "Assets/sounds/sea-background.wav"
#define SEA_ATTACK "Assets/sounds/sea-attack.wav"

//game over
#define GAME_OVER_BOX_FILEPATH "Assets/images/game_over.png"
#define GAME_OVER_BUTTONS_FILEPATH "Assets/images/game_over_buttons.png"

// ENTIDADES
#define SHARK_FILEPATH "Assets/images/shark.png"
#define SHARK_SWIMMING 0
#define SHARK_DIE 1
#define SHARK_ATTACK 2

#endif /* Header_h */
