#pragma once
#include <exception>
using namespace std;
template <class T>
struct node {
	T data;
	node* next;
};

template <class T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void addItem(T);
	T* getItem(T);
	bool isInList(T);
	bool isEmpty();
	int size();
	T seeNext();
	T seeAt(int);
	void reset();
	void display();
private:
	int location;
	node<T>* list; // holds the list
};

template<class T>
inline LinkedList<T>::LinkedList()
{
	location = 0;
	list = NULL; // initialize node with nothing in it
}

template<class T>
inline LinkedList<T>::~LinkedList()
{
	// something probably goes here but idk what
}

template<class T>
inline void LinkedList<T>::addItem(T dat)
{
	// start by adding new item to front of list
	node<T>* n = new node<T>;
	n->data = dat;
	n->next = list;
}

template<class T>
inline T* LinkedList<T>::getItem(T info)
{
	// create temporary nodes
	node<T>* temp = list;
	node<T>* prev = temp;
	// this is not maximally efficient since the list is sorted, 
	// one does not need to go through the whole list
	while (temp != NULL) {
		if (temp->data == info) {
			prev->next = temp->next; // shift address to previous
			return (T*)temp;
		}
		else {
			prev = temp;
			temp = temp->next;
		}
	}
	return nullptr;
}

template<class T>
inline bool LinkedList<T>::isInList(T info)
{
	bool found = false;
	node<T>* comparator = list;
	while (!found) {
		if (comparator == NULL)
			return false;
		else if (comparator->data == info)
			return true;
		else
			comparator = comparator->next;
	}
}

template<class T>
inline bool LinkedList<T>::isEmpty()
{
	if (list == NULL)
		return true;
	return false;
}

template<class T>
inline int LinkedList<T>::size()
{
	int num = 0;
	node<T>* iterate = list;
	while (iterate != NULL) {
		num++;
		iterate = iterate->next;
	}
	return num;
}

// returns next item from location
template<class T>
inline T LinkedList<T>::seeNext()
{
	node<T>* hold = list;
	for (int j = 0; j < location; j++) {
		hold = hold->next;
		if (hold == NULL)
			throw ItemDNEException();
	}
	location++;
	return hold->data;
}

template<class T>
inline T LinkedList<T>::seeAt(int at)
{
	node<T>* hold = list;
	for (int i = 0; i < at; i++) {
		hold = hold->next;
		if (hold == NULL)
			throw ItemDNEException();
	}
	location = at + 1; // set location to point to next item
	return hold->data;
}

template<class T>
inline void LinkedList<T>::reset()
{
	location = 0;
}

template<class T>
inline void LinkedList<T>::display()
{
	node<T>* h = list;
	while (h != NULL) {
		h->data.display();
		h = h->next;
	}
}

class ItemDNEException : public exception {
public:
	virtual const char* what() const throw() {
		return "Item does not exist.";
	}
};

class LocationDNEException : public exception {
public:
	virtual const char* what() const throw() {
		return "Location does not exist.";
	}
};