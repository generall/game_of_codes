/*
 * SFMLViewer.cpp
 *
 *  Created on: Aug 23, 2015
 *      Author: generall
 */

#include "SFMLViewer.h"

namespace game
{

SFMLViewer::SFMLViewer(): window(NULL)
{
	// TODO Auto-generated constructor stub

}

SFMLViewer::~SFMLViewer()
{
	if(window != NULL)
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
						TRectangle *rec = static_cast<TRectangle*>(shape) ;
						point_2d point = rec->getPoint();
						//std::cout << "point: " << point.first << " " << point.second << std::endl;
						sf::RectangleShape rectangle(sf::Vector2f(rec->getWidth(), rec->getHight()));
						rectangle.setRotation(rec->getAngle());

						rectangle.setPosition(point.first, point.second);
						rectangle.setFillColor(sf::Color(0,0,128,125));
						rectangle.setOutlineThickness(1);
						rectangle.setOutlineColor(sf::Color::White);

						window->draw(rectangle);
						break;
					}
					default:
						break;
					}
				}
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

	window = new sf::RenderWindow(sf::VideoMode(200, 200), "Test view",sf::Style::Default, settings);
	window->setFramerateLimit(60);
	sf::View fixed = window->getView();
	fixed.setCenter(sf::Vector2f(0,0));
	window->setView(fixed);

	// init of window and other render stuff here
	return true;
}

} /* namespace game */
