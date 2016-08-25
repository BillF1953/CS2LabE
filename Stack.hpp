/*********************************************************************
** Program Filename : Stack Header
** Author : Tyler Forrester
** Date : 7 / 24 / 2016
* * Description : A file that creates a linked structure then removes last element add first
** Input : integers
** Output : printout of integer list
** Citations : 
********************************************************************/



#ifndef STACK_HPP
#define STACK_HPP
#include "Node.hpp" 
#include <iostream>
class Stack {
private: 
	void insertAsFirstElement(node *& head, node *& back, int num); 

public:
	bool isEmpty(node *head);
	void push(node *& head, node *& back, int num);
	int peek(node *& back);
	void pop(node *& head, node *& last);


};




#endif  //!1

