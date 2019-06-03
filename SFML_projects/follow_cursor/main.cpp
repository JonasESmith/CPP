#include <SFML/Graphics.hpp> // allows us to draw and update windows.
#include <SFML/Window/Mouse.hpp> // allows us to retrieve the mouse.
#include <iostream>
#include <ostream> // purely to use std::endl :)

int main( int argc, char** argv )
{
	sf::RenderWindow appWindow( sf::VideoMode( 800, 600, 32 ), "App" );
	sf::Event appEvent;
	
	int count = 1;
	double circleRadius = 50.0f;

	// runs the program as long as the window is open
	while ( appWindow.isOpen() )
	{
		while ( appWindow.pollEvent( appEvent ) )
		{
			if ( appEvent.type == sf::Event::Closed )
				appWindow.close();
		}
		
		// clears the window with a black color
		appWindow.clear(sf::Color::Black);

		// creates circle
		sf::CircleShape shape(50.0f);

		// set the shape of the color to green
		shape.setFillColor(sf::Color(150, 50, 250));

		// set a 10-pixel wide orange outline
		shape.setOutlineThickness(10.f);
		shape.setOutlineColor(sf::Color(250, 150, 100));


		sf::Vector2i position = sf::Mouse::getPosition(appWindow);

		shape.move(position.x - circleRadius, position.y - circleRadius);

		// draws the circle shape we have created
		appWindow.draw(shape);

		// end the current frame
		appWindow.display();

		count;
		std::cout << position.x << " , " << position.y << std::endl;
	}
	
	return 0;
}