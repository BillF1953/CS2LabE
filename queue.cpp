/*********************************************************************
** Program Filename : Queue CPP
** Author : Tyler Forrester
** Date : 7 / 24 / 2016
* * Description : A file that creates a linked structure then removes elements in a first in first out manner
** Input : integers
** Output : printout of integer list
** Citations :
********************************************************************/


#include "Queue.hpp"
/*********************************************************************
** Function: isEmpty
** Description: Checks if a Node has been created
** Paramters: node * head
** Pre-Conditions: case 2 and case 3 of switch
** Post-Conditions: Rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

bool Queue::isEmpty(node * head)
{
	if (head == NULL)
		return true;
	else
		return false;

}
/*********************************************************************
** Function: insertAsFirstElement
** Description: creates node, inserts char, points all pointer to first node except temp->next which points to NULL
** Paramters: node * &head, node *&back, int num
** Pre-Conditions: Insert Node
** Post-Conditions: Rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

void Queue::insertAsFirstElement(node *& head, node *& back, int num)
{

	node *temp = new node;  // create first node for first element
	temp->num = num;  // assign value to temps char
	temp->next = NULL;   // assigns pointer to null
	head = temp;   // head (start) = temp 
	back = temp;  // back (end) = temp

}

/*********************************************************************
** Function: addBack
** Description: calls firstElement to create first node or creates node and points back->next to new variable, keeps temp->next pointed to null
** sets back to new node
** Paramters: node * &head, node *&back, int num
** Pre-Conditions: Insert Node
** Post-Conditions: Rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

void Queue::addBack(node *& head, node *& back, int num)
{
	if (isEmpty(head)) {
		insertAsFirstElement(head, back, num); // if empty calls insert As FirstElement //consider doing this in main

	}
	else {
		node *temp = new node;  // creates new node
		temp->num = num;  // assigns pass num
		temp->next = NULL;  // assigns temp->next to null (single linked list)
		back->next = temp;   // moves the last pointer to point at the new temp
		back = temp;   //moves back forward

	}


}

/*********************************************************************
** Function: removeFront
** Description: deletes head after its been displayed
** Paramters: node * &head, node *&back
** Pre-Conditions: getFront()
** Post-Conditions: 
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

void Queue::removeFront(node *& head, node *& last)
{
	if (isEmpty(head)) {
		//cout << "A node never existed" << endl;

	}
	else if (head == last) { // last delete when pointer->next points to itself
		delete head; // delete
		head = NULL;  // set head to Null
		last = NULL;  // set last to null

	}

	else
	{

		node *temp = head;  // set node pointer equal to head
		head = head->next;  // set move head to next node
		delete temp;  // delete old head
	

	}


	
}

/*********************************************************************
** Function:  getFront
** Description: If num has been removed, deals with empty queue cases otherwise returns num
** Paramters: node * &head
** Pre-Conditions: case 1, case 2
** Post-Conditions: removeFront()
** Citation:
*********************************************************************/

int Queue::getFront(node *&head) { // passes head

	try {
		if(isEmpty(head)) {

		throw -65536;

	}
		return(head->num);  // Presents head as the first member of the queue
	}
	catch (int x) {

		std::cout << "Tried to Print Out an Undefined Element\n";

	}
	

}
