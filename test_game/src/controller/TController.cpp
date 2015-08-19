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
	view = new viewer();

	model = new TWorld();

	model->createBox();

	view->init();
	view->setModel(model);

	while(view->update() != closed){};

	delete view;

	delete model;
}

} /* namespace game */
