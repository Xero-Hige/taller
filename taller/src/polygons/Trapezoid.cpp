/**
 Trapezoid.cpp

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
#include "Trapezoid.h"

void Trapezoid::define_vertex(double height, double base, double top, b2Vec2* vertex) {
	double y_height = height / 2;
	double x_top = top / 2;
	double x_base = base / 2;
	vertex[0] = b2Vec2(-x_base, -y_height);
	vertex[1] = b2Vec2(x_base, -y_height);
	vertex[2] = b2Vec2(x_top, y_height);
	vertex[3] = b2Vec2(-x_top, y_height);
}

Trapezoid::Trapezoid(double height, double base, double top,  double posX, double posY,
		double density, int body_type, World * world) :
				Polygon(body_type) {

	b2Vec2* vertex = new b2Vec2[4];
	this->define_vertex(height, base, top, vertex);

	b2PolygonShape polygon_shape;
	polygon_shape.Set(vertex, 4); //seteo los vertices del poligono

	b2FixtureDef body_fixture;
	body_fixture.shape = &polygon_shape;
	body_fixture.density = density;
	body_fixture.friction = 0.1f;

	b2BodyDef body_definition;

	if(body_type == Polygon::STATIC){
		body_definition.type = b2_staticBody;
	} else {
		body_definition.type = b2_dynamicBody;
	}

	body_definition.position.Set(posX, posY); //seteo posicion base

	this->create_body(&body_definition, &body_fixture, world);

	this->setVertex(vertex);
	this->createSDLPoints();

	delete[] vertex;
}

void Trapezoid::setVertex(b2Vec2 * vertex){
	for(size_t i = 0; i < 4; i++){
		this->addB2DPoint(vertex[i].x, vertex[i].y);
	}
}

Trapezoid::~Trapezoid() {
	// TODO Auto-generated destructor stub
}
