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
	bool init();
	bool update();
	bool render_rectangle(double x, double y, double h, double w );
	bool render_line(double x1, double y1, double x2,  double y2 );
};

} /* namespace game */

#endif /* RENDER_VIEWER_H_ */
