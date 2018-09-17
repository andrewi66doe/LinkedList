#include <iostream>
#include <cstdlib>
#include <mutex>
#include <unistd.h>
#include "IntNode.h"

class LinkedList{
public:
	LinkedList();
	~LinkedList();
	void insertVal(int val);
	void deleteVal(int val);
	void printList();
private:
	std::mutex access_mtx;

	IntNode *lastNode();
	IntNode *head;
};