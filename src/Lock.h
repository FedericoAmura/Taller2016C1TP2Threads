/*
 * Lock.h
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#ifndef LOCK_H_
#define LOCK_H_

#include "Mutex.h"

class Lock {
private:
	Mutex &m;

public:
	explicit Lock(Mutex &m);

	~Lock();

private:
	Lock(const Lock&);
	Lock& operator=(const Lock&);
};

#endif /* LOCK_H_ */
