// https://www.redblobgames.com/pathfinding/a-star/introduction.html

#include <SFML/Graphics.hpp> // allows us to draw and update windows.
#include <SFML/Window/Mouse.hpp> // allows us to retrieve the mouse.
#include <iostream> // output to console for random information for myself.
#include <ostream> // purely to use std::endl :)
#include <vector> 
#include <SFML/Graphics/Vertex.hpp>
#include <math.h>

using namespace std;

double decideMove(double mouseVal, double rectVal, int movement);
bool UpdateMethod(sf::Time elapsed, bool keepGoing);

sf::RenderWindow appWindow( sf::VideoMode( 800, 600, 32 ), "Moving Box" );
sf::Vector2i mousePos;

int movementRate = 10;

int main( int argc, char** argv )
{
	sf::Clock clock;
	sf::VertexArray vertices(sf::LinesStrip, 3);
	sf::Event appEvent;
	
	sf::Vertex firstVertex;
	int count = 0;
	double circleRadius = 50.0f;

	bool restart = false;

	// runs the program as long as the window is open
	while ( appWindow.isOpen() )
	{
		while ( appWindow.pollEvent( appEvent ) )
		{
			if ( appEvent.type == sf::Event::Closed )
				appWindow.close();
		}
		
		sf::Time elapsed = clock.getElapsedTime();
		mousePos = sf::Vector2i(50,50); //sf::Mouse::getPosition(appWindow);

		restart = UpdateMethod(elapsed, restart);
	}
	
	return 0;
}

bool UpdateMethod(sf::Time elapsed, bool keepGoing)
{
	sf::RectangleShape rectangle;

	rectangle.setSize(sf::Vector2f(50,50));

	rectangle.setFillColor(sf::Color(100,100,100));

	double xValue;
	double yValue;

	// // rectangle AI!
	// if(rectangle.getPosition().x != mousePos.x)
	// {
	// 	//xValue = decideMove(mousePos.x, rectangle.getPosition().x, movementRate);
	// 	rectangle.move(decideMove(mousePos.x, rectangle.getPosition().x, elapsed.asSeconds() * movementRate), 
	// 				   rectangle.getPosition().y );
	// }

	if( ceil(elapsed.asSeconds()) * movementRate != ceil(mousePos.x) && !keepGoing)
	{	
		rectangle.move(decideMove(mousePos.y ,rectangle.getPosition().y, ceil(elapsed.asSeconds() * movementRate) ) , 
					   rectangle.getPosition().y);
	}
	else
	{
		keepGoing = true;
	}
	
	if( ceil(elapsed.asSeconds()) * movementRate != ceil(mousePos.y) && !keepGoing)
	{	
		rectangle.move(rectangle.getPosition().x , 
					   decideMove(mousePos.y ,rectangle.getPosition().y, ceil(elapsed.asSeconds() * movementRate) ));
	}
	else
	{
		keepGoing = true;
	}
	
	rectangle.getTransform();

	// appWindow.clear(sf::Color::Black);

	appWindow.draw(rectangle);

	appWindow.display();
	std::cout << elapsed.asSeconds() * movementRate << ":" << mousePos.x << " - " << ceil(elapsed.asSeconds() * movementRate) << ":" << ceil(mousePos.y) << endl;

	return keepGoing;
}

double decideMove(double mouseVal, double rectVal, int movement)
{
	double value = rectVal;

	if(mouseVal > rectVal)
		value = value + movement;
	else
		value = value - movement;	
	
	return value;
}
