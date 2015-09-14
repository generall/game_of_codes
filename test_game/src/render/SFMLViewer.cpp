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

		/*
		 * Implementation of Z-ordering.
		 * Add vectors ov ordering of objects to draw.
		 */

		window->clear();
		auto object_iterator = model->getObjectVector();
		for (auto obj : object_iterator)
		{
			obj_type ft = obj->getType();
			switch (ft)
			{
			case box:
			{
				const BoxSt *data = (const BoxSt *)obj->getStructure();

				render_box(*data, 0);

				break;
			}
			case polygon:
			{
				const PolygonSt *data = (const PolygonSt *)obj->getStructure();

				render_poly(*data, 0);

				break;
			}
			case composed_boxes:
			{
				const ComposedSt *data = (const ComposedSt *)obj->getStructure();

				for(auto &x:data->boxes )
				{
					render_box(x, 0);
				}

				for(auto &x:data->polygons)
				{
					render_poly(x, 0);
				}

				break;
			}
			default:
				break;
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

		draw_layers();

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

void SFMLViewer::render_poly(const PolygonSt& data, int z)
{
	sf::ConvexShape *polygon = new sf::ConvexShape();

	size_t p_count = data.points.size();

	polygon->setPointCount(p_count);

	for(size_t i = 0; i < p_count; i++)
	{
		sf::Vector2f v2(data.points[i].x, -data.points[i].y);
		polygon->setPoint(i, v2);
	}

	double alpha = -data.angle;

	double alpha_deg = alpha * RAD_TO_DEG_COEF;

	double x = data.x;
	double y = -data.y;

	polygon->setRotation(alpha_deg);

	polygon->setPosition(x, y);
	polygon->setFillColor(sf::Color(0, 0, 128, 125));
	polygon->setOutlineThickness(-0.05);
	polygon->setOutlineColor(sf::Color::White);

	/**
	 * DEBUG LINES OF ORIENTATION
	 */

	sf::Vertex *line1 = new sf::Vertex[2];
	sf::Vertex *line2 = new sf::Vertex[2];

	line1[0] = sf::Vertex(sf::Vector2f(x, y));
	line1[1] = sf::Vertex(sf::Vector2f(x + 10 * sin(alpha), y + 10 * cos(PI - alpha)));

	line2[0] = sf::Vertex(sf::Vector2f(x, y));
	line2[1] = sf::Vertex(sf::Vector2f(x + 10 * cos(alpha), y + 10 * sin(alpha)));


	line1[0].color = sf::Color::Red;
	line1[1].color = sf::Color::Red;

	line2[0].color = sf::Color::Green;
	line2[1].color = sf::Color::Green;

	poly_layers[z].push_back(polygon);
	vert_layers[z + 1].push_back( make_pair(2 , line1) );
	vert_layers[z + 1].push_back( make_pair(2 , line2) );

	layers_indexes.insert(z);
	layers_indexes.insert(z + 1);

}

void SFMLViewer::render_box(const BoxSt &data, int z)
{
	sf::RectangleShape *rectangle = new sf::RectangleShape(
			sf::Vector2f(data.width, data.height));

	double alpha = -data.angle;

	double alpha_deg = alpha * RAD_TO_DEG_COEF;

	double x = data.x;
	double y = -data.y;

	rectangle->setOrigin( data.width / 2, data.height / 2 );

	rectangle->setRotation(alpha_deg);

	rectangle->setPosition(x, y);
	rectangle->setFillColor(sf::Color(0, 0, 128, 125));
	rectangle->setOutlineThickness(-0.3);
	rectangle->setOutlineColor(sf::Color::White);

	sf::Vertex *line1 = new sf::Vertex[2];
	sf::Vertex *line2 = new sf::Vertex[2];

	line1[0] = sf::Vertex(sf::Vector2f(x, y));
	line1[1] = sf::Vertex(sf::Vector2f(x + 10 * sin(alpha), y + 10 * cos(PI - alpha)));

	line2[0] = sf::Vertex(sf::Vector2f(x, y));
	line2[1] = sf::Vertex(sf::Vector2f(x + 10 * cos(alpha), y + 10 * sin(alpha)));


	line1[0].color = sf::Color::Red;
	line1[1].color = sf::Color::Red;

	line2[0].color = sf::Color::Green;
	line2[1].color = sf::Color::Green;

	rect_layers[z].push_back(rectangle);
	vert_layers[z + 1].push_back( make_pair(2 , line1) );
	vert_layers[z + 1].push_back( make_pair(2 , line2) );

	layers_indexes.insert(z);
	layers_indexes.insert(z + 1);
}

void SFMLViewer::draw_layers()
{
	for(int z: layers_indexes)
	{
		for(auto x: rect_layers[z])
		{
			window->draw(*x);
		}

		for(auto x: poly_layers[z])
		{
			window->draw(*x);
		}

		for(auto x: vert_layers[z])
		{
			window->draw(x.second, x.first, sf::Lines);
		}
	}
	free_layers();
}

void SFMLViewer::free_layers()
{
	for(int z: layers_indexes)
	{
		for(auto x: rect_layers[z])
		{
			delete x;
		}

		for(auto x: vert_layers[z])
		{
			delete []x.second;
		}
	}
	rect_layers.clear();
	poly_layers.clear();
	vert_layers.clear();
	layers_indexes.clear();
}

} /* namespace game */


