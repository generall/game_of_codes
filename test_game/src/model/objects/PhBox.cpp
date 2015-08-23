/*
 * PhBox.cpp
 *
 *  Created on: Aug 23, 2015
 *      Author: generall
 */

#include "PhBox.h"

namespace game
{

PhBox::PhBox(b2World *world)
{
	// Define the dynamic body. We set its position and call the body factory.

	float width = 1.0;
	float hight = 1.0;

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 100 );
	body = world->CreateBody(&bodyDef);

	// Define another box shape for our dynamic body.

	dynamicBox.SetAsBox(width, hight);

	rec->setWidth(width * 2);
	rec->setHight(hight * 2);

	// Define the dynamic body fixture.

	fixtureDef.shape = &dynamicBox;

	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;

	// Override the default friction.
	fixtureDef.friction = 0.3f;

	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);

	// TODO Auto-generated constructor stub

}

PhBox::~PhBox()
{
	// TODO Auto-generated destructor stub
}

void PhBox::update()
{
	rec->setAngle(body->GetAngle() * 57.295780490442965);
	b2Vec2 position = body->GetPosition();
	//b2Vec2 vv = body->GetWorldVector( b2Vec2( 1, 1 ) );
	rec->setPoint(position.x , position.y);
}

void PhBox::setPosition(double x, double y)
{
	body->SetTransform(b2Vec2(x,y),body->GetAngle());
}

} /* namespace game */
