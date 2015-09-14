/*
 * TLoader.cpp
 *
 *  Created on: 2 сент. 2015 г.
 *      Author: generall
 */

#include "TLoader.h"

namespace game
{

TLoader::TLoader()
{
	// TODO Auto-generated constructor stub

}

TLoader::~TLoader()
{
	// TODO Auto-generated destructor stub
}

} /* namespace game */

bool game::TLoader::loadBox(b2PolygonShape* polygon, b2FixtureDef* fixture,
		BoxSt* box)
{
	return false;
}

bool game::TLoader::loadComposed(b2Body* body,
		std::vector<b2PolygonShape*>& dynamicBox_vector,
		std::vector<b2PolygonShape*>& dynamicPoly_vector,
		std::vector<b2FixtureDef*>& fixtureDef_vector, ComposedSt& c_data)
{
	return false; // fail everytime
}
