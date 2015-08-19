/*
 * TWorld.h
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#ifndef MODEL_TWORLD_H_
#define MODEL_TWORLD_H_

#include <vector>
#include "objects/TObject.h"
#include "objects/TBox.h"

namespace game
{
/**
 * Base class for the Universe, wich contain all objects and implements (with engine) its interaction.
 *
 */
class TWorld
{

protected:
	// assume that we use C++11 standart, so we have no warry about
	// Object recreation on resizing of vector: we use move semantic.
	std::vector<TObject *> objects; // polimorphic of course

public:
	TWorld();
	virtual ~TWorld();
	virtual std::vector<TObject*>& getObjectVector();

	virtual void createBox();
};

} /* namespace game */

#endif /* MODEL_TWORLD_H_ */
