#include <SFML/Graphics.hpp> // allows us to draw and update windows.
#include <SFML/Window/Mouse.hpp> // allows us to retrieve the mouse.
#include <iostream>
#include <ostream> // purely to use std::endl :)

double normalize(double mouseX, double maxWin);

int main( int argc, char** argv )
{
	sf::RenderWindow appWindow( sf::VideoMode( 800, 600, 32 ), "App" );
	sf::Event appEvent;
	
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

		// get location of mouse (x,y)
		sf::Vector2i position = sf::Mouse::getPosition(appWindow);
		
		
		// creates circle
		sf::CircleShape shape(50.0f);
		// set the shape color
		shape.setFillColor(sf::Color(normalize(position.y ,appWindow.getSize().y),
									 normalize(position.x ,appWindow.getSize().x), 
									 normalize((position.x + position.y) / 2, (appWindow.getSize().x + appWindow.getSize().y) / 2)));
		// set a 10-pixel wide orange outline
		shape.setOutlineThickness(10.f);
		shape.setOutlineColor(sf::Color(250, 150, 100));


		shape.move(position.x - circleRadius, position.y - circleRadius);

		// draws the circle shape we have created
		appWindow.draw(shape);

		// end the current frame
		appWindow.display();

		std::cout << position.x << " , " << position.y << std::endl;
	}
	
	return 0;
}

// I wanted to mess with colors here but was running into problems
// what I used to normalize https://stats.stackexchange.com/questions/70801/how-to-normalize-data-to-0-1-range
double normalize(double mouseX, double maxWin)
{
	double newValue = (mouseX - 0) / (maxWin - 0) * 255; // this will give me a value between (0 - 1) * 255 which will represent a value between [0, 255]
	return newValue;
}