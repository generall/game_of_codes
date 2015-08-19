/*
 * viewer.h
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#ifndef RENDER_VIEWER_H_
#define RENDER_VIEWER_H_

#include <SFML/Graphics.hpp>
#include "../model/TWorld.h"


namespace game
{

typedef enum {
	working,
	closed,
	stoped
} view_state;

/**
 * Base class for rendering the world
 */

class viewer
{

	TWorld *model;

	 sf::RenderWindow *window;

public:
	viewer();
	virtual ~viewer();
	virtual bool init();
	virtual void setModel(TWorld * _model);
	virtual view_state update();
};

} /* namespace game */

#endif /* RENDER_VIEWER_H_ */
