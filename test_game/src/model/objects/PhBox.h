/*
 * PhBox.h
 *
 *  Created on: Aug 23, 2015
 *      Author: generall
 */

#ifndef MODEL_OBJECTS_PHBOX_H_
#define MODEL_OBJECTS_PHBOX_H_

#include "TBox.h"
#include <Box2D/Box2D.h>

namespace game
{

class PhBox: public TBox
{
protected:
	b2BodyDef bodyDef;
	b2Body* body;
	b2PolygonShape dynamicBox;
	b2FixtureDef fixtureDef;
public:
	PhBox(b2World *world);
	virtual ~PhBox();
	virtual void update();
	virtual void setPosition(double x, double y);
};

} /* namespace game */


#endif /* MODEL_OBJECTS_PHBOX_H_ */
