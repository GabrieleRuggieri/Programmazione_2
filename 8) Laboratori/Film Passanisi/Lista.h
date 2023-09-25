#ifndef LISTA_H
#define LISTA_H

#include "Film.h"

class Node{

	Film val;
	Node* next;

	friend class List;

	public:

		Node(Film val) : val(val){

			next = nullptr;
		}	

		Node* get_next()const{

			return this->next;
		}

		friend ostream& operator<< (ostream& os, Node& n){

			os << n.val << endl;
			return os;
		}
};

class List{

		Node* head;

	public:

		List(){

			head = nullptr;
		}

		bool isEmpty(){

			return head == nullptr;
		}

		void insert_head(Film val){

			if(isEmpty())
			{
				head = new Node(val);
				return;
			}

			Node* toinsert = new Node(val);
			toinsert->next = head;
			head = toinsert;
			return;
		}

		void insert_tail(Film val){

			if(isEmpty())
			{
				cerr << "Void List" << endl;
				return;
			}

			Node* cur = head;

			while(cur->next)
				cur = cur->next;

			Node* toinsert = new Node(val);
			cur->next = toinsert;
			return;

		}

		void insert_in_order(Film val){  //Crescente

			if(isEmpty())
			{
				head = new Node(val);
				return;
			}


			if(head->val >= val)
			{
				insert_head(val);
				return;
			}

			Node* cur = head;

			while(cur->next && val >= cur->val)
			{
				if(cur->next->val >= val) //se val è maggiore del corrente ma minore del successivo
					break;

				cur = cur->next;
			}

			if(!cur->next) //Se sono uscito perchè ho finito la lista
			{
				insert_tail(val);
				return;
			}

			Node* toinsert = new Node(val);
			toinsert->next = cur->next;
			cur->next = toinsert;
			return;
		}

		void remove_head(){

			if(isEmpty())
			{
				cerr << "Empty list!" << endl;
				return;
			}

			Node* tmp = head;
			head = head->next;
			delete tmp;
			return;
		}

		void remove_tail(){

			if(isEmpty())
			{
				cerr << "Empty list!" << endl;
				return;
			}

			if(!head->next)
			{
				remove_head();
				return;
			}

			Node* cur = head;
			Node* prev = nullptr;

			while(cur->next)
			{
				prev = cur;
				cur = cur->next;
			}

			prev->next = nullptr;
			delete cur;
		}

		void remove_element(Film val){

			if(isEmpty())
			{
				cerr << "Element not found or Empty list!" << endl;
				return;
			}
			
			if(head->val == val)
			{
				remove_head();
				return;
			}

			Node* cur = head;
			Node* prev = nullptr;

			while(cur->next &&  cur->val != val)
			{
				prev = cur;
				cur = cur->next;
			}

			if(cur->val != val) //Se sono uscito perchè ho finito la lista
			{
				cerr << "Element not found or Empty list!" << endl;
				return;
			}

			prev->next = cur->next;
			delete cur;
			return;
		}

		friend ostream& operator<< (ostream& os, List& l){
			
			if(l.isEmpty())
			{
				os << "Empty list" << endl;
				return os;
			}

			Node* ptr = l.head;
			while(ptr)
			{
				os << "\t" << *ptr << endl;
				ptr = ptr->get_next();
			}
			
			return os;
		}

};



#endif