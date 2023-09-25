#ifndef NODO_H
#define NODO_H

#include "Giocatore.h"

class Node{

	Giocatore val;
	Node* next;

	friend class List;

	public:

		Node(Giocatore val):val(val){ next = nullptr; }

		Giocatore get_val(){ return this->val; }

		Node* get_next(){ return this->next; }

		friend ostream& operator<< (ostream& os, Node& n){ return os << n.val << endl; }
};

#endif