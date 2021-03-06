/**
 client_handler.h

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
#ifndef CLIENT_HANDLER_H_
#define CLIENT_HANDLER_H_

#include "socket.h"
#include "message_command.h"
#include <string>
#include <thread>
#include <signal.h>
#include "Message.h"
#include <mutex>

using std::thread;
class DataObserver;
using std::mutex;

typedef char status_t;

class Client_handler {

private:

	Socket * _socket;
	thread clientThread;
	bool threadLoop;

	static void threadFunction(Client_handler * client);

public:
	char userIndex;

	Client_handler();
	virtual ~Client_handler();

	void setSocket(Socket * socket);
	bool isConnected();

	bool isEmpty();

	void startLoop();

	bool runListen();

	void waitThreadEnd();

	bool is_valid();

	void stop();

	bool send_message(Message * msg);

	void setDataObserver(DataObserver *dO);
private:
	DataObserver * dataObserver;
	//mutex sendingMutex;
};

#endif /* CLIENT_HANDLER_H_ */
