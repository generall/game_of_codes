/*
 * WallBox.cpp
 *
 *  Created on: Aug 23, 2015
 *      Author: generall
 */

#include "WallBox.h"

namespace game
{

WallBox::WallBox(b2World *world)
{

	float width = 50.0f;
	float hight = 10.0f;

	groundBodyDef.position.Set(0.0f, -10.0f);
	groundBody = world->CreateBody(&groundBodyDef);
	groundBox.SetAsBox(width, hight);
	groundBody->CreateFixture(&groundBox, 0.0f);

	rec->setPoint(0.0, -10.0);
	rec->setHight( hight * 2 );
	rec->setWidth( width);

	// TODO Auto-generated constructor stub

}

WallBox::~WallBox()
{

	// TODO Auto-generated destructor stub
}

} /* namespace game */
