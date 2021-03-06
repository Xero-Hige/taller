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

#include <Box2D/Common/b2Math.h>
#include <vector>

#include "../../common/CommandCode.h"

class b2Body;
struct b2BodyDef;
struct b2FixtureDef;

class World;

using std::vector;

class Polygon {

public:
	static const int STATIC = 0;
	static const int DYNAMIC = 1;

	Polygon(int body_def);
	virtual ~Polygon();

	b2Vec2 * getPosition();
	b2Body * getBody();
	float getRotation();

	bool isStatic();
	vector<b2Vec2 *> getPointList();

	void setEntityIndex(int index);
	int getEntityIndex();

	EntityType getType();
	void setType(EntityType type);

	char tipoDeObjeto;
protected:

	EntityType type;

	b2Body* body;
	World * world;

	const float friction = 0.5;

	void create_body(b2BodyDef* body_definition, b2FixtureDef* body_fixture,
			World * world);

	void addB2DPoint(double x, double y);

private:
	vector<b2Vec2 *> pointList;
	int body_def;
	int entityIndex;
};

#endif /* MODEL_POLYGON_H_ */
