/*
 * TRectangle.h
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#ifndef MODEL_PRIMITIVES_TRECTANGLE_H_
#define MODEL_PRIMITIVES_TRECTANGLE_H_

#include "TShape.h"

namespace game
{


/**
 * Rectangle class. Provides representation of rectangle for render & modeling.
 */

class TRectangle: public TShape
{

	double x, y, hight, width;
public:
	TRectangle();
	virtual ~TRectangle();
	virtual point_2d getPoint();
	virtual void get_params(params &p);

};

} /* namespace game */

#endif /* MODEL_PRIMITIVES_TRECTANGLE_H_ */
