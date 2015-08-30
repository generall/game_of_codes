/*
 * GravityWorld.cpp
 *
 *  Created on: Aug 23, 2015
 *      Author: generall
 */

#include "GravityWorld.h"

namespace game
{

GravityWorld::GravityWorld() :
		gravity(0.0f, -10.0f),
		world(gravity),
		timeStep(1.0f / 60.0f),
		velocityIterations(6),
		positionIterations(2)
{
	// TODO Auto-generated constructor stub

}

GravityWorld::~GravityWorld()
{
	// TODO Auto-generated destructor stub
}

void GravityWorld::createUniverse()
{

	objects.push_back(new WallBox(&world));
	objects.push_back(new PhBox(&world));
	objects.push_back(new ComposedObj(&world));


	PhBox *barier1 = new PhBox(&world);
	barier1->setPosition(-1.5, 10);

	PhBox *barier2 = new PhBox(&world);
	barier2->setPosition(-1, 12);


	objects.push_back(barier1);
	objects.push_back(barier2);

}

void GravityWorld::tick()
{
	world.Step(timeStep, velocityIterations, positionIterations);
	for(auto x: objects)
		x->update();
}

} /* namespace game */
