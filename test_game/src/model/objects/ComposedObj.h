/*
 * ComposedObj.h
 *
 *  Created on: 30 авг. 2015 г.
 *      Author: generall
 */

#ifndef MODEL_OBJECTS_COMPOSEDOBJ_H_
#define MODEL_OBJECTS_COMPOSEDOBJ_H_

#include "PhBox.h"
#include "common/TLoader.h"

namespace game
{


class ComposedObj: public TObject
{

	ComposedSt c_data;

	b2BodyDef bodyDef;
	b2Body *body;

	std::vector<b2PolygonShape *> dynamicBox_vector;
	std::vector<b2FixtureDef *> fixtureDef_vector;
	std::vector<b2PolygonShape *> dynamicPoly_vector;
public:
	ComposedObj(b2World *world, double x, double y, TLoader *loader);
	virtual ~ComposedObj();

	virtual void update();
	virtual const void* getStructure();
};

} /* namespace game */

#endif /* MODEL_OBJECTS_COMPOSEDOBJ_H_ */
