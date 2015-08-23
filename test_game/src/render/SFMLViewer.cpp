/*
 * SFMLViewer.cpp
 *
 *  Created on: Aug 23, 2015
 *      Author: generall
 */

#include "SFMLViewer.h"
#include <math.h>


namespace game
{

SFMLViewer::SFMLViewer() :
		window(NULL)
{
	// TODO Auto-generated constructor stub

}

SFMLViewer::~SFMLViewer()
{
	if (window != NULL)
		delete window;
	// TODO Auto-generated destructor stub
}

view_state SFMLViewer::update()
{
	if (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
				return closed;
			}
		}

		window->clear();
		auto object_iterator = model->getObjectVector();
		for (auto obj : object_iterator)
		{
			auto shapes = obj->getShapes();
			for (auto shape : shapes)
			{
				figure_type ft = shape->getType();
				switch (ft)
				{
				case rectangle:
				{
					TRectangle *rec = static_cast<TRectangle*>(shape);
					point_2d point = rec->getPoint();

					//point.first = -point.first;
					point.second = -point.second;

					//std::cout << "point: " << point.first << " " << point.second << std::endl;
					sf::RectangleShape rectangle(
							sf::Vector2f(rec->getWidth(), rec->getHight()));

					double alpha = -rec->getAngle();

					double alpha_deg = alpha / RAD_TO_DEG_COEF;

					rectangle.setOrigin( rec->getWidth() / 2, rec->getHight() / 2 );

					rectangle.setRotation(alpha);

					rectangle.setPosition(point.first, point.second);
					rectangle.setFillColor(sf::Color(0, 0, 128, 125));
					rectangle.setOutlineThickness(-0.7);
					rectangle.setOutlineColor(sf::Color::White);

					sf::Vertex line[] =
					{
							sf::Vertex(sf::Vector2f(point.first, point.second)),
							sf::Vertex(sf::Vector2f(point.first + 10 * sin(alpha_deg), point.second + 10 * cos(PI - alpha_deg)))
					};

					sf::Vertex line2[] =
					{
							sf::Vertex(sf::Vector2f(point.first, point.second)),
							sf::Vertex(sf::Vector2f(point.first + 10 * cos(alpha_deg), point.second + 10 * sin(alpha_deg)))
					};

					line[0].color = sf::Color::Red;
					line[1].color = sf::Color::Red;

					line2[0].color = sf::Color::Green;
					line2[1].color = sf::Color::Green;

					window->draw(line, 2, sf::Lines);
					window->draw(line2, 2, sf::Lines);

					window->draw(rectangle);
					break;
				}
				default:
					break;
				}
			}
		}

		if(debug)
		{
			sf::Vertex line1[] =
			{
					sf::Vertex(sf::Vector2f(-200, 0)),
					sf::Vertex(sf::Vector2f(200, 0 ))
			};
			sf::Vertex line2[] =
			{
					sf::Vertex(sf::Vector2f(0, -200)),
					sf::Vertex(sf::Vector2f(0,  200))
			};

			line1[0].color = sf::Color::Red;
			line1[1].color = sf::Color::Blue;

			line2[0].color = sf::Color::Green;
			line2[1].color = sf::Color::Blue;

			window->draw(line1, 2, sf::Lines);
			window->draw(line2, 2, sf::Lines);
		}


		window->display();
	}
	else
	{
		return closed;
	}
	return working;
}

bool SFMLViewer::init()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window = new sf::RenderWindow(sf::VideoMode(400, 400), "Test view",
			sf::Style::Default, settings);
	window->setFramerateLimit(60);
	sf::View fixed = window->getView();
	fixed.setCenter(sf::Vector2f(0, 0));
	fixed.zoom(0.1);

	window->setView(fixed);

	// init of window and other render stuff here
	return true;
}

} /* namespace game */
