

s-talk: myList.o s-talk.o 
	gcc -o s-talk myList.o s-talk.o -lpthread

myList.o: myList.h myList.c
	gcc -c myList.c

s-talk.o: s-talk.h s-talk.c
	gcc -c s-talk.c

clean:
	rm -f s-talk *.o
