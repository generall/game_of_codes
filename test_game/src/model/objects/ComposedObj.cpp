/*
 * ComposedObj.cpp
 *
 *  Created on: 30 авг. 2015 г.
 *      Author: generall
 */

#include "ComposedObj.h"

namespace game
{

ComposedObj::ComposedObj(b2World *world, double x, double y, TLoader *loader)
{
	type = composed_boxes;



	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x, y );
	body = world->CreateBody(&bodyDef);

	if(!loader->loadComposed(body, dynamicBox_vector, dynamicPoly_vector, fixtureDef_vector, c_data))
		throw std::runtime_error("Fail on loading ComposedObj!");

	// Define another box shape for our dynamic body.

	// TODO Auto-generated constructor stub

}

ComposedObj::~ComposedObj()
{
	for(auto x: fixtureDef_vector)
		if(x != NULL)
			delete x;
	for(auto x: dynamicBox_vector)
		if(x != NULL)
			delete x;
	for(auto x: dynamicPoly_vector)
		if(x != NULL)
			delete x;
}

void ComposedObj::update()
{
	b2Transform tr = body->GetTransform();

	for(size_t i = 0, sz = c_data.boxes.size(); i < sz ; i++)
	{
		b2Vec2 pos1 = dynamicBox_vector[i]->m_centroid;
		pos1 = b2Mul(tr, pos1);
		c_data.boxes[i].x = pos1.x;
		c_data.boxes[i].y = pos1.y;
		c_data.boxes[i].angle = body->GetAngle() + c_data.boxes[i].d_angle;
	}

	for(size_t i = 0, sz = c_data.polygons.size(); i < sz; i++ )
	{
		b2Vec2 pos1;// = dynamicPoly_vector[i]->m_centroid;
		//pos1 = b2Mul(tr, pos1);
		pos1 = body->GetPosition();
		c_data.polygons[i].x = pos1.x;
		c_data.polygons[i].y = pos1.y;
		c_data.polygons[i].angle = body->GetAngle();
	}

}

const void* ComposedObj::getStructure()
{
	return &c_data;
}

} /* namespace game */
