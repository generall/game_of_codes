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

	if (data_node.IsObject())
	{
		/**
		 * necessary values
		 */

		if (data_node["width"].IsDouble())
			box->width = data_node["width"].GetDouble();
		else
			return false;
		if (data_node["height"].IsDouble())
			box->height = data_node["height"].GetDouble();
		else
			return false;

		/**
		 * optional params
		 */

		if (data_node.HasMember("dx") && data_node["dx"].IsDouble())
			box->x = data_node["dx"].GetDouble();
		else
			box->x = 0.0;

		if (data_node.HasMember("dy") && data_node["dy"].IsDouble())
			box->y = data_node["dy"].GetDouble();
		else
			box->y = 0.0;

		if (data_node.HasMember("angle") && data_node["angle"].IsDouble())
			box->angle = data_node["angle"].GetDouble() / RAD_TO_DEG_COEF;
		else
			box->angle = 0.0;

		box->d_angle = box->angle;

	}
	else
	{
		return false;
	}

	// SetAsBox accepts half of size
	polygon->SetAsBox(box->width / 2, box->height / 2, b2Vec2(box->x, box->y),
			box->angle);
	fixture->shape = polygon;

	return true;
}

bool JSONLoader::dinamicBody(b2FixtureDef* fixture)
{
	double density = 0.0;
	double friction = 0.0;
	double restitution = 0.0; // if > 1 energy is not conservating

	if (data_node.IsObject())
	{

		if (data_node.HasMember("density") && data_node["density"].IsDouble())
			density = data_node["density"].GetDouble();

		if (data_node.HasMember("friction") && data_node["friction"].IsDouble())
			friction = data_node["friction"].GetDouble();

		if (data_node.HasMember("restitution")
				&& data_node["restitution"].IsDouble())
			restitution = data_node["restitution"].GetDouble();
	}
	else
	{
		return false;
	}

	fixture->density = density;
	fixture->friction = friction;
	fixture->restitution = restitution;

	return true;
}

bool JSONLoader::loadComposed(b2Body* body,
		std::vector<b2PolygonShape*>& dynamicBox_vector,
		std::vector<b2PolygonShape*>& dynamicPoly_vector,
		std::vector<b2FixtureDef*>& fixtureDef_vector, ComposedSt &c_data)
{
	if (data_node.IsArray())
	{
		for (SizeType i = 0; i < data_node.Size(); i++)
		{
			Value &body_node = data_node[i];
			if (body_node.IsObject())
			{
				if (!body_node["type"].IsString())
					return false;
				std::string type = body_node["type"].GetString();
				if (type == "box")
				{
					BoxSt box;
					b2PolygonShape *polygon = new b2PolygonShape();
					b2FixtureDef *fixture = new b2FixtureDef();

					JSONLoader jl;

					if (!body_node["params"].IsObject())
						return false;

					jl.set_source(body_node["params"]);

					if (!jl.loadBox(polygon, fixture, &box))
						return false;

					if (!jl.dinamicBody(fixture))
						return false;

					dynamicBox_vector.push_back(polygon);
					fixtureDef_vector.push_back(fixture);
					body->CreateFixture(fixture);
					c_data.boxes.push_back(box);
				}
				else if (type == "polygon")
				{
					PolygonSt poly;
					b2PolygonShape *polygon = new b2PolygonShape();
					b2FixtureDef *fixture = new b2FixtureDef();

					JSONLoader jl;
					if (!body_node["params"].IsObject())
						return false;
					jl.set_source(body_node["params"]);

					if (!jl.loadPoly(polygon, fixture, &poly))
						return false;

					if (!jl.dinamicBody(fixture))
						return false;

					dynamicPoly_vector.push_back(polygon);
					fixtureDef_vector.push_back(fixture);
					body->CreateFixture(fixture);
					c_data.polygons.push_back(poly);

				}
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

bool JSONLoader::loadPoly(b2PolygonShape* polygon, b2FixtureDef* fixture,
		PolygonSt* data)
{

	if (data_node.IsObject())
	{
		/**
		 * necessary values
		 */

		if (data_node.HasMember("dx") && data_node["dx"].IsDouble())
			data->x = data_node["dx"].GetDouble();
		else
			data->x = 0.0;

		if (data_node.HasMember("dy") && data_node["dy"].IsDouble())
			data->y = data_node["dy"].GetDouble();
		else
			data->y = 0.0;

		if (data_node["points"].IsArray())
		{
			try
			{
				std::vector<Point2D> poly_points;
				for (SizeType i = 0; i < data_node["points"].Size(); i++)
				{
					Value &p = data_node["points"][i];
					poly_points.push_back(
							Point2D(p[0].GetDouble(),
									p[1].GetDouble()));
				}
				b2Vec2 *vertices = new b2Vec2[poly_points.size()];
				/*
				 * WARN: memory leak! Check if it can be safely deleted!
				 */

				b2Vec2 *curr = vertices;

				for (Point2D pt : poly_points)
				{
					curr->x = pt.x + data->x;
					curr->y = pt.y + data->y;
					curr++;
				}

				data->points = poly_points;

				polygon->Set(vertices, poly_points.size());

			} catch (...)
			{
				throw std::runtime_error("invalid json");
			}
		}
		else
		{
			return false;
		}

		/**
		 * optional params
		 */

		data->angle = 0.0;
		data->d_angle = data->angle;

	}
	else
	{
		return false;
	}

	fixture->shape = polygon;

	return true;
}

void JSONLoader::set_source(Value& dn)
{
	data_node = dn;
}

} /* namespace game */

