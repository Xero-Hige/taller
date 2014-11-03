/*
 * LevelState.h
 *
 *  Created on: 17/10/2014
 *      Author: demian
 */

#ifndef LEVELSTATE_H_
#define LEVELSTATE_H_

#include "engine/GameState.h"
#include <iostream>
#include <vector>
#include <CommandCode.h>
#include <mutex>

#include "engine/Image.h"
#include "engine/SpriteSheet.h"
#include "engine/Animation.h"
#include "engine/Graphics.h"
#include "engine/Game.h"
#include "engine/Graphics.h"
#include "engine/LibIncludes.h"
#include "engine/ParticleEmiter.h"
#include "engine/Image.h" //Provisional
#include "GameWorld.h"

using std::mutex;

class LevelState: public GameState {
public:
	LevelState();
	virtual ~LevelState();

	void setWorld(GameWorld * world);
	void restartCameraPosition();

	void sendKeyData();
	std::vector<KeyCode> getKeyCodeData();
private:
	virtual void update(unsigned int delta);
	virtual void render(Graphics *g, Game * game, unsigned int delta);
	virtual void keyEvent(SDL_Event e, Game * game);
	virtual void init(Game * game);
	virtual void exit(Game * game);
	void enter();

	Image * worldImage;
	Image * backgroundImage;

	GameWorld * gameWorld;

	ParticleEmiter * backParticleEmiter;
	ParticleEmiter * frontParticleEmiter;

	Animation * lightAnimation;
	SpriteSheet * spriteLightAnimation;
	int lightAnimationX;

	float zoomScale;
	float maxZoomScale;
	float minZoomScale;

	int globalX;
	int globalY;

	std::vector<KeyCode> keyCodeData;
	mutex levelStateMutex;
};

#endif /* LEVELSTATE_H_ */
