/*
 * TObject.h
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#ifndef MODEL_OBJECTS_TOBJECT_H_
#define MODEL_OBJECTS_TOBJECT_H_

#include <vector>
#include "../primitives/TShape.h"

namespace game
{

class TObject
{

protected:

	std::vector<TShape*> shapes;

public:
	TObject();
	virtual ~TObject();
	virtual std::vector<TShape*>& getShapes();

};

} /* namespace game */

#endif /* MODEL_TOBJECT_H_ */
