/*********************************************************************
** Program Filename: main LabFa
** Author: Tyler Forrester
** Date: 7/22/2016
** Description: The driver function for demontrated a stack structure and a queue strucutre
** Input: User Input
** Output: Prints list of Integers
** Citation : C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
**********************************************************************/


#include <iostream>
#include "InputValid.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

char menu();
int getChoice(InputValid valid);
bool remove(node *&head, node *&last, Stack stack);
void continueOn(InputValid valid);
bool remove(node *&head, node *&last, Queue queue);
/*********************************************************************
** Function: main
** Description: Displays menu of options for adding ints, showing and removing ints in a queue and a stack
** Paramters: none
** Pre-Conditions: Start of program
** Post-Conditions: Rest of program
** Citation: Starting Out C++: Early Objects (8th Edition) Program 6-14 Gaddis P. 352
** C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/



int main() {
	InputValid valid = InputValid();   // bring in validation class
	node *head = NULL;  // initializes head pointer to null
	node *back = NULL; // intializes back pointer to null
	node *headQ = NULL;  // initializes head Queue pointer to null
	node *backQ = NULL; // intializes back Queue pointer to null
	Stack stack = Stack();
	Queue queue = Queue();
	cout << "\nWelcome to Assignment1\n";
	int choice = 0;
	do {

		menu(); // display menu
		int choice = getChoice(valid); // get choice
		int num = 0; // initialize int

		if (choice == 3) {

			break;   // quit on 3

		}

		switch (choice) // switch 
		{

		case 1:{ cout << "Please enter your list of integers: ";  // Prompts user for a list of integers
		//	int length = 0;
		//	length = valid.validateInt(); // uses input validation file from Lab A to validate int
			char quit;
			//	cout << "Your list is " << length << " numbers.\n";
			cout << "Please enter q to indicate the end of the list.\n";  
			while (quit != 'q')
			{
				num = valid.validateInt();
				stack.push(head, back, num); // add number to stack
				queue.addBack(headQ, backQ, num); // add number to stack
				cout << "Continue (q to quit)?\n"; // prompts user to end list
				quit = valid.validateChar();
			}

			cout << "Your List has been entered.\n";  
			continueOn(valid);
			cout << "Displaying your stack structure\n ";

			while (!(stack.isEmpty(head))) {  // shows and then removes nodes until stack is empty

				cout << stack.peek(back) << " ";
				stack.pop(head, back);

			}
			cout << endl;
			continueOn(valid);

			cout << "Displaying your queue structure\n";

			while (!(queue.isEmpty(headQ))) {

				cout << queue.getFront(headQ) << " ";
				queue.removeFront(headQ, backQ);        // shows and then removes nodes until queue is empty

			}
			cout << endl;

			continueOn(valid);

			if (stack.isEmpty(head)) {

				cout << "There are no numbers left in your Stack list\n"; // checks if stack is empty

			}

			if (queue.isEmpty(headQ)) {

				cout << "There are no numbers left in your Queue list\n"; // checks is queue is emtpy

			}


			cout << endl << endl;
			break;
		}
		case 2: { cout << "Attempt to print out N+1 values where N = 0.\n";
			cout << "This is the queue " << queue.getFront(headQ) << "\n ";  // attempt to break queue getfront()
			cout << "This is the stack " << stack.peek(back) << "\n "; // attempts to  break stack.peek()
			break; }
		}




	} while (true); // breaks on 2

	cout << "Successfully Exit Program\n";
	if (!(stack.isEmpty(head))) {
		while (remove(head, back, stack)); // frees allocated memory on exit (if any left)
	}
	if (!(queue.isEmpty(headQ))) {
		while (remove(headQ, backQ, queue)); // frees allocated memory of queue (if any left)
	}
	
}


/*********************************************************************
** Function: displayMenu
** Description: Displays Menu of Options for Sum Game
** Parameters: void
** Pre-Conditions: Start of Program
** Post-Conditions: getChoice()
** Citation: Starting Out C++: Early Objects (8th Edition) Program 6-14 Gaddis P. 352
*********************************************************************/


char menu() {


	cout << "\nPlease Select a Number\n\n";
	cout << "1. Store and Display an Integer List.\n";
	cout << "2. Try to print out an Undefined Node\n"; 
	cout << "3. Quit the Program.\n\n";


}
/*********************************************************************
** Function:  getChoice
** Description: gets number of Choice
** Parameters:  InputValid
** Pre-Conditions: DisplayMenu()
** Post-Conditions: Switch and Array Entry
** Citation: Starting Out C++: Early Objects (8th Edition) Program 6-14 Gaddis P. 352
*********************************************************************/


int getChoice(InputValid valid) {

	int choice;
	choice = valid.validateInt();
	while (choice < 1 || choice > 4) {

		cout << "The only valid choices are 1-4. Please re-enter.\n";
		choice = valid.validateInt();

	}

	return choice;


}

/*********************************************************************
** Function:  continueOn
** Description: Pauses program after tasks
** Parameters: InputValid
** Pre-Conditions: switch case 1, case 2 and case 3
** Post-Conditions: displaymenu()
** Citation:
*********************************************************************/

void continueOn(InputValid valid) {
	char entry = '0';
	do {


		cout << "Please enter 'c' to continue.\n";
		entry = valid.validateChar();



	} while (entry != 'c');

}

/*********************************************************************
** Function: remove
** Description: frees memory on exit
** Paramters: node * &head, node *&back Stakc stack
** Pre-Conditions: Quit the Program
** Post-Conditions: Exit
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

bool remove(node *&head, node *&last, Stack stack) {

	if (stack.isEmpty(head)) {
		//cout << "A node never existed" << endl;

	}
	else if (head == last) { // last delete when pointer->next points to itself
		delete head; // delete
		head == NULL;  // set head to Null
		last == NULL;  // set last to null
		return false; // return false to break loop
	}

	else
	{

		node *temp = head;  // set node pointer equal to head
		head = head->next;  // set move head to next node
		delete temp;  // delete old head
		return true;  // continue to delete

	}


}

/*********************************************************************
** Function: remove
** Description: frees memory on exit for queue
** Paramters: node * &head, node *&back Queue queue
** Pre-Conditions: Quit the Program
** Post-Conditions: Exit
** Citation: C++ Tutorial: Linked Lists, adding, removing, displaying Brandon Labuschagne https://www.youtube.com/watch?v=U-MfAoL6qjM May 28 2013
*********************************************************************/

bool remove(node *&head, node *&last, Queue queue) {

	if (queue.isEmpty(head)) {
		//cout << "A node never existed" << endl;

	}
	else if (head == last) { // last delete when pointer->next points to itself
		delete head; // delete
		head == NULL;  // set head to Null
		last == NULL;  // set last to null
		return false; // return false to break loop
	}

	else
	{

		node *temp = head;  // set node pointer equal to head
		head = head->next;  // set move head to next node
		delete temp;  // delete old head
		return true;  // continue to delete

	}


}