/*
 * EnemyEntity.h
 *
 *  Created on: 29/11/2014
 *      Author: demian
 */

#ifndef ENEMYENTITY_H_
#define ENEMYENTITY_H_

#include "MovementEntity.h"

class EnemyEntity: public MovementEntity {
public:
	EnemyEntity(int index, int type);
	void render(Graphics * g, unsigned int delta);
	void initialize();
	void applyUpdate(UpdateRequest * u);
	virtual ~EnemyEntity();
private:
	int type;
};

#endif /* ENEMYENTITY_H_ */
