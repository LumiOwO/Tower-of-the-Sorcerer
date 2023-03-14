#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <initializer_list>
using namespace std;

// template class to implement a linked list

// node
template <class T>
class Node
{
private:
	T value;
	Node<T> *next;
public:
	// constructor
	Node(T value = T());
	// get next node
	Node<T> *getNext();
	// set next node
	void setNext(Node<T> *next);
	// get value
	T& getValue();
	// set value
	void setValue(T t);
};

// double linked list with a dummy head
template <class T>
class LinkedList
{
private:
	Node<T> *head;
	Node<T> *tail;
	int numOfNodes;
public:
	// constructor
	LinkedList();
	// copy constructor
	LinkedList(const LinkedList &list);
	// constructor by initialize list
	LinkedList(initializer_list<T> list);
	// destructor
	~LinkedList();
	// return the first node in the list
	Node<T>* begin() const;
	// return the last node in the list
	Node<T>* last() const;
	// return the size of the list
	int size() const;
	// judge whether the value is in the list
	bool contains(const T& value) const;
	// append an element at the end of the list
	void push_back(const T& value);
	// remove the given value
	void remove(const T& value);
	// clear and free all nodes
	void clear();
	// overload operator []
	T& operator[](int index) const;
	// overload operator =
	LinkedList<T>& operator=(const LinkedList& list);
};

// function definitions of Node
template <class T>
Node<T>::Node(T value)
{
	this->value = value;
	next = nullptr;
}

template <class T>
Node<T>* Node<T>::getNext()
{
	return next;
}

template <class T>
void Node<T>::setNext(Node<T> *next)
{
	this->next = next;
}

template <class T>
T& Node<T>::getValue()
{
	return value;
}

template <class T>
void Node<T>::setValue(T t)
{
	value = t;
}

// function definitions of linked list
template <class T>
LinkedList<T>::LinkedList()
{
	// get a dummy head
	head = tail = new Node<T>();
	numOfNodes = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& list)
{
	// get a dummy head
	head = tail = new Node<T>();
	numOfNodes = 0;
	// for each node in the list,
	// get a new node and copy the value 
	// then push it into this list
	for (Node<T> *p = list.begin(); p; p = p->getNext())
		this->push_back(p->getValue());
}

template <class T>
LinkedList<T>::LinkedList(initializer_list<T> list)
{
	// get a dummy head
	head = tail = new Node<T>();
	numOfNodes = 0;
	// typedef the iterator for the initializer list
	typedef decltype(list.begin()) List_Iterator;
	// push in each value in the initializer list
	for (List_Iterator i = list.begin(); i != list.end(); i++)
		this->push_back(*i);
}

template <class T>
LinkedList<T>::~LinkedList()
{
	// delete all nodes but the dummy head
	this->clear();
	// delete the dummy head
	delete head;
}

template <class T>
Node<T>* LinkedList<T>::begin() const
{
	// return the first node in the list
	return head->getNext();
}

template <class T>
Node<T>* LinkedList<T>::last() const
{
	// return the last node in the list
	return tail;
}

template <class T>
int LinkedList<T>::size() const
{
	return numOfNodes;
}

template <class T>
bool LinkedList<T>::contains(const T& value) const
{
	bool ret = false;
	// if can the value in the list
	// then return true
	for(Node<T> *p = begin(); p; p = p->getNext())
		if (p->getValue() == value)
		{
			ret = true;
			break;
		}
	return ret;
}

template <class T>
void LinkedList<T>::push_back(const T& value)
{
	// push the new node after the tail
	tail->setNext(new Node<T>(value));
	// add the number of nodes
	numOfNodes++;
	// modify the tail pointer
	tail = tail->getNext();
}

template <class T>
void LinkedList<T>::remove(const T& value)
{
	// find the node contains the value
	// and record the previous node of it
	Node<T> *prev = head;
	Node<T> *node = begin();
	// move the pointers to find it
	while (node->getValue() != value)
	{
		prev = prev->getNext();
		node = node->getNext();
	}
	// delete the node
	prev->setNext(node->getNext());
	delete node;
	// modify tail
	if (node == tail)
		tail = prev;
	// reduce the number of node
	numOfNodes--;
}

template <class T>
void LinkedList<T>::clear()
{
	// traversal the list to delete every node 
	// except the dummy head
	Node<T> *temp;
	for(Node<T> *p = begin(); p; p = temp)
	{
		temp = p->getNext();
		delete p;
	}
	// modify the head and tail
	head->setNext(nullptr);
	tail = head;
	// modify the number of nodes
	numOfNodes = 0;
}

template <class T>
T& LinkedList<T>::operator[](int index) const
{
	// get the i-th element
	Node<T> *p = begin();
	for (int i = 0; i < index; i++)
		p = p->getNext();
	return p->getValue();
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list)
{
	// if assign to itself, then do nothing
	if (this->head == list.head)
		;
	else
	{
		// clean the list
		this->clear();
		// get a new node and copy the value 
		// then push it into this list
		for (Node<T> *p = list.begin(); p; p = p->getNext())
			this->push_back(p->getValue());
	}
	// return the reference of this list
	return *this;
}

#endif