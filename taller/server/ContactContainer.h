/*
 * ContactContainer.h
 *
 *  Created on: Nov 3, 2014
 *      Author: maxi
 */

#ifndef SERVER_CONTACTCONTAINER_H_
#define SERVER_CONTACTCONTAINER_H_

class ContactContainer {
public:
	static const int POLYGON = 1;
	static const int JUGADOR = 2;
	static const int SENSORDELPIE = 3;

	int type;
	void *containedThing;

	ContactContainer(int typeOfThing, void *contained);
};

#endif /* SERVER_CONTACTCONTAINER_H_ */