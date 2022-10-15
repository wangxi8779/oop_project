#include "Button.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Button :: Button(sf::RectangleShape s_button, int bWidth, int bLength, int red, int green, int blue)
: buttonW(bWidth), buttonL(bLength), recB(s_button)
{
  recB.setSize(sf::Vector2f(buttonW, buttonL));
  recB.setFillColor(sf::Color(red,green,blue));
}

Button :: Button()
{
  buttonW = 0;
  buttonL = 0;
  buttonCol = "NULL";
}

void Button :: setPos(int x_pos, int y_pos)
{
  recB.setPosition(x_pos, y_pos);
}

Button :: ~Button()
{
}


