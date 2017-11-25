//
//  Utils.h
//  PROYECTO
//
//  Created by Alex Paredes on 25/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef Utils_h
#define Utils_h

inline sf::Vector2f getCenterPosition(sf::Vector2u window, sf::FloatRect sprite){
    return sf::Vector2f(window.x / 2 - ( sprite.width / 2), window.y / 2 - ( sprite.height / 2) );
}


#endif /* Utils_h */
