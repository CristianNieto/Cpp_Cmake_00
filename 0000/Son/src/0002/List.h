//
// Created by cris on 12/09/19.
//

#ifndef INC_0002_LIST_H
#define INC_0002_LIST_H


#include "ListNode.h" // ListNode class definition
#include <iostream>
template <typename NODETYPE> class List {
private:
	ListNode<NODETYPE> *firstPtr; // pointer to first node
	ListNode<NODETYPE> *lastPtr;  // pointer to last node
	
	// utility function to allocate new node
	ListNode<NODETYPE> *getNewNode(const NODETYPE &value) {
		return new ListNode<NODETYPE>(value);
	} // end function getNewNode

public:
	// default constructor
	List() : firstPtr(nullptr), lastPtr(nullptr) {} // end List constructor
	
	// destructor
	~List() {
		if (!isEmpty()) { // List is not empty
			std::cout << "Destroying nodes ...\n";
			
			ListNode<NODETYPE> *currentPtr = firstPtr;
			ListNode<NODETYPE> *tempPtr = nullptr;
			while (currentPtr != nullptr) { // delete remaining nodes
				tempPtr = currentPtr;
				std::cout << tempPtr->data << '\n';
				currentPtr = currentPtr->nextPtr;
				delete tempPtr;
			} // end while
		}   // end if
		std::cout << "All nodes destroyed\n\n";
	} // end List destructor
	
	// insert node at front of list
	void insertAtFront(const NODETYPE &value) {
		ListNode<NODETYPE> *newPtr = getNewNode(value); // new node
		if (isEmpty())                                  // List is empty
			firstPtr = lastPtr = newPtr; // new list has only one node
		else                           // List is not empty
		{
			newPtr->nextPtr = firstPtr; // point new node to old 1st node
			firstPtr = newPtr;          // aim firstPtr at new node
		}                             // end else
	}                               // end function insertAtFront
	
	// insert node at back of list
	void insertAtBack(const NODETYPE &value) {
		ListNode<NODETYPE> *newPtr = getNewNode(value); // new node
		if (isEmpty())                                  // List is empty
			firstPtr = lastPtr = newPtr; // new list has only one node
		else                           // List is not empty
		{
			lastPtr->nextPtr = newPtr; // update previous last node
			lastPtr = newPtr;          // new last node
		}                            // end else
	}                              // end function insertAtBack
	
	// delete node from front of list
	bool removeFromFront(NODETYPE &value) {
		if (isEmpty())  // List is empty
			return false; // delete unsuccessful
		else {
			ListNode<NODETYPE> *tempPtr = firstPtr; // hold item to delete
			if (firstPtr == lastPtr)
				firstPtr = lastPtr = nullptr; // no nodes remain after removal
			else
				firstPtr = firstPtr->nextPtr; // point to previous 2nd node
			value = tempPtr->data;          // return data being removed
			delete tempPtr;                 // reclaim previous front node
			return true;                    // delete successful
		}                                 // end else
	}                                   // end function removeFromFront
	
	// delete node from back of list
	bool removeFromBack(NODETYPE &value) {
		if (isEmpty())  // List is empty
			return false; // delete unsuccessful
		else {
			ListNode<NODETYPE> *tempPtr = lastPtr; // hold item to delete
			if (firstPtr == lastPtr)               // List has one element
				firstPtr = lastPtr = nullptr;        // no nodes remain after removal
			else {
				ListNode<NODETYPE> *currentPtr = firstPtr;
				// locate second-to-last element
				while (currentPtr->nextPtr != lastPtr)
					currentPtr = currentPtr->nextPtr; // move to next node
				lastPtr = currentPtr;               // remove last node
				currentPtr->nextPtr = nullptr;      // this is now the last node
			}                                     // end else
			value = tempPtr->data;                // return value from old last node
			delete tempPtr;                       // reclaim former last node
			return true;                          // delete successful
		}                                       // end else
	}                                         // end function removeFromBack
	
	// is List empty?
	bool isEmpty() const { return firstPtr == nullptr; } // end function isEmpty
	
	// display contents of List
	void print() const {
		if (isEmpty()) // List is empty
		{
			std::cout << "The list is empty\n\n";
			return;
		} // end if
		// Fig. 19.5 |
		ListNode<NODETYPE> *currentPtr = firstPtr;
		std::cout << "The list is: ";
		while (currentPtr != nullptr) // get element data
		{
			std::cout << currentPtr->data << ' ';
			currentPtr = currentPtr->nextPtr;
		} // end while
		
		std::cout << "\n\n";
		
	} // end function print
	
}; // end class List

#endif //INC_0002_LIST_H
