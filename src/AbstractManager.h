/*
 * AbstractManager.h
 *
 *  Created on: 15 juin 2014
 *      Author: nicolaslambert
 */

#ifndef ABSTRACTMANAGER_H_
#define ABSTRACTMANAGER_H_

template<typename T>
class AbstractManager {
protected:
	// Constructeur/destructeur
	AbstractManager() {
	}
	~AbstractManager() {
	}
public:
	// Interface publique
	static T *getInstance() {
		if (0 == _singleton) {
			_singleton = new T;
		}

		return (static_cast<T*>(_singleton));
	}
	static void kill() {
		if (0 != _singleton) {
			delete _singleton;
			_singleton = 0;
		}
	}

private:
	// Unique instance
	static T *_singleton;

};

template<typename T>
T *AbstractManager<T>::_singleton = 0;

#endif /* ABSTRACTMANAGER_H_ */
