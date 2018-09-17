all: main.cpp LinkedList.cpp 
	g++ main.cpp LinkedList.cpp -std=c++11 -lpthread -o main

clean: 
	$(RM) main
