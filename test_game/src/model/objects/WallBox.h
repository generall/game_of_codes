/*
 * WallBox.h
 *
 *  Created on: Aug 23, 2015
 *      Author: generall
 */

#ifndef MODEL_OBJECTS_WALLBOX_H_
#define MODEL_OBJECTS_WALLBOX_H_

#include "TBox.h"
#include <Box2D/Box2D.h>

namespace game
{

class WallBox: public TBox
{
protected:
	b2BodyDef groundBodyDef;
	b2Body *groundBody;
	b2PolygonShape groundBox;
public:
	WallBox(b2World *world);
	virtual ~WallBox();
};

} /* namespace game */

#endif /* MODEL_OBJECTS_WALLBOX_H_ */
