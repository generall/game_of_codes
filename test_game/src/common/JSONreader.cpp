/*
 * JSONreader.cpp
 *
 *  Created on: 30 авг. 2015 г.
 *      Author: generall
 */

#include "JSONreader.h"

namespace game
{

JSONreader::JSONreader(const string &fname)
{
	// TODO Auto-generated constructor stub
	ifstream in(fname.c_str(), ios::in);
	if(in)
	{
		in.seekg(0, std::ios::end);
		size_t size = in.tellg();
		std::string buff(size, ' ');
		in.seekg(0);
		in.read(&buff[0], size);
		value =  buff;
		buffer = new char[value.size()];
		memcpy(buffer, value.c_str(), value.size());
		if (document.ParseInsitu(buffer).HasParseError())
			throw std::runtime_error("Can not create document");
	}else{
		throw std::runtime_error("File " + fname + " not found!");
	}
}

JSONreader::JSONreader()
{

}

JSONreader::~JSONreader()
{
	if(buffer != NULL)
		delete buffer;
	// TODO Auto-generated destructor stub
}

} /* namespace game */
