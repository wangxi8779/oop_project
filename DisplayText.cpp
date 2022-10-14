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
  //textObj.setFont(font);
}

DisplayText :: DisplayText(std::string sText, sf::Text con_text, int size)
  : _text(sText), textObj(con_text)
{
  //text.setPosition(_x, _y);
  textObj.setCharacterSize(size);
  textObj.setString(_text);
  textObj.setFillColor(sf::Color(red, green, blue));
  //textObj.setFont(font);
}

void DisplayText :: setColor(int aRed, int aGreen, int aBlue)
{
  textObj.setFillColor(sf::Color(aRed,aGreen,aBlue));
}

void DisplayText :: setPos(int x, int y)
{
  // _x = x;
  //_y = y;
  textObj.setPosition(x,y);
}

DisplayText :: ~DisplayText()
{
}
