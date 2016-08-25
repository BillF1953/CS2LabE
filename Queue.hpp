/*********************************************************************
** Program Filename : Queue Header
** Author : Tyler Forrester
** Date : 7 / 24 / 2016
* * Description : A file that creates a linked structure then removes elements in a first in first out manner
** Input : integers
** Output : printout of integer list
** Citations :
********************************************************************/



#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Node.hpp"
#include <iostream>
class Queue {
private: 
	void insertAsFirstElement(node *& head, node *& back, int num);

public:
	bool isEmpty(node *head);
	void addBack(node *& head, node *& back, int num);
	void removeFront(node *&head, node *&last);
	int getFront(node *& head);

};

#endif  //!1

