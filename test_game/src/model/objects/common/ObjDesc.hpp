/*
 * ObjDesc.hpp
 *
 *  Created on: 2 сент. 2015 г.
 *      Author: generall
 */

#ifndef MODEL_OBJECTS_COMMON_OBJDESC_HPP_
#define MODEL_OBJECTS_COMMON_OBJDESC_HPP_

#define RAD_TO_DEG_COEF 57.295780490442965
#define PI 3.1415926

namespace game{

struct BoxSt
{
	double x, y, width, height;
	double angle; // current angle relative to World [updateable]
	double d_angle; // angle relative to body
};


struct ComposedSt
{
	std::vector<BoxSt> boxes;
};



};



#endif /* MODEL_OBJECTS_COMMON_OBJDESC_HPP_ */
