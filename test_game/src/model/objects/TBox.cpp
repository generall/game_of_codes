/*
 * TBox.cpp
 *
 *  Created on: Aug 19, 2015
 *      Author: generall
 */

#include "TBox.h"

namespace game
{

TBox::TBox()
{
	type = obj_type::box;
}

TBox::~TBox()
{
	// TODO Auto-generated destructor stub
}

void TBox::setPosition(double x, double y)
{
	data.x = x;
	data.y = y;
}

void TBox::setAngelD(double angle)
{
	data.angle = angle / RAD_TO_DEG_COEF;
}

void TBox::setAngelR(double angle)
{
	data.angle = angle;
}

void TBox::setSize(double width, double height)
{
	data.width = width;
	data.height = height;
}

const void* TBox::getStructure()
{
	return &data;
}

} /* namespace game */
