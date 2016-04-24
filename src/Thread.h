/*
 * Thread.h
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>

//Clase para correr metodos de objetos en hilos independientes
class Thread {
private:
	pthread_t thread;

	static void *runner(void *data) {
        Thread *self = (Thread*)data;
        self->run();
        return NULL;
    }

public:
	Thread();

	//Metodo que arranca la ejecucion de run() en un hilo independiente
	void start();

	//Join al hilo, para esperar a que termine
	void join();

	//Metodo virtual, la clase hija debe implementar para correrlo en otro hilo
	virtual void run() = 0;

	virtual ~Thread();

private:
	Thread(const Thread&);
	Thread& operator=(const Thread&);
};

#endif /* THREAD_H_ */
