//
// Created by cris on 12/09/19.
//

#ifndef INC_0002_LISTNODE_H
#define INC_0002_LISTNODE_H

// forward declaration of class List required to announce that class
// List exists so it can be used in the friend declaration at line 13
template <typename NODETYPE> class List;
//
template <typename NODETYPE> class ListNode {
	friend class List<NODETYPE>; // make List a friend
private:
	NODETYPE data;               // data
	ListNode<NODETYPE> *nextPtr; // next node in list
public:
	// Constructor
	explicit ListNode(const NODETYPE &info) : data(info), nextPtr(nullptr) {}
	// Getter
	NODETYPE getData() const { return data; }
}; // end class ListNode

#endif //INC_0000_LISTNODE_H
