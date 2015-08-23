/*
 * TShape.h
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#ifndef MODEL_TSHAPE_H_
#define MODEL_TSHAPE_H_

#include <vector>
#include <utility>

namespace game
{

typedef enum {
	abstract,
	point,
	line,
	rectangle,
	circle
} figure_type;

typedef std::vector<double> params;

typedef std::pair<double, double> point_2d;
/**
 * Base class, that provides interface to basic shapes.
 *
 */

class TShape
{

protected:
	figure_type type;
public:
	TShape();
	virtual ~TShape();

	virtual point_2d getPoint();
	virtual void setPoint(const point_2d&);
	virtual void setPoint(double x, double y);
	virtual figure_type getType();
	// assume that we use move semantic, so vector will not be copied
	virtual void get_params(params &p);

};

} /* namespace game */

#endif /* MODEL_TSHAPE_H_ */
