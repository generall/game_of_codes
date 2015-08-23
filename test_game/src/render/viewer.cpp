/*
 * viewer.cpp
 *
 *  Created on: Aug 18, 2015
 *      Author: generall
 */

#include "viewer.h"

namespace game
{

viewer::viewer() :
		model(NULL)
{

	// TODO Auto-generated constructor stub

}

viewer::~viewer()
{

	// TODO Auto-generated destructor stub
}

bool viewer::init()
{
	return true;
}

void viewer::setModel(TWorld* _model)
{
	model = _model;
}

view_state viewer::update()
{
	return closed;
}

} /* namespace game */
