/*
 * TPolygon.h
 *
 *  Created on: Sep 13, 2015
 *      Author: generall
 */

#ifndef MODEL_OBJECTS_TPOLYGON_H_
#define MODEL_OBJECTS_TPOLYGON_H_

#include "TObject.h"
#include "common/ObjDesc.hpp"

namespace game
{

class TPolygon: public TObject
{
protected:
	PolygonSt data;
public:
	TPolygon();
	virtual ~TPolygon();
	virtual void setPosition(double x, double y);
	virtual void setAngelD(double angle);
	virtual void setAngelR(double angle);
	virtual void setPoints(std::vector<Point2D> &points);

	virtual const void* getStructure();

};

}

#endif /* MODEL_OBJECTS_TPOLYGON_H_ */
