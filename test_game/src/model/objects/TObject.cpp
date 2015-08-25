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
	type = abstract_obj;
	// TODO Auto-generated constructor stub
}

TObject::~TObject()
{
	// TODO Auto-generated destructor stub
}

void TObject::update()
{
	return ;
}

const void* TObject::getStructure()
{
	return 0;
}

} /* namespace game */


