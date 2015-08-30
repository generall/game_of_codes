//============================================================================
// Name        : test_game.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <SFML/Graphics.hpp>
#include "controller/TController.h"
#include "common/JSONreader.h"

using namespace game;
using namespace std;

int main()
{
	TController controller;
	controller.start();

    return 0;
}
