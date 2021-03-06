#include "Personaje.h"
#include "../game/Resources.h"
#include "../game/engine/Animation.h"
#include "CosaConMovimiento.h"
#include <iostream>

Personaje::Personaje() {
	listenerTouchingGround = NULL;
	this->currentAnimation = A_STAND_LEFT;
	this->atravesandoRampa = false;
	this->activeUpdate = true;
	this->superSpeed = false;
	this->inWater = false;
}

int Personaje::getIndex() {
	return userIndex;
}

AnimationCode Personaje::getCurrentAnimation() {
	return this->currentAnimation;
}

void Personaje::moveLeft(bool isButtonDown) {
	body->ApplyLinearImpulse(b2Vec2(-50 - body->GetLinearVelocity().x * 2, 0),
			body->GetWorldCenter(), true);

}

void Personaje::moveRight(bool isButtonDown) {
	body->ApplyLinearImpulse(b2Vec2(50 - body->GetLinearVelocity().x * 2, 0),
			body->GetWorldCenter(), true);
}

ContactListener* Personaje::getListenerTouchingGround() {
	return listenerTouchingGround;
}

void Personaje::setListenerTouchingGround(ContactListener *aListener) {
	listenerTouchingGround = aListener;
}

ContactListener* Personaje::getHeadListener(){
	return headListener;
}

void Personaje::setHeadListener(ContactListener *aListener){
	headListener = aListener;
}

void Personaje::enteredWater(){
	movementSpeedX -= 10;
	inWater = true;
}

void Personaje::exitedWater(){
	movementSpeedX += 10;
	inWater = false;
}

bool Personaje::isInWater(){
	return inWater;
}

void Personaje::evaluateAnimation() {
// redefinir en cada personaje
}

void Personaje::jump() {
	if(isInWater()){
		b2Vec2 currentVel = this->body->GetLinearVelocity();
		this->body->SetLinearVelocity(b2Vec2(currentVel.x, movementSpeedY/2));
		this->goingUp = true;
		return;
	}
	if (listenerTouchingGround->getNumberOfContacts() == 0 || this->atravesandoRampa)
		return; //Esto medio que esta repetido, ya se checkea en SnowBross.
	b2Vec2 currentVel = this->body->GetLinearVelocity();
	this->body->SetLinearVelocity(b2Vec2(currentVel.x, movementSpeedY));

	//body->ApplyLinearImpulse(b2Vec2(0,body->GetMass() * 8), body->GetWorldCenter(), true);
	//body->ApplyForceToCenter(b2Vec2(0,1006), true);
	this->goingUp = true;
}

b2Vec2 * Personaje::getPosition() {
	return (b2Vec2*) &this->body->GetPosition();
}

void Personaje::setEntityIndex(int index) {
	this->userIndex = index;
}

void Personaje::update() {
	if(!activeUpdate){
		return;
	}

	int movementSpeedX;

	if(this->superSpeed){
		movementSpeedX = this->movementRunSpeed;
	} else {
		movementSpeedX = this->movementSpeedX;
	}
	//cout << "cantidad de contactos: " << listenerTouchingGround->getNumberOfContacts() << endl;
	b2Vec2 currentVel = this->body->GetLinearVelocity();

	if (currentVel.y < 1 && currentVel.y > -1) { // Quieto en Y
		if (this->goingUp) {
			this->goingUp = false;
			this->onTopJump = true;
		}

		if (this->goingDown) {
			this->goingDown = false;
			if (stopAtHit) {
				this->stop();
				this->stopAtHit = false;
			}
		}

	}

	if (currentVel.y < -1) { // Cayendo
		if (this->onTopJump) {
			this->onTopJump = false;
			this->goingDown = true;
		}
	}

	//Movimiento hacia los lados
	if (movingRight) {
		if (!movingLeft || !wasMovingLeftFirst) {
			body->ApplyLinearImpulse(
					b2Vec2(movementSpeedX - body->GetLinearVelocity().x * 2, 0),
					body->GetWorldCenter(), true); //this->body->SetLinearVelocity(b2Vec2(movementSpeedX, currentVel.y));
			mirandoParaLaDerecha = true;
			this->evaluateAnimation();
			return;
		}
	}
	if (movingLeft) {
		if (!movingRight || wasMovingLeftFirst) {
			body->ApplyLinearImpulse(
					b2Vec2(-movementSpeedX - body->GetLinearVelocity().x * 2, 0),
					body->GetWorldCenter(), true); //this->body->SetLinearVelocity(b2Vec2(-movementSpeedX, currentVel.y));
			mirandoParaLaDerecha = false;
			this->evaluateAnimation();
			return;
		}
	}

	stop(true, false);
	this->evaluateAnimation();
}

/*
 void Personaje::jump() {

 if (listenerTouchingGround->getNumberOfContacts() == 0)
 return; //Esto medio que esta repetido, ya se checkea en SnowBross.
 b2Vec2 currentVel = this->body->GetLinearVelocity();
 this->body->SetLinearVelocity(b2Vec2(currentVel.x, movementSpeedY));

 //body->ApplyLinearImpulse(b2Vec2(0,body->GetMass() * 8), body->GetWorldCenter(), true);
 //body->ApplyForceToCenter(b2Vec2(0,1006), true);
 this->goingUp = true;


 }

 /*
 void Personaje::setListenerTouchingGround(ContactListener *aListener) {
 listenerTouchingGround = aListener;
 }

 bool Personaje::isOnAir() {
 return (listenerTouchingGround->getNumberOfContacts() == 0);
 }

 Animation * Personaje::getAnimation(Resources * resources) {
 if (this->isOnAir()) {
 if (mirandoParaLaDerecha) {
 return resources->getPlayerAirRight();
 } else {
 return resources->getPlayerAirLeft();
 }
 }

 if (mirandoParaLaDerecha) {
 if (this->movingRight) {
 return resources->getPlayerWalkRight();
 } else {
 return resources->getPlayerStaticRight();
 }
 } else {
 if (this->movingLeft) {
 return resources->getPlayerWalkLeft();
 } else {
 return resources->getPlayerStaticLeft();
 }
 }
 }

 */

Personaje::~Personaje() {
	//delete this->mainCharacterBody;
}

