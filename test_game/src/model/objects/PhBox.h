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
	PhBox(b2World *world, double width = 1.0, double height = 1.0);
	virtual ~PhBox();
	virtual void update();
	virtual void setPosition(double x, double y);

	virtual void setAngelD(double angle);
	virtual void setAngelR(double angle);
	virtual void setSize(double width, double height);
};

} /* namespace game */


#endif /* MODEL_OBJECTS_PHBOX_H_ */
