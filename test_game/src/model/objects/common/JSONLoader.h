/*
 * JSONLoader.h
 *
 *  Created on: 2 сент. 2015 г.
 *      Author: generall
 */

#ifndef MODEL_OBJECTS_COMMON_JSONLOADER_H_
#define MODEL_OBJECTS_COMMON_JSONLOADER_H_

#include "PhisicsIncluder.hpp"
#include "ObjDesc.hpp"
#include "../../../common/JSONreader.h"
#include "TLoader.h"

namespace game
{

class JSONLoader: public TLoader
{
	Value data_node;
public:
	JSONLoader();
	virtual ~JSONLoader();
	virtual bool loadBox(  b2PolygonShape *polygon, b2FixtureDef* fixture, BoxSt * box  );
	virtual bool loadPoly( b2PolygonShape *polygon, b2FixtureDef* fixture, PolygonSt * box  );

	virtual bool dinamicBody(b2FixtureDef* fixture );
	virtual bool loadComposed(
			b2Body *body,
			std::vector<b2PolygonShape *> &dynamicBox_vector,
			std::vector<b2PolygonShape *> &dynamicPoly_vector,
			std::vector<b2FixtureDef *> &fixtureDef_vector,
			ComposedSt &c_data);
	void set_source(Value & dn);
};

} /* namespace game */

#endif /* MODEL_OBJECTS_COMMON_JSONLOADER_H_ */
