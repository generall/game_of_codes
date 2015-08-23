/*
 * TBox.cpp
 *
 *  Created on: Aug 19, 2015
 *      Author: generall
 */

#include "TBox.h"

namespace game
{

TBox::TBox()
{
	rec = new TRectangle();
	shapes.push_back(rec);

}

TBox::~TBox()
{
	for(auto x: shapes)
		delete x;
	// TODO Auto-generated destructor stub
}

} /* namespace game */
