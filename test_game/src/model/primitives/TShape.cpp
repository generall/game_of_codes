/*
 * TShape.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#include "TShape.h"
#include <stdexcept>

namespace game
{

TShape::TShape()
{
	type = abstract;
	// TODO Auto-generated constructor stub

}

TShape::~TShape()
{
	// TODO Auto-generated destructor stub
}

point_2d TShape::getPoint()
{
	throw std::runtime_error("Not implemented");
	return std::make_pair(0,0); // default values
}


figure_type game::TShape::getType()
{
	return type;
}


void game::TShape::get_params(params &p)
{
	return ; // no params
}

void game::TShape::setPoint(const point_2d &pair)
{
	return ;
}

void TShape::setPoint(double x, double y)
{
	setPoint(std::make_pair(x,y));
}

} /* namespace game */


