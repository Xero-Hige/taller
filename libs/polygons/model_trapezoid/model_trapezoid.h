/**
 model_trapezoid.h

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
#ifndef MODEL_TRAPEZOID_H_
#define MODEL_TRAPEZOID_H_

#include "../model_polygon/model_polygon.h"
#include <Box2D/Box2D.h>

class Model_trapezoid: public Model_polygon {
public:
	Model_trapezoid(double height, double base, double top, double density,
			int body_type, b2World& world);
	virtual ~Model_trapezoid();
};

#endif /* MODEL_TRAPEZOID_H_ */
