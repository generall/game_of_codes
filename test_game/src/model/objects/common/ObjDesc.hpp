/*
 * ObjDesc.hpp
 *
 *  Created on: 2 сент. 2015 г.
 *      Author: generall
 */

#ifndef MODEL_OBJECTS_COMMON_OBJDESC_HPP_
#define MODEL_OBJECTS_COMMON_OBJDESC_HPP_

#define RAD_TO_DEG_COEF 57.295780490442965
#define PI 3.1415926

namespace game
{

struct Point2D
{
	Point2D(double _x, double _y):x(_x),y(_y){}
	double x, y;
};

struct TObjectSt
{
	double x, y;
	double angle; // current angle relative to World [updateable]
	double d_angle; // angle relative to body
};

struct BoxSt: public TObjectSt
{
	double width, height;
};

struct PolygonSt: public TObjectSt
{
	std::vector<Point2D> points;
};

struct ComposedSt
{
	std::vector<BoxSt> boxes;
	std::vector<PolygonSt> polygons;
};

}
;

#endif /* MODEL_OBJECTS_COMMON_OBJDESC_HPP_ */
