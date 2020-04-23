Lab9: main.o Executive.o leftistHeap.o skewHeap.o BNode.o
	g++ -g -std=c++11 -Wall main.o Executive.o leftistHeap.o skewHeap.o BNode.o -o Lab9

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -g -std=c++11 -Wall -c Executive.cpp

leftistHeap.o: leftistHeap.h leftistHeap.cpp
	g++ -g -std=c++11 -Wall -c leftistHeap.cpp

skewHeap.o: skewHeap.h skewHeap.cpp
	g++ -g -std=c++11 -Wall -c skewHeap.cpp

BNode.o: BNode.h BNode.cpp
	g++ -g -std=c++11 -Wall -c BNode.cpp

clean:
	rm *.o Lab9
