#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "Personaje.h"
#include "../game/BolaDeNieve.h"
#include "../common/client_handler.h"
#include <vector>
#include "../common/CommandCode.h"

using std::vector;
// Jugador principal
class Jugador: public Personaje {
private:

	char * name;
	vector<KeyCode> keyCode;
	Client_handler * client;

	bool offline;

	void evaluateAnimation();



	/*
	 const float VELOCIDAD_MAXIMA_BUFF_X = VELOCIDAD_MAXIMA_DEFAULT_X * 1.5;
	 */

public:
	void updateOnClientUserStats();

	int lives;
	int score;

	int keyRequestSend;

	int getPlayerLives();
	int getPlayerScore();

	void setOffline(bool isOffline);
	bool isOffline();

	Jugador(Client_handler * client, char * name);

	void setClient(Client_handler * client);

	char * getName();

	void addKeyCode(KeyCode keyCode);
	void apllyCodes();

	char * getPlayerName();

	Client_handler * getClient();

	char tipoDeObjeto; // Para contact listener.
};

#endif /* JUGADOR_H_ */
