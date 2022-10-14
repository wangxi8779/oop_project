#include <SFML/Graphics.hpp>
#include "Button.h"
#include "DisplayText.h"

// Screen resolution
int WIDTH = 1000;
int HEIGHT = 600;

// for testing
double balance = 500;


int main()
{

  sf::Color Grey(54,69,79);
  
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Stock Trader");
  //window.setFillColor(sf::Color(0,0,102));

  // need to change to class scheme.
  sf::RectangleShape priceScreen(sf::Vector2f(700,400));
  priceScreen.setOutlineThickness(10);
  priceScreen.setOutlineColor(sf::Color(128,128,128));
  priceScreen.setFillColor(Grey);
  priceScreen.setPosition(280, 20);

  //awful button shapes
  sf::RectangleShape buyB;
  Button b1(buyB, 140, 60, 224, 224, 224);
  b1.setPos(70,10);

  sf::RectangleShape sellB;
  Button b2(sellB, 140, 60, 224, 224, 224);
  b2.setPos(70,100);

  sf::RectangleShape sellOrder_button;
  Button b3(sellOrder_button, 140, 60, 224, 224, 224);
  b3.setPos(70, 190);

  sf::RectangleShape buyOrder_button;
  Button b4(buyOrder_button, 140, 60, 224, 224, 224);
  b4.setPos(70, 280);

  sf::RectangleShape change_user;
  Button b5(change_user, 140, 60, 224, 224, 224);
  b5.setPos(70, 370);

  sf::RectangleShape print_money_b;
  Button b6(print_money_b, 140, 60, 224, 224, 224);
  b6.setPos(70, 460);

  sf::RectangleShape price_overview;
  Button b7(print_money_b, 500, 125, 150, 150, 150);
  b7.setPos(270,460);

  sf::RectangleShape _bank;
  Button b8(_bank, 150,100, 170, 170, 170);
  b8.setPos(820,460);

  
  //loading in font
  sf::Font font;
  if (!font.loadFromFile("secrcode.ttf"))
    {
      std::cout<<"ERROR loading font"<<std::endl;
      return 0;
    }
    
  // testing with sf::Text class
  sf::Text text;
  text.setFont(font);
  text.setString("Test");
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::Red);


  //Button Texts
  sf::Text buy_text, sell_text, buy_order, sell_order, change_usr, add_bank;
  
  DisplayText buy_t("Buy", buy_text, 20);
  buy_t.setPos(80, 25);
  (buy_t.textObj).setFont(font);

  DisplayText sell_t("Sell", sell_text, 20);
  sell_t.setPos(80, 115);
  (sell_t.textObj).setFont(font);

  DisplayText buyOrder_t("Buy Order", buy_order, 20);
  buyOrder_t.setPos(80, 205);
  (buyOrder_t.textObj).setFont(font);

  DisplayText sellOrder_t("Sell Order", sell_order, 20);
  sellOrder_t.setPos(80, 295);
  (sellOrder_t.textObj).setFont(font);

  DisplayText usr_t("Change User", change_usr, 20);
  usr_t.setPos(80, 385);
  (usr_t.textObj).setFont(font);

  DisplayText add_bank_t("Add Income", add_bank, 20);
  add_bank_t.setPos(80, 475);
  (add_bank_t.textObj).setFont(font);


  // program run time?
  while (window.isOpen())
    {
      //All events go here
      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	  
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	    {
	      std::cout<<"Closing window..."<<std::endl;
	      std::cout<<"Window closed." << std::endl;
	      window.close();
	    }

	  // individual button mouse clicks -- need to try make class to write less code...
	  if (event.type == sf::Event::MouseButtonReleased)// && check_region(70,210,10,70))
	    {

	      if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= 70
		  && event.mouseButton.x <= 210 && event.mouseButton.y >= 460 && event.mouseButton.y <= 520)
		{
		  balance += 50;
		  std::cout << balance << std::endl;
		}
	      
	      if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= 70
		  && event.mouseButton.x <= 210 && event.mouseButton.y >= 10 && event.mouseButton.y <= 80)
		{
		  balance -= 50;
		  std :: cout << balance << std :: endl;
		}
	      
	      if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= 70
		  && event.mouseButton.x <= 210 && event.mouseButton.y >= 100 && event.mouseButton.y <= 160)
		{
		  std :: cout << "Sell Button clicked" << std :: endl;
		}

	      if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= 70
		  && event.mouseButton.x <= 210 && event.mouseButton.y >= 190 && event.mouseButton.y <= 250)
		{
		  std :: cout << " Buy Order set: need popup" << std :: endl;
		}

	      if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= 70
		  && event.mouseButton.x <= 210 && event.mouseButton.y >= 280 && event.mouseButton.y <= 340)
		{
		  std :: cout << "Sell Order set: needs popup" << std :: endl;
		}

	      if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= 70
		  && event.mouseButton.x <= 210 && event.mouseButton.y >= 370 && event.mouseButton.y <= 430)
		{
		  std :: cout << "change user button clicked" << std :: endl;
		}
	    }
	} // end events

      
	// while(window.pollEvent(event))
	//   {
	//     if(event.type == sf::Event::KeyPressed)
	//       {
	// 	std::cout<<"b1 Pressed" << std::endl;
	//       }
	//   }
	

	// Drawing GUI and updates
        window.clear(sf::Color(15,5,30));
	window.draw(b1.recB);
	window.draw(b2.recB);
	window.draw(b3.recB);
	window.draw(b4.recB);
	window.draw(b5.recB);
	window.draw(b6.recB);
	window.draw(b7.recB);
	window.draw(b8.recB);
	window.draw(priceScreen);

	window.draw(text);
	window.draw(buy_t.textObj);
	window.draw(sell_t.textObj);
	window.draw(buyOrder_t.textObj);
	window.draw(sellOrder_t.textObj);
	window.draw(usr_t.textObj);
	window.draw(add_bank_t.textObj);
	
	window.display();
    }
    return 0;
}
