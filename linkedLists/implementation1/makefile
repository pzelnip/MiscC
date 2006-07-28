
# First specify the compiler to use:
CC = gcc

# And now the compiler flags to use:
CFLAGS = -Wall -ansi

# the default target, which specifies that we are to build three different executables
# Once done, the "echo done" command is executed to echo "Done" on the screen indicating
# that the procedure is complete

All : StackTest LinkedListTest NodeTest
	echo Done

# Lets do the three linking commands first:

StackTest : Node.o NodeData.o LinkedList.o StackTest.o Stack.o
	$(CC) -o StackTest Node.o NodeData.o LinkedList.o StackTest.o Stack.o 

LinkedListTest : Node.o NodeData.o LinkedList.o LinkedListTest.o
	$(CC) -o LinkedListTest Node.o NodeData.o LinkedList.o LinkedListTest.o

NodeTest : NodeTest.o Node.o NodeData.o
	$(CC) -o NodeTest NodeTest.o Node.o NodeData.o


# now each of the .o targets:

StackTest.o : StackTest.c Stack.h
	$(CC) $(CFLAGS) -c StackTest.c

LinkedListTest.o : LinkedListTest.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedListTest.c

NodeTest.o : NodeTest.c Node.h
	$(CC) $(CFLAGS) -c NodeTest.c

Stack.o : Stack.c Stack.h LinkedList.h NodeData.h
	$(CC) $(CFLAGS) -c Stack.c

LinkedList.o : LinkedList.c LinkedList.h Node.h NodeData.h
	$(CC) $(CFLAGS) -c LinkedList.c

Node.o : Node.c Node.h NodeData.h
	$(CC) $(CFLAGS) -c Node.c

NodeData.o : NodeData.c NodeData.h 
	$(CC) $(CFLAGS) -c NodeData.c


# and finally the "clean" target for removing all compiled files from the directory
clean :
	rm Node.o NodeData.o LinkedList.o StackTest.o Stack.o LinkedListTest.o NodeTest.o
	rm StackTest LinkedListTest NodeTest
