/*
 * GravityWorld.h
 *
 *  Created on: Aug 23, 2015
 *      Author: generall
 */

#ifndef MODEL_GRAVITYWORLD_H_
#define MODEL_GRAVITYWORLD_H_

#include "TWorld.h"
#include "objects/PhBox.h"
#include "objects/WallBox.h"
#include <Box2D/Box2D.h>

namespace game
{

class GravityWorld: public TWorld
{
	b2Vec2 gravity;
	b2World world;

	float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations;
public:
	GravityWorld();
	virtual ~GravityWorld();
	virtual void createUniverse();
	virtual void tick();
};

} /* namespace game */

#endif /* MODEL_GRAVITYWORLD_H_ */
