/**
 weapon.cpp

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
#include "weapon.h"

bool Weapon::is_empty() {
	return remaining_bullets == 0;
}

Weapon::~Weapon() {
}

Weapon::Weapon(World* world) {
	this->world = world;
}

Projectile* Weapon::fire() {
	Projectile* p = (*this).get_projectile(); //FIXME
	(*this).launch(p);
	world->add_projectile(p);
	return p;
}
