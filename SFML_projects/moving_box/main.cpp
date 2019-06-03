#include <SFML/Graphics.hpp> // allows us to draw and update windows.
#include <SFML/Window/Mouse.hpp> // allows us to retrieve the mouse.
#include <iostream> // output to console for random information for myself.
#include <ostream> // purely to use std::endl :)
#include <vector>
#include <SFML/Graphics/Vertex.hpp>

using namespace std;


void updateGame(sf::Time elapsed);
sf::RenderWindow appWindow( sf::VideoMode( 800, 600, 32 ), "Weird Drawing" );

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
		
		sf::Time elapsed = clock.restart();

		updateGame(elapsed);
	}
	
	return 0;
}

void updateGame(sf::Time elapsed)
{
	sf::RectangleShape rectangle;

	rectangle.setSize(sf::Vector2f(50,50));

	rectangle.setFillColor(sf::Color(100,100,100));

	rectangle.move(100 + elapsed.asSeconds(), 100 + elapsed.asSeconds());

	appWindow.draw(rectangle);

	appWindow.display();
	std::cout << "What up pimp : " << elapsed.asSeconds() << endl;
}
