/**
 dmg_projectile.cpp

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
#include "dmg_projectile.h"

Dmg_projectile::Dmg_projectile() {
	// TODO Auto-generated constructor stub

}

Dmg_projectile::~Dmg_projectile() {
	// TODO Auto-generated destructor stub
}

void Dmg_projectile::collide(Character& character) {
	character.reduce_life();
}
