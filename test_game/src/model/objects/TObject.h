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

#define RAD_TO_DEG_COEF 57.295780490442965

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
	virtual void update();

};

} /* namespace game */

#endif /* MODEL_TOBJECT_H_ */
