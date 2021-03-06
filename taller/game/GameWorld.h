/*
 * GameWorld.h
 *
 *  Created on: 18/10/2014
 *      Author: demian
 */

#ifndef GAMEWORLD_H_
#define GAMEWORLD_H_

#include "VectorXY.h"
#include <vector>
#include <map>
class GameEntity;
#include "../common/UpdateRequest.h"
#include <mutex>

class GameWorld {
public:
	/* Crea un GameWorld.
	 * Recibe el tamanyo del mundo de box2d. */
	GameWorld(float tX, float tY);

	/* Setea tamanyo de la pantalla. */
	void setScreenSize(VectorXY screenSize);

	/* Devuelve entityList. */
	std::map<int, GameEntity *> getEntityMap();

	/* Agrega un GameEntity. */
	void addEntity(GameEntity * entity);

	/* Devuelve el tamanyo del mundo de box2d. */
	VectorXY getBox2DWorldSize();

	/* Inicializa los componentes graficos. */
	void generateGraphics();

	VectorXY box2DToSDLSize(VectorXY * box2DCoord);
	VectorXY box2DToSDL(VectorXY * box2DCoord);

	VectorXY getSdlWorldSize();

	/* Agrega pedido de request. */
	void addUpdateRequest(UpdateRequest * update);

	/* Realiza los updates. */
	void update(unsigned int delta);

	GameEntity * searchEntity(int index);
	void setMainEntity(int index);

	GameEntity * getMainEntity();

	void setWaitingForPlayers(bool waitingForPlayers);
	bool isWaitingForPlayers();

	void mutexLock();
	void mutexUnlock();

	virtual ~GameWorld();
private:
	VectorXY box2DSize;
	VectorXY screenSize;
	VectorXY sdlWorldSize;

	std::map<int, GameEntity *> entityMap;

	std::mutex updateMutex;
	std::mutex entityMutex;

	GameEntity * mainEntity;

	bool waitingForPlayers;
	int afkTime;

	std::vector<UpdateRequest *> updateList;
};

#endif /* GAMEWORLD_H_ */
