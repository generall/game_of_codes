/*
 * TBox.h
 *
 *  Created on: Aug 19, 2015
 *      Author: generall
 */

#ifndef MODEL_OBJECTS_TBOX_H_
#define MODEL_OBJECTS_TBOX_H_

#include "TObject.h"

namespace game
{

struct BoxSt
{
	double x, y, width, height;
	double angle;
};

class TBox: public TObject
{
protected:
	BoxSt data;
public:
	TBox();
	virtual ~TBox();
	virtual void setPosition(double x, double y);
	virtual void setAngelD(double angle);
	virtual void setAngelR(double angle);
	virtual void setSize(double width, double height);
	virtual const void* getStructure();
};

} /* namespace game */

#endif /* MODEL_OBJECTS_TBOX_H_ */
