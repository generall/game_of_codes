/*
 * TController.cpp
 *
 *  Created on: Aug 19, 2015
 *      Author: generall
 */

#include "TController.h"

namespace game
{

TController::TController():model(NULL), view(NULL)
{
	// TODO Auto-generated constructor stub

}

TController::~TController()
{
	// TODO Auto-generated destructor stub
}

void TController::start()
{
	view = new SFMLViewer();

	model = new GravityWorld();

	model->createUniverse();

	view->init();
	view->setModel(model);

	while(view->update() != closed){
		model->tick();
		//exit(0);
		//usleep(16000); // 60 fps
	};

	delete view;

	delete model;
}

} /* namespace game */
