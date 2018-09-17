#include <thread>

#include "LinkedList.h"

void addValues(LinkedList *list)
{
	for(int i=0;i<15;i++){
		list->printList();
		list->insertVal(i);
	}
}

void addOtherValues(LinkedList *list)
{
		for(int i=0;i<15;i++){
			list->insertVal(i*2);
		}

}

int main(int argc, char **argv)
{
	LinkedList l;

	// Spawn three different threads
	std::thread thread1 (addValues, &l);
	std::thread thread2 (addOtherValues, &l);
	std::thread thread3 (addOtherValues, &l);

	// Threads run concurrently, all accessing the linked list

	// Synchronize threads;
	thread1.join();
	thread2.join();
	thread3.join();
	l.printList();
	return 0;
}
