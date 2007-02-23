/* 

threadTest.cpp - a sample thread class derrived from Runnable which 
illustrates the usage of the Runnable class

Author: Adam Parkin (loosely based upon code found at:
	http://sourceware.org/ml/pthreads-win32/2001/msg00083.html) 

Date: February 23, 2007

*/

#include <iostream>
#include <sstream>
#include "runnable.h"

class MyThread : public Runnable
{
    public:
	// "arguments" to threads should be passed via a constructor
        MyThread (int idIn = 42) : id (idIn) { }

	// results should be returned by a method of this class (you 
	// can call it whatever you want as it will be specific to 
	// this class)
	int getResult () const { return result; }

	// helper functions for this example.
	int getId() const { return id; }

    private:
	// internal data needed for this thread
        int id;
	int result;

	// the thread logic
        virtual void run()
        {
            // note must use osstringstream as cout can be interrupted
            // between << operators 
            std::ostringstream s;
            s   << "I am thread " << _thread_id
                << " running in context of object " << this
                << std::endl
                << "My thread id is: " << id << std::endl;
            std::cout << s.str();

            result = id * 2;
        }
};

int main()
{
	MyThread * array[10];

	std::cerr << "Default constructor\n";
	array[0] = new MyThread();
	std::cerr << "int constructor\n";
	for (int x = 1; x < 10; x++)
		array[x] = new MyThread (x);
	std::cerr << "done creating threads\n";

	// Note that we don't have to do start_thread before join_thread
	// as join_thread will create & start the thread if needed
	// however, since join_thread is a blocking call this would mean
	// that you're essentially reduced to single-threading
	std::cerr << "Starting threads...\n";
	for (int x = 0; x < 10; x++)
		array[x]->start_thread();

	std::cerr << "finished starting threads"
		<< "  Now joining...\n";

	for (int x = 0; x < 10; x++)
		array[x]->join_thread();

	std::cerr << "Threads finished, printing results...\n";
	for (int x = 0; x < 10; x++)
		std::cout << x << " -- Id: " 
			<< array[x]->getId() 
			<< " and result is: "
			<< array[x]->getResult()
			<< std::endl;

	for (int x = 0; x < 10; x++)
		delete array[x];

	return 0;
}
