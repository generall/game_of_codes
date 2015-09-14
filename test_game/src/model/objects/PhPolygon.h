/*
 * PhPolygon.h
 *
 *  Created on: Sep 13, 2015
 *      Author: generall
 */

#ifndef MODEL_OBJECTS_PHPOLYGON_H_
#define MODEL_OBJECTS_PHPOLYGON_H_

#include "TPolygon.h"
#include "common/PhisicsIncluder.hpp"


namespace game
{

class PhPolygon: public game::TPolygon
{
protected:
	b2BodyDef bodyDef;
	b2Body* body;
	b2PolygonShape dynamicBox;
	b2FixtureDef fixtureDef;
	b2Vec2 *vertices;
public:
	PhPolygon(b2World *world, std::vector<Point2D> &points );
	virtual ~PhPolygon();

	virtual void update();
	virtual void setPosition(double x, double y);

	virtual void setAngelD(double angle);
	virtual void setAngelR(double angle);
};

}

#endif /* MODEL_OBJECTS_PHPOLYGON_H_ */
