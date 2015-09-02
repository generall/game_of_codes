/*
 * JSONLoader.cpp
 *
 *  Created on: 2 сент. 2015 г.
 *      Author: generall
 */

#include "JSONLoader.h"

namespace game
{

JSONLoader::JSONLoader()
{
	// TODO Auto-generated constructor stub

}

JSONLoader::~JSONLoader()
{
	// TODO Auto-generated destructor stub
}

/**
 * reading Box params from json value node
 * @param polygon
 * @param fixture
 * @param box
 * @param data_node
 * @return true if succsess
 */
bool JSONLoader::loadBox(b2PolygonShape* polygon, b2FixtureDef* fixture,
		BoxSt* box)
{
	double density  = 0.0;
	double friction = 0.0;
	if(data_node.IsObject())
	{
		/**
		 * necessary values
		 */

		if(data_node["width"].IsDouble())
			box->width = data_node["width"].GetDouble();
		else
			return false;
		if(data_node["height"].IsDouble())
			box->height = data_node["height"].GetDouble();
		else
			return false;

		/**
		 * optional params
		 */

		if(data_node.HasMember("dx") && data_node["dx"].IsDouble())
			box->x = data_node["dx"].GetDouble();
		else
			box->x = 0.0;

		if(data_node.HasMember("dy") && data_node["dy"].IsDouble())
			box->y = data_node["dy"].GetDouble();
		else
			box->y = 0.0;

		if(data_node.HasMember("angle") && data_node["angle"].IsDouble())
			box->angle = data_node["angle"].GetDouble() / RAD_TO_DEG_COEF;
		else
			box->angle = 0.0;

		box->d_angle = box->angle;

		if(data_node.HasMember("density") && data_node["density"].IsDouble())
			density = data_node["density"].GetDouble();

		if(data_node.HasMember("friction") && data_node["friction"].IsDouble())
			friction = data_node["friction"].GetDouble();

	}else{
		return false;
	}

	// SetAsBox accepts half of size
	polygon->SetAsBox(box->width / 2, box->height / 2, b2Vec2(box->x, box->y), box->angle );
	fixture->shape = polygon;
	fixture->density = density;
	fixture->friction = friction;

	return true;
}

bool JSONLoader::loadComposed( b2Body* body,
		std::vector<b2PolygonShape*>& dynamicBox_vector,
		std::vector<b2FixtureDef*>& fixtureDef_vector, ComposedSt &c_data)
{
	if(data_node.IsArray())
	{
		for (SizeType i = 0; i < data_node.Size(); i++)
		{
			Value &body_node = data_node[i];
			if(body_node.IsObject())
			{
				if(!body_node["type"].IsString())
					return false;
				std::string type = body_node["type"].GetString();
				if(type == "box")
				{
					BoxSt box;
					b2PolygonShape *polygon = new b2PolygonShape();
					b2FixtureDef   *fixture = new b2FixtureDef();

					JSONLoader jl;

					if(!body_node["params"].IsObject())
						return false;

					jl.set_source(body_node["params"]);

					if(!jl.loadBox(polygon, fixture, &box ))
						return false;

					dynamicBox_vector.push_back(polygon);
					fixtureDef_vector.push_back(fixture);
					body->CreateFixture(fixture);
					c_data.boxes.push_back(box);
				}
			}else{
				return false;
			}
		}
	}else{
		return false;
	}
	return true;
}

void JSONLoader::set_source(Value& dn)
{
	data_node = dn;
}

} /* namespace game */
