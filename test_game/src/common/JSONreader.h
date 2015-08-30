/*
 * JSONreader.h
 *
 *  Created on: 30 авг. 2015 г.
 *      Author: generall
 */

#ifndef COMMON_JSONREADER_H_
#define COMMON_JSONREADER_H_

#include <rapidjson/document.h>
#include <iostream>
#include <fstream>
#include <stdexcept>

namespace game
{
using namespace std;
using namespace rapidjson;

class JSONreader
{
	string value;
	char *buffer = NULL;

public:
	JSONreader(const string &fname);
	JSONreader();

	virtual ~JSONreader();

	const string& getValue() const
	{
		return value;
	}

	void setValue(const string& value)
	{
		this->value = value;
	}


public:
	Document document;
};

} /* namespace game */

#endif /* COMMON_JSONREADER_H_ */
