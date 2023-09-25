#include "comande.h"
#ifndef LIST_H
#define LIST_H
template<typename T>
class nodo {
	T val;
	nodo<T> * next;
	template<typename U>
	friend class list;
public:
	nodo(T val) : val(val) {next = nullptr; }
	nodo<T> * getNext() {return this->next; }
	T getVal() {return this->val; }
	friend ostream &operator<<(ostream &os, nodo<T> & n) {
		return os << n.val << endl;
	}
};

template<typename T>
class list {
	nodo<T> * head;
public:
	list() {head = nullptr; }

	bool isEmpty() {return head == nullptr; }

	void insert(T val) {
		if(isEmpty()) {
			head = new nodo<T>(val);
		}
	}

	T get_head(){return head->getVal();}

	T get_tail(){

		nodo<T>* tail = head;
		
		while(tail->next)
			tail = tail->next;

		return tail->getVal();
	}

	void insertHead(T val) {
		if(isEmpty()) {
			insert(val);
		return;
	}
		nodo<T> * toInsert = new nodo<T> (val);
		toInsert->next = head;
		head = toInsert;
		return;
	}

	void insertTail(T val) {
		if(isEmpty())
			insertHead(val);

		nodo<T> * ptr = head;
		while(ptr) {
			ptr = ptr->next;
		}
		nodo<T> * toInsert = new nodo<T>(val);
		ptr->next = toInsert;
		return;
	}

	void removeHead() {
		if(isEmpty())
			return;
		nodo<T> * tmp = head;
		head = head->next;
		delete tmp;
		return;
	}

	void removeTail() {
		
		nodo<T> * cur = head;
		nodo<T> * prev = nullptr;
		while(cur->next) {
			prev = cur;
			cur = cur->next;
		}
		prev->next = nullptr;
		delete cur;
		return;
	}

	void removeElement(double val) {

		if(isEmpty())
			return;

		nodo<T> * cur = head;
		nodo<T> * prev = nullptr;

		if(head->val.getTotale() == val)
		{
			removeHead();
			return;
		}

		while(cur->next && cur->val.getTotale() != val) {

			prev = cur;
			cur = cur->next;
		}

		if(cur->val.getTotale() != val)
			return;

		prev->next = cur->next;
		delete cur;
		return;
	}

	void removeBelow(double p){

		if(isEmpty())
			return;	

		nodo<T> * cur = head;

		while(cur) {

			if(cur->val.getTotale()<= p) 
				removeElement(cur->val.getTotale());
			
			cur = cur->next;
		}
	}

	list create(list &l) {
		ifstream fin("comande.txt");

		while(fin.good()) {
			comande c("Flavio", "Marinara", 2, 20);
			fin>>c;
			l.insertHead(c);
		}
		return l;
	}

	void raggruppa() {
		nodo<T> * ptr = head;
		while(ptr->next) {
			cout << "il cliente : " <<ptr->val.getCognome() << " " << "ha ordinato : " << ptr->val.getQta() << "pizze" << " " << "costo di : " << ptr->val.getPrezzo() << endl;
			ptr = ptr->getNext();
		}

	}

	void cerca(string cognome) {
		
		if(isEmpty())
			return;
		nodo<T> * ptr = head;
		while(ptr) {
			if(cognome == ptr->val.getCognome()) {
				cout << ptr->val << endl;
				cout << "il totale e : " << ptr->val.getPrezzo() * ptr->val.getQta() << "£" << endl;
			}
			//totale = ptr->val.getPrezzo() * ptr->val.getQta() << endl;
			
			ptr = ptr->next;

		}
	}

	void elimina() {

		if(isEmpty())
			return;

		int count = 0;
		double somma = 0.0;
		nodo<T> * ptr = head;

		while(ptr) {
			somma += ptr->val.getPrezzo() * ptr->val.getQta();
			count++;
			ptr = ptr->next;

		}
		double media = (double)somma/count ;

		cout << "La media = " << media << endl;

		nodo<T> * cur = head;
		while(cur) {
			if( cur->val.getTotale()<= media) 
				removeBelow(media);
				
			cur = cur->next;
		}
	}
			
		
	friend ostream &operator<<(ostream &os, list<T> & l) {
		if(l.isEmpty())
			return os << "empty " << endl;
		nodo<T> * ptr = l.head;
		while(ptr) {
			os << *ptr << endl;
			ptr = ptr->getNext();
		}
		return os;
	}
};
#endif


	

