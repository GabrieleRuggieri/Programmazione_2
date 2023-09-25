#ifndef NODO_H
#define NODO_H

#include<iostream>

using namespace std;

//class Pila;

template<typename T>
class Nodo{

protected:

		T val;
		Nodo<T>* next;

		//friend Pila;
		friend class Pila;

	public:

		Nodo(T val) : val(val){
		
			next = nullptr;
		}

		Nodo<T>* get_next(){
			return this->next;
		}

		T get_val(){
			return this->val;
		}

		friend ostream& operator<< (ostream& os, Nodo<T>& n){

			return os << *n.val ;
		}


};


template<typename T>
class Node{

protected:

		T val;
		Node<T>* next;

		friend class Coda;

	public:

		Node(T val) : val(val){
		
			next = nullptr;
		}

		Node<T>* get_next(){
			return this->next;
		}

		T get_val(){
			return this->val;
		}

		friend ostream& operator<< (ostream& os, Node<T>& n){
	
			return os << n.val ;
		}


};

#endif