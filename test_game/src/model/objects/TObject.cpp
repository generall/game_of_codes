/*
 * TObject.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#include "TObject.h"

namespace game
{

TObject::TObject()
{
	// TODO Auto-generated constructor stub

}

TObject::~TObject()
{
	// TODO Auto-generated destructor stub
}

std::vector<TShape*>& TObject::getShapes()
{
	return shapes;
}

void TObject::update()
{
	return ;
}


} /* namespace game */

