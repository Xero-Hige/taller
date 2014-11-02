/*
 * ServerData.cpp
 *
 *  Created on: 31/10/2014
 *      Author: demian
 */

#include <ServerData.h>
#include "Jugador.h"
#include "Data.h"
#include <string>

ServerData::ServerData(Server * sv) {
	this->sv = sv;
}

void ServerData::closeConnection(Client_handler * client){

}

void ServerData::dataArribal(Message * m, Client_handler * client){
	Message envio = Message();
	//std::cout<<"Re: "<<m->getMessageLength()<<" bytes - "<<m->getMessageData()<<std::endl;
	char cCode = m->getCommandCode();
	if(cCode == IM_LOGGED){

		envio.addCommandCode(SERVER_DATA);
		envio.addCharArray("Un mapa de snowBross\0", 21);
		envio.addChar(4); //Max player
		char jugando = Data::world->getPlayerList().size();
		envio.addChar(jugando); //Jugando!
		client->send_message(&envio);
		return;
	}

	if(cCode == LOGGIN_GAME){

		vector<Jugador *> lPlayer = Data::world->getPlayerList();
		char * playerName;
		m->getCharArray(&playerName);

		string nm(playerName);

		for(auto * p : lPlayer){
			string oPlayer(p->getName());

			if(oPlayer.compare(nm) == 0){
				envio.addCommandCode(ERROR_MESSAGE);
				envio.addCharArray("Jugador Online\0", 15);
				envio.addCharArray("El nombre que intenta utilizar se encuentra en uso\0", 51);
				client->send_message(&envio);
				return;
			}
		}

		/*
		Jugador * j = new Jugador(client->userIndex, playerName);
		Data::world->addPlayer(j);
		 */

		//Mandamos un mensaje por poligono!
		envio.addCommandCode(INITIALIZE_MAP);
		envio.addFloat(&Data::world->getBox2DWorldSize()->x);
		envio.addFloat(&Data::world->getBox2DWorldSize()->y);

		client->send_message(&envio);

		char polNumber = Data::world->getPolygonList().size();

		vector<Polygon*> polList = Data::world->getPolygonList();

		for(auto * p : polList){
			Message * mapData = new Message();
			mapData->addCommandCode(ADD_MAP_DATA);

			char vNum = p->getPointList().size();
			mapData->addChar(vNum);

			for(auto * ver : p->getPointList()){
				mapData->addFloat(&ver->x);
				mapData->addFloat(&ver->y);
			}

			client->send_message(mapData);
			delete mapData;
		}

		Message * finalData = new Message();
		finalData->addCommandCode(INITIALIZE_GRAPHICS);
		client->send_message(finalData);
		delete finalData;
		return;
	}
}

void ServerData::errorConnection(Client_handler * client, int error){

}



ServerData::~ServerData() {
	// TODO Auto-generated destructor stub
}

