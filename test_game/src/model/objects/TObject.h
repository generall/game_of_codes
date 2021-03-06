/*
 * TObject.h
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#ifndef MODEL_OBJECTS_TOBJECT_H_
#define MODEL_OBJECTS_TOBJECT_H_

#include <vector>
#include "common/ObjDesc.hpp"

namespace game
{

typedef enum {
	abstract_obj,
	box,
	wall,
	composed_boxes,
	polygon
} obj_type;

class TObject
{

protected:

	obj_type type;

public:
	TObject();
	virtual ~TObject();
	virtual void update();

	virtual obj_type getType() const { return type; }

	virtual const void* getStructure();

};

} /* namespace game */

#endif /* MODEL_TOBJECT_H_ */
