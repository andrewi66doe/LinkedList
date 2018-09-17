#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = NULL;
}

/*
	Print the contents of the linked list
*/
void LinkedList::printList()
{
	access_mtx.lock();

	for(IntNode *i=head;i != NULL; i = i->next){
		std::cout << i->value << "->";
	}
	std::cout << std::endl;
	access_mtx.unlock();
}


/*
	Insert a value at the end of the list
*/
void LinkedList::insertVal(int val)
{
	access_mtx.lock();
	IntNode *last;

	// If the list is empty
	if(head == NULL){
		head = new IntNode(val);
	// Otherwise get the node at the end of the list and add a value
	}else{
		last = lastNode();
		last->next = new IntNode(val);
	}
	access_mtx.unlock();
}

/*
	Removes the first instance of a specified value from the linked list.
*/
void LinkedList::deleteVal(int val)
{
	access_mtx.lock();

	IntNode *last = head;
	IntNode *current = head;

	if(head == NULL){
		throw "Error: Deletion from empty list";
	}else if(head->value == val){
		current = head;
		head = head->next;
		delete current;
	}

	bool found = false;

	while(current != NULL){
		if(current->value == val){
			last->next = current->next;
			delete current;
			found = true;
			break;
		}
		last = current;
		current = current->next;
	}

	if(found == false){
		throw "Error: Value does not exist in list";
	}

	access_mtx.unlock();
}

/*
	Returns the last node in the linked list.
*/
IntNode* LinkedList::lastNode()
{
	IntNode *iter = head;
	while(iter->next != NULL){
		iter = iter->next;
	}
	return iter;
}

/*
	When the linked list is destroyed free all memory in the list
*/
LinkedList::~LinkedList()
{
	IntNode *next, *current;
	current = head;

	while(current != NULL){
		next = current->next;
		delete current;
		current = next;
	}
}
