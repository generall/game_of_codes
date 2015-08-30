/*
 * ComposedObj.h
 *
 *  Created on: 30 авг. 2015 г.
 *      Author: generall
 */

#ifndef MODEL_OBJECTS_COMPOSEDOBJ_H_
#define MODEL_OBJECTS_COMPOSEDOBJ_H_

#include "PhBox.h"

namespace game
{


struct ComposedSt
{
	std::vector<BoxSt> boxes;
};


class ComposedObj: public TObject
{

	ComposedSt c_data;

	b2BodyDef bodyDef;
	b2Body *body;

	/* FOR TEST */
	b2PolygonShape dynamicBox, dynamicBox2; // delete later
	b2FixtureDef fixtureDef, fixtureDef2;   // delete

	std::vector<b2PolygonShape> dynamicBox_vector;
	std::vector<b2FixtureDef> fixtureDef_vector;
public:
	ComposedObj(b2World *world);
	virtual ~ComposedObj();

	virtual void update();
	virtual const void* getStructure();
};

} /* namespace game */

#endif /* MODEL_OBJECTS_COMPOSEDOBJ_H_ */
