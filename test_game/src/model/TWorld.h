/*
 * TWorld.h
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#ifndef MODEL_TWORLD_H_
#define MODEL_TWORLD_H_

#include "TObject.h"
#include "../render/viewer.h"

namespace game
{


/**
 * Base class for the Universe, wich contain all objects and implements (with engine) its interaction.
 *
 */
class TWorld
{

	// assume that we use C++11 standart, so we have no warry about
	// Object recreation on resizing of vector: we use move semantic.
	std::vector<TObject*> objects; // polimorphic of course

	viewer* render_engine;

public:
	TWorld();
	virtual ~TWorld();
};

} /* namespace game */

#endif /* MODEL_TWORLD_H_ */
