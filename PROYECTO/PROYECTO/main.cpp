//
//  main.cpp
//  PROYECTO
//
//  Created by DevJAD on 1/11/17.
//  Copyright © 2017 DevJAD. All rights reserved.
//

#include "iostream"
#include "Constants.hpp"
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "SharkEntity.hpp"

int main(int argc, const char * argv[]) {
    DevJAD::Game("UPAO", SCREEN_SIZE_TYPE_MEDIUM); // SCREEN_SIZE_TYPE_LARGE
    return EXIT_SUCCESS;
}
