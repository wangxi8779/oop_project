#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Button
{
 private:
  int buttonW;
  int buttonL;
  std::string buttonCol;
    
 public:
  sf::RectangleShape recB; 
  // need to add a default constructor
  Button(sf::RectangleShape s_button, int bWidth, int bLength, int red, int gre, int blue);
  void setPos(int x_pos, int y_pos);
  ~Button();
};

#endif
