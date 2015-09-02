/*
 * WallBox.h
 *
 *  Created on: Aug 23, 2015
 *      Author: generall
 */

#ifndef MODEL_OBJECTS_WALLBOX_H_
#define MODEL_OBJECTS_WALLBOX_H_

#include "TBox.h"
#include "common/PhisicsIncluder.hpp"

namespace game
{

class WallBox: public TBox
{
protected:
	b2BodyDef groundBodyDef;
	b2Body *groundBody;
	b2PolygonShape groundBox;
public:
	WallBox(b2World *world, double width = 50, double height = 10);
	virtual ~WallBox();
	virtual void setPosition(double x, double y);

	virtual void setAngelD(double angle);
	virtual void setAngelR(double angle);
	virtual void setSize(double width, double height);
};

} /* namespace game */

#endif /* MODEL_OBJECTS_WALLBOX_H_ */
