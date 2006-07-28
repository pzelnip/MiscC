
CC = gcc

CFLAGS = -Wall -ansi


All : testList testHash
	echo Done

testHash : hash.o testHash.o comps.o
	$(CC) -o testHash hash.o testHash.o comps.o

hash.o : hash.c hash.h
	$(CC) $(CFLAGS) -c hash.c

testHash.o : testHash.c hash.h comps.h
	$(CC) $(CFLAGS) -c testHash.c

testList : list.o testlist.o comps.o
	$(CC) -o testList list.o testlist.o comps.o

list.o : list.c list.h
	$(CC) $(CFLAGS) -c list.c

testlist.o: testlist.c list.h comps.h
	$(CC) $(CFLAGS) -c testlist.c

comps.o : comps.c comps.h
	$(CC) $(CFLAGS) -c comps.c

clean :
	rm *.o
	rm -f testList testHash
	# in case we're under Windows
	rm -f testList.exe testHash.exe
