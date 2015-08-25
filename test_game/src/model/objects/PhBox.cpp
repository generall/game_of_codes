/*
 * PhBox.cpp
 *
 *  Created on: Aug 23, 2015
 *      Author: generall
 */

#include "PhBox.h"

namespace game
{

PhBox::PhBox(b2World *world, double width, double height)
{
	// Define the dynamic body. We set its position and call the body factory.
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 100 );
	body = world->CreateBody(&bodyDef);

	// Define another box shape for our dynamic body.

	dynamicBox.SetAsBox(width, height);

	data.height = height * 2;
	data.width = width * 2;

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
	data.angle = body->GetAngle();

	//rec->setAngle(body->GetAngle() * 57.295780490442965);
	b2Vec2 position = body->GetPosition();
	//b2Vec2 vv = body->GetWorldVector( b2Vec2( 1, 1 ) );
	data.x = position.x;
	data.y = position.y;
}

void PhBox::setPosition(double x, double y)
{
	body->SetTransform(b2Vec2(x,y),body->GetAngle());
}

void PhBox::setAngelD(double angle)
{
	TBox::setAngelD(angle);
	body->SetTransform(b2Vec2(data.x,data.y),data.angle);
}

void PhBox::setAngelR(double angle)
{
	TBox::setAngelR(angle);
	body->SetTransform(b2Vec2(data.x,data.y),data.angle);
}

void PhBox::setSize(double width, double height)
{

}

} /* namespace game */
