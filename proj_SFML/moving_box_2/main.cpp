// https://www.redblobgames.com/pathfinding/a-star/introduction.html

#include <SFML/Graphics.hpp> // allows us to draw and update windows.
#include <SFML/Window/Mouse.hpp> // allows us to retrieve the mouse.
#include <iostream> // output to console for random information for myself.
#include <ostream> // purely to use std::endl :)

using namespace std;

double decideMove(double mouseVal, double rectVal, int movement);
bool UpdateMethod(sf::Time elapsed, bool keepGoing);

sf::RenderWindow appWindow( sf::VideoMode( 800, 600, 32 ), "Moving Box" );
sf::Vector2i mousePos;

int movementRate = 10;

int main( int argc, char** argv )
{
	sf::Event appEvent;
	// runs the program as long as the window is open
	while ( appWindow.isOpen() )
	{
		while ( appWindow.pollEvent( appEvent ) )
		{
			if ( appEvent.type == sf::Event::Closed )
				appWindow.close();
		}

		double width = appWindow.getSize().x;
		
		sf::RectangleShape rectangle;
		sf::Color color(0,0,0);

		for(int i = 0; i < width / 100; i++)
		{

			rectangle.setSize(sf::Vector2f(100,100));
			rectangle.setFillColor(color);
		}

		
		mousePos = sf::Vector2i(50,50); //sf::Mouse::getPosition(appWindow);

		appWindow.display();
	}
	
	return 0;
}

sf::Color newColor(sf::Color color, int buffer)
{
	sf::Color returnColor(color.r + buffer,color.g + buffer,color.b + buffer);
	return returnColor;
}