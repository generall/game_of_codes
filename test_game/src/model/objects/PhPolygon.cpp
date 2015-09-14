/*
 * PhPolygon.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: generall
 */

#include "PhPolygon.h"

namespace game
{

PhPolygon::PhPolygon(b2World *world, std::vector<Point2D> &points)
{
	// Define the dynamic body. We set its position and call the body factory.
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 100 );
	body = world->CreateBody(&bodyDef);

	// Define another box shape for our dynamic body.

	/*
	 * Creation of polygon here
	 */

	vertices = new b2Vec2[points.size()];
	b2Vec2 *curr = vertices;

	for(Point2D pt: points){
		curr->x = pt.x;
		curr->y = pt.y;
		curr++;
	}

	setPoints(points);

	dynamicBox.Set(vertices, points.size());

	// Define the dynamic body fixture.

	fixtureDef.shape = &dynamicBox;

	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;

	// Override the default friction.
	fixtureDef.friction = 0.3f;

	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);

}

PhPolygon::~PhPolygon()
{
	if(vertices != NULL)
		delete []vertices;
}

void PhPolygon::update()
{
	data.angle = body->GetAngle();
	b2Vec2 position = body->GetPosition();
	data.x = position.x;
	data.y = position.y;
}

void PhPolygon::setPosition(double x, double y)
{
	body->SetTransform(b2Vec2(x,y),body->GetAngle());
}

void PhPolygon::setAngelD(double angle)
{
	TPolygon::setAngelD(angle);
	body->SetTransform(b2Vec2(data.x,data.y),data.angle);
}

void PhPolygon::setAngelR(double angle)
{
	TPolygon::setAngelR(angle);
	body->SetTransform(b2Vec2(data.x,data.y),data.angle);
}

}
