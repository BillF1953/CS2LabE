/*********************************************************************
** Program Filename : Stack Header
** Author : Tyler Forrester
** Date : 7 / 24 / 2016
* * Description : A file that creates a linked structure then removes last element add first
** Input : integers
** Output : printout of integer list
** Citations :
********************************************************************/


#include "Stack.hpp"
using std::cout; 
using std::endl; 
/*********************************************************************
** Function: isEmpty
** Description: Checks if a Node has been created
** Paramters: node * head
** Pre-Conditions: case 1 and case 2
** Post-Conditions: Rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

bool Stack::isEmpty(node*head) {

	if (head == NULL)
		return true;
	else
		return false;

}

/*********************************************************************
** Function: insertAsFirstElement
** Description: creates node, inserts char, points all pointer to first node except temp->next which points null
** Paramters: node * &head, node *&back, int num
** Pre-Conditions: Insert Node
** Post-Conditions: Rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

void Stack::insertAsFirstElement(node  *&head, node *&back, int num) {

	node *temp = new node;  // create first node for first element
	temp->num = num;  // assign value to temps char
	temp->next = NULL;   // assign s point next to itself 
	head = temp;   // head (start) = temp 
	back = temp;  // back (end) = temp

}


/*********************************************************************
** Function: push
** Description: calls firstElement to create first node or creates node and points back->next to new variable, points temp-> next to null
** sets back to new node
** Paramters: node * &head, node *&back, int num
** Pre-Conditions: Insert Node
** Post-Conditions: Rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/
void Stack::push(node *&head, node *&back, int num) { // pass by reference so they can be modified

	if (isEmpty(head)) {
		insertAsFirstElement(head, back, num); // if empty calls insert As FirstElement //consider doing this in main

	}
	else {
		node *temp = new node;  // creates new node
		temp->num = num;  // assigns pass num
		temp->next = NULL;  // assigns temp->next to head (i.e. creates a circle with the last element always point to the first element
		back->next = temp;   // moves the last pointer to point at the new temp
		back = temp;   // sets back to this node

	}

}

/*********************************************************************
** Function:  peek
** Description: If num has been removed, deals with empty stack cases otherwise prints out 
** Paramters: node * &back
** Pre-Conditions:  choice = 1 or 2
** Post-Conditions: Rest of program
** Citation:
*********************************************************************/

int Stack::peek(node *&back) { // passes head

	try {
		if (isEmpty(back)) {

			throw -65536;  // throw error if peek is run on empty structure

		}
		return(back->num);  // Presents head as the first member of the queue
	}
	catch (int x) {

		std::cout << "Tried to Print Out an Undefined Element\n";  // Prints out error Message

	}


}

/*********************************************************************
** Function: pop
** Description: removes top item
** Paramters: node * &head, node *&last
** Pre-Conditions: peek()
** Post-Conditions: rest of program
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
** Citation: Linked Lists Part 7: Delete Last List Node Method (Java) Nathan Schultz June 6 2014 https://www.youtube.com/watch?v=qWgiwpfB_u4
*********************************************************************/

void Stack::pop(node *&head, node *&last) {

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
	//	node * current = head->next; // set current to head next pointer
		node * previous = head; // set previous to head 
		while (previous->next->next != NULL) { // until last element

			previous = previous->next;   // move previous to current
		//	current = current->next;  // move current forward
		
		}

		node *temp = previous->next;  // set node pointer equal to last element
		previous->next = NULL;  // set move head to next node
		last = previous; // reset back pointer to previous 
		delete temp;  // delete old head
	
	}


}