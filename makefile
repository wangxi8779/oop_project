stock_app:
	@g++ -c mainSFML.cpp Button.h Button.cpp DisplayText.h DisplayText.cpp Account.h Account.cpp Admin.h Admin.cpp Member.h Member.cpp Trader.h Trader.cpp Stock.h\
 Stock.cpp Order.h Order.cpp LimitOrder.h LimitOrder.cpp MarketOrder.h MarketOrder.cpp Transaction.h Transaction.cpp Watchlist.h Watchlist.cpp StockPortfolio.h StockPortf\
olio.cpp StockMarket.h StockMarket.cpp -I /home/admir/sfml/SFML-2.5.1/include & export LD_LIBRARY_PATH=/home/admir/sfml/SFML-2.5.1/lib && ./sfml-app & g++ mainSFML.o Button.o DisplayText.o Account.o Admin.o Member.o Trader.o Stock.o Order.\
o LimitOrder.o MarketOrder.o Transaction.o Watchlist.o StockPortfolio.o StockMarket.o -o sfml-app -L/home/admir/sfml/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml\
-system
