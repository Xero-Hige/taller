#include "Jugador.h"
#include <math.h>
#include <iostream>

// Inicializa Jugador.
Jugador::Jugador(b2World * gameWorld, double posX, double posY) :
		Personaje(gameWorld) {
	//Defino forma, posicion y tamanyo del body para el Personaje.

	// TODO: permitir ponerlo en una posicion especifica.

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(posX, posY);
	bodyDef.fixedRotation = true;

	body = gameWorld->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;

	double longX = 1.4f;
	double longY = 1.8f;

	dynamicBox.SetAsBox(longX, longY);

	//TODO: mejorar medidas.
	this->size = b2Vec2(longX * 2.5, longY * 2);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1;
	fixtureDef.friction = 0;

	b2Fixture *bodyFixture = body->CreateFixture(&fixtureDef);
	bodyFixture->SetUserData((void*) 3);

	dynamicBox.SetAsBox(longX - 0.1, 0.4, b2Vec2(0, -longY), 0);
	fixtureDef.density = 0;
	fixtureDef.isSensor = true;
	b2Fixture * footSensor = body->CreateFixture(&fixtureDef);
	footSensor->SetUserData((void*) 2);

	// Redefino velocidades a las ajustadas para el jugador principal.
	movementSpeedX = MOVEMENT_SPEED_X;
	movementSpeedY = MOVEMENT_SPEED_Y;

	//buffVelocidad = false;
}

b2Vec2 Jugador::getSize() {
	return this->size;
}

// Devuelve true si tiene buff de velocidad.
/*
 bool Jugador::tieneBuffVelocidad(){
 return buffVelocidad;
 }
 */

// Le otorga el buff de velocidad.
/*
 void Jugador::darBuffVelocidad(){
 velocidadMaximaX = VELOCIDAD_MAXIMA_BUFF_X;
 buffVelocidad = true;
 }
 */

// Le quita el buff de velocidad.
/*
 void Jugador::quitarBuffVelocidad(){
 velocidadMaximaX = VELOCIDAD_MAXIMA_DEFAULT_X;
 buffVelocidad = false;
 }
 */

/*
 BolaDeNieve Jugador::disparar(){
 return BolaDeNieve(estaMirandoParaLaDerecha(), posicion);
 }
 */
