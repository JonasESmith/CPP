#include <SFML/Graphics.hpp> // allows us to draw and update windows.
#include <SFML/Window/Mouse.hpp> // allows us to retrieve the mouse.
#include <iostream> // output to console for random information for myself.
#include <ostream> // purely to use std::endl :)
#include <vector>
#include <SFML/Graphics/Vertex.hpp>

using namespace std;

double normalize(double mouseX, double maxWin);

sf::VertexArray vertices(sf::LinesStrip, 3);

int main( int argc, char** argv )
{
	sf::RenderWindow appWindow( sf::VideoMode( 800, 600, 32 ), "Weird Drawing" );
	sf::Event appEvent;
	
	sf::Vertex firstVertex;
	int count = 0;
	double circleRadius = 50.0f;

	// runs the program as long as the window is open
	while ( appWindow.isOpen() )
	{
		while ( appWindow.pollEvent( appEvent ) )
		{
			if ( appEvent.type == sf::Event::Closed )
				appWindow.close();
		}
		
		if(count == 0)
		{
			appWindow.clear(sf::Color::White);
		}

		if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			vertices.clear();
			appWindow.clear(sf::Color::White);
		}

		// get location of mouse (x,y)
			sf::Vector2i position = sf::Mouse::getPosition(appWindow);
		
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{	
			count++;

			sf::CircleShape point(1.5f);

			point.setFillColor(sf::Color::Red);
			point.move(position.x, position.y);

			appWindow.draw(point);

			firstVertex.position.x = position.x;
			firstVertex.position.y = position.y;

			vertices.append(firstVertex);
			vertices[vertices.getVertexCount() - 9].color = sf::Color::Black;
		}

		sf::VertexArray lines(sf::LineStrip, vertices.getVertexCount());

		for(int i = 0; i < vertices.getVertexCount(); i++)
		{
			lines[i].position = vertices[i].position;
			lines[i].color = vertices[i].color;
		}

		appWindow.draw(lines);


		// end the current frame
		appWindow.display();

		std::cout << position.x << " , " << position.y << " - " << vertices.getVertexCount() << " - " << vertices[vertices.getVertexCount()].position.x << std::endl;
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