/*
 * TPolygon.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: generall
 */

#include "TPolygon.h"


namespace game
{


TPolygon::TPolygon()
{
	type = obj_type::polygon;
}

TPolygon::~TPolygon()
{
	// TODO Auto-generated destructor stub
}

void TPolygon::setPosition(double x, double y)
{
	data.x = x;
	data.y = y;
}

void TPolygon::setAngelD(double angle)
{
	data.angle = angle / RAD_TO_DEG_COEF;
}

void TPolygon::setAngelR(double angle)
{
	data.angle = angle;
}

void TPolygon::setPoints(std::vector<Point2D>& points)
{
	data.points = points;
}

const void* TPolygon::getStructure()
{
	return &data;
}

}
