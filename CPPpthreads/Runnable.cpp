/* code taken from: http://sourceware.org/ml/pthreads-win32/2001/msg00083.html */


#include "runnable.h"

/*
start_thread - spawns the thread and adds it to the thread library's job
	queue.  Returns true if successful, false if error occurred.
*/
bool Runnable::start_thread()
{
    if (!_id_valid) {
        if (0 == pthread_create(
          &_thread_id, 0,
          runnable_exec_redirector,
          static_cast<void *>(this)
        )) {
            _id_valid = true;
        }
    }
    return _id_valid;
}

/*
join_thread - waits on this thread for completion.  Returns true if thread
	terminated correctly, false otherwise.  Note: it is safe to call
	join_thread before start_thread (if necessary, join_thread will 
	spawn the thread), but because join_thread is a blocking method
	doing join_thread before start_thread would reduce your program to
	be essentially single-threaded
*/
bool Runnable::join_thread()
{
    bool ret = false;

    // if start_thread() hasn't been called before, call it to init thread
    if (!_id_valid)
        start_thread();

    // if thread was started, join
    if (_id_valid) {
        pthread_join(_thread_id, NULL);
        _id_valid = false;
        ret = true;
    }
    return ret;
}

/*
runnable_exec_redirector - the C-style function which is passed to pthread_create
	Note: This function *ALWAYS* returns false.  Note #2:  Clients of the 
	Runnable class should *NEVER* call this function directly (only 
	indirectly through start_thread()) 
*/
extern "C" void *runnable_exec_redirector(void *arg)
{
    assert (arg != 0);
    Runnable *obj = static_cast<Runnable *>(arg);
    assert (obj != 0);
    obj->run();
    return NULL;
}
