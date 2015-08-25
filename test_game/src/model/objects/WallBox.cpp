/*
 * WallBox.cpp
 *
 *  Created on: Aug 23, 2015
 *      Author: generall
 */

#include "WallBox.h"

namespace game
{

WallBox::WallBox(b2World *world, double width, double height)
{
	groundBodyDef.position.Set(0.0f, -10.0f);
	groundBody = world->CreateBody(&groundBodyDef);
	groundBox.SetAsBox(width, height);
	groundBody->CreateFixture(&groundBox, 0.0f);

	data.height = height * 2;
	data.width = width * 2;

	data.x = 0.0;
	data.y = -10.0;

	// TODO Auto-generated constructor stub

}

WallBox::~WallBox()
{

	// TODO Auto-generated destructor stub
}

void WallBox::setPosition(double x, double y)
{
	groundBody->SetTransform(b2Vec2(x,y),groundBody->GetAngle());
}

void WallBox::setAngelD(double angle)
{
	TBox::setAngelD(angle);
	groundBody->SetTransform(b2Vec2(data.x,data.y),data.angle);
}

void WallBox::setAngelR(double angle)
{
	TBox::setAngelR(angle);
	groundBody->SetTransform(b2Vec2(data.x,data.y),data.angle);
}

void WallBox::setSize(double width, double height)
{
}

} /* namespace game */
