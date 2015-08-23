/*
 * TController.h
 *
 *  Created on: Aug 19, 2015
 *      Author: generall
 */

#ifndef CONTROLLER_TCONTROLLER_H_
#define CONTROLLER_TCONTROLLER_H_

#include "../render/SFMLViewer.h"
#include "../model/TWorld.h"
#include "../model/GravityWorld.h"
#include <unistd.h>

namespace game
{

class TController
{

	TWorld *model;
	viewer *view;

public:
	TController();
	virtual ~TController();
	virtual void start();
};

} /* namespace game */

#endif /* CONTROLLER_TCONTROLLER_H_ */
