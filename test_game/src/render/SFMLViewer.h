/*
 * SFMLViewer.h
 *
 *  Created on: Aug 23, 2015
 *      Author: generall
 */

#ifndef RENDER_SFMLVIEWER_H_
#define RENDER_SFMLVIEWER_H_

#include "viewer.h"
#include <iostream>
#include <set>
#include <map>
#include <utility>

namespace game
{

using namespace std;

class SFMLViewer: public viewer
{
protected:
	sf::RenderWindow *window;

	set<int> layers_indexes;

	map<int, vector<sf::RectangleShape *> > rect_layers;
	map<int, vector< pair<size_t, sf::Vertex *> > > vert_layers;

public:
	SFMLViewer();
	virtual ~SFMLViewer();
	virtual view_state update();
	virtual bool init();

private:
	/**
	 * @param data - description of object
	 * @param z - index of layer
	 */
	void render_box(const BoxSt &data, int z = 0);
	void draw_layers();
	void free_layers();

};

} /* namespace game */

#endif /* RENDER_SFMLVIEWER_H_ */
