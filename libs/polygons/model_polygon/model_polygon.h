/**
 model_polygon.h

 Copyright 2014 Gaston Martinez Gaston.martinez.90@gmail.com

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses
 */
#ifndef MODEL_POLYGON_H_
#define MODEL_POLYGON_H_

#include <Box2D/Box2D.h>

class Model_polygon {

public:
	static const int STATIC = 0;
	static const int DYNAMIC = 1;

protected:
	int body_type;
	double density;
	b2Body* body;
	b2Vec2* vertex=NULL;

protected:
	void create_body(b2BodyDef* body_definition, b2FixtureDef* body_fixture,
			b2World& world);
	void set_vertex(b2Vec2* vertex);

public:
	Model_polygon(int body_type, double density);
	virtual ~Model_polygon();

	virtual void rotate(double angle);
	virtual double get_rotation();

	virtual void move(double x_units, double y_units);
	virtual b2Vec2 get_position();

	virtual void apply_force(double x_units, double y_units);
	virtual void apply_instant_force(double x_units, double y_units);

	virtual void set_velocity(double x_units, double y_units);
	virtual b2Vec2 get_velocity();

	virtual void set_angular_velocity(double angular_velocity);
	virtual double get_angular_velocity();

	virtual b2Vec2* get_vertex();
};

#endif /* MODEL_POLYGON_H_ */
