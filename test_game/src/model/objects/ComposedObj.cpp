/*
 * ComposedObj.cpp
 *
 *  Created on: 30 авг. 2015 г.
 *      Author: generall
 */

#include "ComposedObj.h"

namespace game
{

ComposedObj::ComposedObj(b2World *world)
{
	type = composed_boxes;
	double width  = 1.0;
	double height = 1.0;

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(-1.0f, 150 );
	body = world->CreateBody(&bodyDef);

	// Define another box shape for our dynamic body.


	dynamicBox.SetAsBox(width, height);
	dynamicBox2.SetAsBox(width, height, b2Vec2(-2, -0.9), 45 / RAD_TO_DEG_COEF );


	BoxSt data;
	data.height = height * 2;
	data.width = width * 2;

	BoxSt data2;
	data2.height = height * 2;
	data2.width = width * 2;

	c_data.boxes.push_back(data);
	c_data.boxes.push_back(data2);

	// Define the dynamic body fixture

	fixtureDef.shape = &dynamicBox;
	fixtureDef2.shape = &dynamicBox2;


	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef2.density = 1.0f;
	fixtureDef.density = 1.0f;
	// Override the default friction.
	fixtureDef.friction = 0.3f;
	fixtureDef2.friction = 0.3f;
	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);
	body->CreateFixture(&fixtureDef2);

	// TODO Auto-generated constructor stub

}

ComposedObj::~ComposedObj()
{
	// TODO Auto-generated destructor stub
}

void ComposedObj::update()
{
	b2Transform tr = body->GetTransform();
	body->GetWorldCenter();
	b2Vec2 pos1 = ((b2PolygonShape*)fixtureDef.shape)->m_centroid;
	b2Vec2 pos2 = ((b2PolygonShape*)fixtureDef2.shape)->m_centroid;
	pos1 = b2Mul(tr, pos1);
	pos2 = b2Mul(tr, pos2);
	c_data.boxes[0].x = pos1.x;
	c_data.boxes[0].y = pos1.y;
	c_data.boxes[1].x = pos2.x;
	c_data.boxes[1].y = pos2.y;
	c_data.boxes[0].angle = body->GetAngle();
	c_data.boxes[1].angle = body->GetAngle() + 45 / RAD_TO_DEG_COEF;
}

const void* ComposedObj::getStructure()
{
	return &c_data;
}

} /* namespace game */
