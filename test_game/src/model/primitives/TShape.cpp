/*
 * TShape.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#include "TShape.h"

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


} /* namespace game */
