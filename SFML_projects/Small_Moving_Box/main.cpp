#include <SFML/Graphics.hpp>
#include <SFML/Mouse.hpp>
#include <iostream>

int main( int argc, char** argv )
{
	sf::RenderWindow appWindow( sf::VideoMode( 800, 600, 32 ), "App" );
	sf::Event appEvent;
	
	int count = 1;

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

		// draws the circle shape we have created
		appWindow.draw(shape);

		sf::Vector2i position = sf::Mouse::getPosition();

		shape.move(position.x, position.y);

		// end the current frame
		appWindow.display();

		count++;
		std::cout << count << "\n";
	}
	
	return 0;
}