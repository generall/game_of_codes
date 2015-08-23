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
	double angle;
public:
	TRectangle();
	virtual ~TRectangle();
	virtual point_2d getPoint();
	virtual void setPoint(const point_2d &p);
	virtual void get_params(params &p);
	using TShape::setPoint;

	double getHight() const
	{
		return hight;
	}

	void setHight(double hight)
	{
		this->hight = hight;
	}

	double getWidth() const
	{
		return width;
	}

	void setWidth(double width)
	{
		this->width = width;
	}

	double getAngle() const
	{
		return angle;
	}

	void setAngle(double angle)
	{
		this->angle = angle;
	}
};

} /* namespace game */

#endif /* MODEL_PRIMITIVES_TRECTANGLE_H_ */
