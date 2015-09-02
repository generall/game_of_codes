/*
 * TLoader.h
 *
 *  Created on: 2 сент. 2015 г.
 *      Author: generall
 */

#ifndef MODEL_OBJECTS_COMMON_TLOADER_H_
#define MODEL_OBJECTS_COMMON_TLOADER_H_

#include <vector>
#include "ObjDesc.hpp"
#include "PhisicsIncluder.hpp"

namespace game
{

class TLoader
{
public:
	TLoader();
	virtual ~TLoader();
	virtual bool loadBox( b2PolygonShape *polygon, b2FixtureDef* fixture, BoxSt * box );
	virtual bool loadComposed(
			b2Body *body,
			std::vector<b2PolygonShape *> &dynamicBox_vector,
			std::vector<b2FixtureDef *> &fixtureDef_vector,
			ComposedSt &c_data);
};

} /* namespace game */

#endif /* MODEL_OBJECTS_COMMON_TLOADER_H_ */
