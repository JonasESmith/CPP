#include <SFML/Graphics.hpp> // allows us to draw and update windows.
#include <SFML/Window/Mouse.hpp> // allows us to retrieve the mouse.
#include <iostream> // output to console for random information for myself.
#include <ostream> // purely to use std::endl :)
#include <vector>
#include <SFML/Graphics/Vertex.hpp>

using namespace std;

double decideMove(double mouseVal, double rectVal, int movement);
void UpdateMethod(sf::Time elapsed);

sf::RenderWindow appWindow( sf::VideoMode( 800, 600, 32 ), "Moving Box" );
sf::Vector2i mousePos;

int main( int argc, char** argv )
{
	sf::VertexArray vertices(sf::LinesStrip, 3);
	sf::Event appEvent;
	
	sf::Vertex firstVertex;
	int count = 0;
	double circleRadius = 50.0f;

	sf::Clock clock;

	// runs the program as long as the window is open
	while ( appWindow.isOpen() )
	{
		while ( appWindow.pollEvent( appEvent ) )
		{
			if ( appEvent.type == sf::Event::Closed )
				appWindow.close();
		}
		
		sf::Time elapsed = clock.getElapsedTime();
		mousePos = sf::Mouse::getPosition(appWindow);

		UpdateMethod(elapsed);

		mousePos.x = 0; 
		mousePos.y = 0;
	}
	
	return 0;
}

void UpdateMethod(sf::Time elapsed)
{
	int movementRate = 1;

	sf::RectangleShape rectangle;

	rectangle.setSize(sf::Vector2f(50,50));

	rectangle.setFillColor(sf::Color(100,100,100));

	double xValue;
	double yValue;

	// rectangle AI!
	if(rectangle.getPosition().x != mousePos.x)
	{
		xValue = rectangle.getPosition().x;

		//xValue = decideMove(mousePos.x, rectangle.getPosition().x, movementRate);
		rectangle.move(decideMove(mousePos.x, rectangle.getPosition().x, elapsed.asSeconds() * movementRate), 
					   rectangle.getPosition().y );
		rectangle.setPosition(decideMove(mousePos.x, rectangle.getPosition().x, elapsed.asSeconds() * movementRate), 
					   rectangle.getPosition().y );
	}

	if(rectangle.getPosition().y != mousePos.y)
	{
		rectangle.move(rectangle.getPosition().x , 
					   decideMove(mousePos.y ,rectangle.getPosition().y, elapsed.asSeconds() * movementRate));
		rectangle.setPosition(rectangle.getPosition().x , 
					   decideMove(mousePos.y ,rectangle.getPosition().y, elapsed.asSeconds() * movementRate));	   
	}

	appWindow.clear(sf::Color::Black);

	appWindow.draw(rectangle);

	appWindow.display();
	std::cout << rectangle.getPosition().x << ":" << mousePos.x << " - " << rectangle.getPosition().y << ":" << mousePos.y << endl;
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
