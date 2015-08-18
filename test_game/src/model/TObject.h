/*
 * TObject.h
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#ifndef MODEL_TOBJECT_H_
#define MODEL_TOBJECT_H_

#include <vector>
#include "primitives/TShape.h"
#include "../render/viewer.h"

namespace game
{

class TObject
{

	std::vector<TShape*> shapes;

public:
	TObject();
	virtual ~TObject();
	void render(viewer* v);
};

} /* namespace game */

#endif /* MODEL_TOBJECT_H_ */
