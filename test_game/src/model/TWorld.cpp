/*
 * TWorld.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#include "TWorld.h"

namespace game
{

TWorld::TWorld()
{
	// TODO Auto-generated constructor stub

}

TWorld::~TWorld()
{
	for(auto x: this->objects)
	{
		delete x;
	}
}

std::vector<TObject*>& TWorld::getObjectVector()
{
	return objects;
}

void TWorld::createUniverse()
{
	this->objects.push_back(new TBox());
}

void TWorld::tick()
{
	return;
}


} /* namespace game */

