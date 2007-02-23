#ifndef __RUNNABLE_H__
#define __RUNNABLE_H__

/* 

Code taken from: http://sourceware.org/ml/pthreads-win32/2001/msg00083.html 

Modified to remove the void* return mechanisms, it is now expected that
subclasses will provide a getResult() or some such method to get results
of threads.  This will help improve type-safety and reduce the risk of 
memory leaks at the expence of less flexibility (you can't do getResult() 
from a Runnable pointer)

*/

//runnable.h
//----------
#include <assert.h>
#include <iostream>
#include <pthread.h>

// the C-style function which will be passed to pthread_create
extern "C" void *runnable_exec_redirector(void *arg);

class Runnable
{
public:
	bool start_thread();
	bool join_thread(void);
	
	Runnable() : _id_valid(false) { };
	virtual ~Runnable() { assert( !_id_valid ); };


protected:
	// Subclasses will have to override this with the thread logic
	virtual void run() = 0;

	//allow this function to access class details and run method
	friend void *runnable_exec_redirector(void *arg);

protected:
	bool      _id_valid;	// is the thread in a valid (ie runnable) state?
	pthread_t _thread_id;	// the pthread thread id of this thread
};

#endif
