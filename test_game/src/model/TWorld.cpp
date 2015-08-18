/*
 * TWorld.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#include "TWorld.h"

namespace game
{

TWorld::TWorld()
{
	// TODO Auto-generated constructor stub

}

TWorld::~TWorld()
{
	// TODO Auto-generated destructor stub
}

void TWorld::render()
{
	for(auto x: objects )
	{
		x->render(render_engine);
	}
	render_engine->update();
}

} /* namespace game */
