/*
 * viewer.h
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#ifndef RENDER_VIEWER_H_
#define RENDER_VIEWER_H_

namespace game
{

/**
 * Base class for rendering the world
 */

class viewer
{
public:
	viewer();
	virtual ~viewer();
	void render();
	bool init();
};

} /* namespace game */

#endif /* RENDER_VIEWER_H_ */
