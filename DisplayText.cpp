#include "DisplayText.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

// Default constructor
DisplayText :: DisplayText()
{
  _x = 0;
  _y = 0;
  _text = "NULL";
}

DisplayText :: DisplayText(std::string sText, sf::Text con_text, int size)
: _text(sText), textObj(con_text)
{
  textObj.setCharacterSize(size);
  textObj.setString(_text);
  textObj.setFillColor(sf::Color(red, green, blue));
}

void DisplayText :: setColor(int aRed, int aGreen, int aBlue)
{
  red = aRed;
  green = aGreen;
  blue = aBlue;
  textObj.setFillColor(sf::Color(red, green, blue));
}

void DisplayText :: setPos(int x, int y)
{
  _x = x;
  _y = y;
  textObj.setPosition(_x,_y);
}

void DisplayText :: change_text(std::string newText)
{
  _text = newText;
  textObj.setString(_text);
}

DisplayText :: ~DisplayText()
{
}
