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
	for(auto x:objects)
		delete x;
	// TODO Auto-generated destructor stub
}

void GravityWorld::createUniverse()
{

	objects.push_back(new WallBox(&world));
	objects.push_back(new PhBox(&world));

	JSONreader jReader("resources/test.json");

	JSONLoader jLoader;


	if(!jReader.document.IsObject())
		throw std::runtime_error("Root of JSON is not an Object");

	Value &v = jReader.document["objects"];

	jLoader.set_source(v);

	ComposedObj *co = new ComposedObj(&world, -2, 5, &jLoader );

	objects.push_back(co);



	std::vector<Point2D> poly_points;

	poly_points.push_back(Point2D(-2, -2));
	poly_points.push_back(Point2D(-3,  1));
	poly_points.push_back(Point2D( 0,  3));
	poly_points.push_back(Point2D( 3,  1));
	poly_points.push_back(Point2D( 2, -2));



	PhPolygon *poly = new PhPolygon(&world, poly_points);
	poly->setPosition(2, 15);


	objects.push_back(poly);




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
