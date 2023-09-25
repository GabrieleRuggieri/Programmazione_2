#ifndef CODA_H
#define CODA_H

#include<iostream>

#include "Nodo.h"

using namespace std;

class Coda{

protected:

	int size = 0;
	Node<double>* head;
	Node<double>* tail;

public:

	Coda(){

		head = nullptr;
		tail = nullptr;
	}

	bool isEmpty(){

		return size == 0;
	}

	void enqueue(double val){

		if(isEmpty())
		{
			head = new Node<double>(val);
			tail = head;
			size ++;
			return;
		}
		
		Node<double>* toinsert = new Node<double> (val);
		tail->next = toinsert;
		tail = toinsert;
		size ++;

		return;
	}

	Node<double>* dequeue(){

		if(isEmpty())
			return nullptr;

		if(head == tail) //Se c'è un solo elemento 
		{
			Node<double>* tmp = head;
			head = nullptr;  //Annullo i collegamenti
			size --;

			return tmp;
		}

		Node<double>* tmp = head;
		head = head->next;
		size --;

		return tmp;
	}


	friend ostream& operator<< (ostream& os, Coda& c){

			os << "\nNumero operandi: " << c.size << endl;
			
			if(c.isEmpty())
			{
				os << "Empty Queue" << endl;
				return os;
			}

			Node<double>* ptr  = c.head;
			int idx = 1;
			
			os << "\nQueue:" << endl;
			while(ptr)
			{
				os << "\tOperando n˚" << idx << ": " << *ptr << endl;
				ptr = ptr->get_next();
				idx ++;
			}
			os << "\nEnd Queue" << endl;
			
			return os;
		}

};

#endif