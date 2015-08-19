/*
 * viewer.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#include "viewer.h"

namespace game
{

viewer::viewer():
		model(NULL),
		window(NULL)
{

	// TODO Auto-generated constructor stub

}

viewer::~viewer()
{
	if(window != NULL)
		delete window;
	// TODO Auto-generated destructor stub
}

bool viewer::init()
{
	window = new sf::RenderWindow(sf::VideoMode(200, 200), "Test view");
	// init of window and other render stuff here
	return true;
}

void viewer::setModel(TWorld* _model)
{
	model = _model;
}

view_state viewer::update()
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
        for(auto obj: object_iterator)
        {
        	auto shapes = obj->getShapes();
        	for(auto shape: shapes)
        	{
        		figure_type ft = shape->getType();
        		switch(ft)
        		{
        		case rectangle:
        		{
        			point_2d point = shape->getPoint();
        			params r_params;
        			shape->get_params(r_params);
        			sf::RectangleShape rectangle(sf::Vector2f(point.first, point.second));
        			rectangle.setSize(sf::Vector2f(r_params[0], r_params[1]));

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
    }else{
    	return closed;
    }
    return working;
}


} /* namespace game */
