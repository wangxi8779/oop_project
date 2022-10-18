#include <SFML/Graphics.hpp>
#include "Button.h"
#include "DisplayText.h"
#include <iostream>

// Screen resolution
int WIDTH = 1000;
int HEIGHT = 600;

// for testing
double balance = 500;
unsigned int purchaseAmount = 0;

int main()
{
  //loading in font
  sf::Font font;
  if (!font.loadFromFile("secrcode.ttf"))
    {
      std::cout<<"ERROR loading font"<<std::endl;
      return 0;
    }

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
  Button b1(buyB, 120, 60, 224, 224, 224);
  b1.setPos(10,10);

  sf::RectangleShape sellB;
  Button b2(sellB, 120, 60, 224, 224, 224);
  b2.setPos(140,10);

  sf::RectangleShape sellOrder_button;
  Button b3(sellOrder_button, 120, 60, 224, 224, 224);
  b3.setPos(10, 90);

  sf::RectangleShape buyOrder_button;
  Button b4(buyOrder_button, 120, 60, 224, 224, 224);
  b4.setPos(140, 90);

  sf::RectangleShape change_user;
  Button b5(change_user, 120, 60, 224, 224, 224);
  b5.setPos(10, 170);

  sf::RectangleShape print_money_b;
  Button b6(print_money_b, 120, 60, 224, 224, 224);
  b6.setPos(140, 170);

  sf::RectangleShape price_overview;
  Button b7(print_money_b, 550, 100, 150, 150, 150);
  b7.setPos(270,440);

  sf::RectangleShape _bank;
  Button b8(_bank, 150, 65, 170, 170, 170);
  b8.setPos(840,440);


  //current user UI
  sf::RectangleShape current_user;
  Button current_user_b(current_user, 450, 20, 224,224,224);
  current_user_b.setPos(270, 560);

  sf::Text current_user_text;
  DisplayText user_text("User: ", current_user_text, 15);
  user_text.setPos(270,560);
  user_text.textObj.setFont(font);
  
  user_text.textObj.setStyle(sf::Text::Bold);

  
  //Watch list UI
  sf::RectangleShape buy_watch, sell_watch;

  Button buy_list(buy_watch, 120, 190, 224,224,224 );
  Button sell_list(sell_watch, 120, 190, 224,224,224);

  buy_list.setPos(10, 400);
  sell_list.setPos(140, 400);

  buy_watch.setOutlineThickness(3);
  sell_watch.setOutlineThickness(3);

  buy_watch.setOutlineColor(sf::Color(0,255,255));
  sell_watch.setOutlineColor(sf::Color(0,255,255));

  sf::Text b_watch_text, s_watch_text;
  DisplayText b_watch_display("Buy-orders", b_watch_text, 15);
  DisplayText s_watch_display("Sell-orders", s_watch_text, 15);

  b_watch_display.setPos(10,400);
  s_watch_display.setPos(140,400);

  b_watch_display.textObj.setFont(font);
  s_watch_display.textObj.setFont(font);

  b_watch_display.textObj.setStyle(sf::Text::Bold);
  s_watch_display.textObj.setStyle(sf::Text::Bold);
  
  // vertical lines to seperate stock options in price_overview
  sf::RectangleShape line1, line2, line3, line4, watch_line;
  Button line_b1(line1, 100, 3, 255,255,255);
  line_b1.setPos(380,440);
  line_b1.recB.rotate(90);

  Button line_b2(line2, 100, 3, 255,255,255);
  line_b2.setPos(490,440);
  line_b2.recB.rotate(90);

  Button line_b3(line3, 100, 3, 255,255,255);
  line_b3.setPos(600,440);
  line_b3.recB.rotate(90);

  Button line_b4(line4, 100, 3, 255,255,255);
  line_b4.setPos(710,440);
  line_b4.recB.rotate(90);

  // importing company logos
  //sf::Image tesla, apple, google, meta, amazon;

  //if(!background.loadFromFile()
  

  
  //watch line is line for watch lists
  Button watch_line_b(watch_line, 250,3, 0,0,0);
  watch_line_b.setPos(10,415);
  
  // testing with sf::Text class
  sf::Text text;
  text.setFont(font);
  text.setString("Test");
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::Red);

  //Button Texts
  sf::Text buy_text, sell_text, buy_order, sell_order, change_usr, add_bank, balance_text, plus, minus, purchaseAmount_text;
  
  DisplayText buy_t("Buy", buy_text, 20);
  buy_t.setPos(50, 25);
  (buy_t.textObj).setFont(font);

  DisplayText sell_t("Sell", sell_text, 20);
  sell_t.setPos(170, 25);
  (sell_t.textObj).setFont(font);

  DisplayText buyOrder_t("Buy Order", buy_order, 20);
  buyOrder_t.setPos(20, 105);
  (buyOrder_t.textObj).setFont(font);

  DisplayText sellOrder_t("Sell Order", sell_order, 20);
  sellOrder_t.setPos(145, 105);
  (sellOrder_t.textObj).setFont(font);

  DisplayText usr_t("Login", change_usr, 20);
  usr_t.setPos(40, 185);
  (usr_t.textObj).setFont(font);

  DisplayText add_bank_t("Add Income", add_bank, 20);
  add_bank_t.setPos(143, 185);
  (add_bank_t.textObj).setFont(font);

  DisplayText balance_t(std::to_string(balance), balance_text, 20);
  balance_t.setPos(840, 440);
  (balance_t.textObj).setFont(font);

  
  // + and - buttons for buy/sell & buyOrder/sellOrder & purchaseAmount
  sf::CircleShape trianglePlus(30,3);
  sf::CircleShape triangleMinus(30,3);
  
  sf::RectangleShape r_purchaseAmount;
  Button b_purchaseAmount(r_purchaseAmount, 50,30,224,224,224);
  b_purchaseAmount.setPos(110,302);
  
  triangleMinus.rotate(180);
  triangleMinus.setPosition(165,385);
  trianglePlus.setPosition(105,250);
  
  DisplayText plus_t("+", plus, 40);
  plus_t.setPos(125, 250);
  (plus_t.textObj).setFont(font);

  DisplayText minus_t("-", minus, 40);
  minus_t.setPos(125,330);
  (minus_t.textObj).setFont(font);

  DisplayText arrowAmount(std::to_string(purchaseAmount), purchaseAmount_text, 30);
  arrowAmount.setPos(120,298);
  (arrowAmount.textObj).setFont(font);


  // testing text input for login/logout etc etc etc
  sf::RectangleShape log_in_out;
  Button log_button(log_in_out, 300, 50, 0,0,0);
  log_button.setPos(350, 500);

  sf::Text logInOut;
  DisplayText log_text("***Please follow the instructions \n\tin the command terminal***", logInOut, 35);

  log_text.setPos(350,20);
  log_text.setColor(255,255,255);

  log_text.textObj.setOutlineColor(sf::Color(0,0,0));
  log_text.textObj.setOutlineThickness(5);

  (log_text.textObj).setFont(font);
		       
  
  // main loop
  while (window.isOpen())
    {
      //All events go here
      sf::Event event;
      while (window.pollEvent(event))
	{
	  // exit applet
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

	      // add bank button
	      if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= 140
		  && event.mouseButton.x <= 260 && event.mouseButton.y >= 170 && event.mouseButton.y <= 230)
		{
		  balance += purchaseAmount * 50;
		  balance_t.change_text(std::to_string(balance));
		  std::cout << balance << std::endl;
		}

	      // buy button
	      if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= 10
		  && event.mouseButton.x <= 130 && event.mouseButton.y >= 10 && event.mouseButton.y <= 70)
		{
		  balance -= purchaseAmount * 50;
		  balance_t.change_text(std::to_string(balance));
		  std :: cout << balance << std :: endl;
		}

	      // sell button
	      if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= 140
		  && event.mouseButton.x <= 260 && event.mouseButton.y >= 10 && event.mouseButton.y <= 70)
		{
		  balance += purchaseAmount * 1;
		  balance_t.change_text(std::to_string(balance));
		  std :: cout << "Sell Button clicked" << std :: endl;
		}

	      // buy order button
	      if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= 10
		  && event.mouseButton.x <= 130 && event.mouseButton.y >= 90 && event.mouseButton.y <= 150)
		{
		  std :: cout << " Buy Order set: need popup" << std :: endl;
		}

	      // sell order button
	      if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= 140
		  && event.mouseButton.x <= 260 && event.mouseButton.y >= 90 && event.mouseButton.y <= 150)
		{
		  std :: cout << "Sell Order set: needs popup" << std :: endl;
		}

	      // change user button
	      if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= 10
		  && event.mouseButton.x <= 130 && event.mouseButton.y >= 170 && event.mouseButton.y <= 230)
		{

		  if(usr_t.return_text() == "Login")
		    {
		      window.draw(log_text.textObj);
		      window.display();
		      std::string usr, pass; // only for testing
		      std :: cout << "Please enter your account name: " << std :: endl;
		      std :: cin >> usr;
		      std :: cout << "Please enter your password: " << std :: endl;
		      std :: cin >> pass;

		      std:: cout << "Usr: " << usr << " ... Pass: " << pass << std :: endl;
		      usr_t.change_text("Logout");
		      break;
		    }
		  if(usr_t.return_text() == "Logout")
		    {
		      usr_t.change_text("Login");
		      break;
		    }
		}
	      
	      // plus and minus arrow buttons
	      if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= 105
		  && event.mouseButton.x <= 170 && event.mouseButton.y >= 250 && event.mouseButton.y <= 295)
		{
		  purchaseAmount++;
		  arrowAmount.change_text(std::to_string(purchaseAmount));
		}

	      if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= 105
		  && event.mouseButton.x <= 170 && event.mouseButton.y >= 345 && event.mouseButton.y <= 385)
		{
		  if (purchaseAmount > 0){purchaseAmount--;}
		  arrowAmount.change_text(std::to_string(purchaseAmount));
		}   
	    }
	  
  
	} // end events

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
	window.draw(trianglePlus);
	window.draw(triangleMinus);
	window.draw(b_purchaseAmount.recB);
	window.draw(line_b1.recB);
	window.draw(line_b2.recB);
	window.draw(line_b3.recB);
	window.draw(line_b4.recB);
	window.draw(buy_list.recB);
	window.draw(sell_list.recB);
	window.draw(watch_line_b.recB);
	window.draw(current_user_b.recB);
	
	window.draw(text);
	window.draw(buy_t.textObj);
	window.draw(sell_t.textObj);
	window.draw(buyOrder_t.textObj);
	window.draw(sellOrder_t.textObj);
	window.draw(usr_t.textObj);
	window.draw(add_bank_t.textObj);
	window.draw(balance_t.textObj);
	window.draw(plus_t.textObj);
	window.draw(minus_t.textObj);
	window.draw(arrowAmount.textObj);
	window.draw(b_watch_display.textObj);
	window.draw(s_watch_display.textObj);
	window.draw(user_text.textObj);
	
	// text input
	//window.draw(log_button.recB);
	
	
	window.display();
    }

  return 0;
}
