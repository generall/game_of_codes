/*
 * SFMLViewer.h
 *
 *  Created on: Aug 23, 2015
 *      Author: generall
 */

#ifndef RENDER_SFMLVIEWER_H_
#define RENDER_SFMLVIEWER_H_

#include "viewer.h"
#include <iostream>

namespace game
{

class SFMLViewer: public viewer
{
protected:
	 sf::RenderWindow *window;

public:
	SFMLViewer();
	virtual ~SFMLViewer();
	virtual view_state update();
	virtual bool init();

};

} /* namespace game */

#endif /* RENDER_SFMLVIEWER_H_ */
