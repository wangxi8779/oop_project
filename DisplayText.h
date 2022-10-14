#ifndef DISPLAYTEXT_H
#define DISPLAYTEXT_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class DisplayText
{
 private:
  int _x, _y;
  int red = 0;
  int green = 0;
  int blue = 0;
  std::string _text;

 public:
  sf::Text textObj;
  DisplayText(std::string sText, sf::Text con_text, int size);
  DisplayText();
  void setColor(int aRed, int aGreen, int aBlue);
  void setPos(int _x, int _y);
  ~DisplayText();
};
#endif
