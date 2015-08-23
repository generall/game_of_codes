/*
 * TRectangle.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#include "TRectangle.h"

namespace game
{

TRectangle::TRectangle()
{
	x = 0;
	y = 0;
	hight = 10; // px
	width = 10; // px
	type = rectangle;
	angle = 0;
}

TRectangle::~TRectangle()
{
	// TODO Auto-generated destructor stub
}

point_2d TRectangle::getPoint()
{
	return std::make_pair(x,y);
}

void TRectangle::setPoint(const point_2d& p)
{
	x = p.first;
	y = p.second;
}

void TRectangle::get_params(params &p)
{
	p.push_back(hight);
	p.push_back(width);
}

} /* namespace game */
