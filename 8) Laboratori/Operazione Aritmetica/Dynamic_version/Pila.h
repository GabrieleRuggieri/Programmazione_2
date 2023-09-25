#ifndef PILA_H
#define PILA_H

#include<iostream>

#include "OperazioneAritmetica.h"
#include "Nodo.h"

using namespace std;

class Pila {
	
	int size = 0;
	Nodo<OperazioneAritmetica*>* top;

public:

	Pila(){
		top = nullptr;
	}

	bool isEmpty(){
		return size == 0;
	}

	Nodo<OperazioneAritmetica*>* get_top(){

		return this->top;
	}

	void push(OperazioneAritmetica* val){

		if(isEmpty())
		{
			top = new Nodo<OperazioneAritmetica*> (val);
			size++;
			return;
		}

		Nodo<OperazioneAritmetica*>* toinsert = new Nodo<OperazioneAritmetica*> (val);
		toinsert->next = get_top();
		top = toinsert;
		size ++;

		return;
	}

	OperazioneAritmetica* pop(){

		if(isEmpty())
			return nullptr;

		Nodo<OperazioneAritmetica*> * tmp = top;
		top = top -> next; 
		OperazioneAritmetica* aux = tmp->val;
		delete tmp;  
		size --;

		return aux;
	}

	friend ostream& operator<< (ostream& os, Pila& p){
						
			os << "\nNumero di operazioni: " << p.size << endl << endl;
					
			if(p.isEmpty())
			{
				os << "\nEmpty Stack!" << endl;
				return os;
			}

			os << "\n\t1˚\t" << *p.get_top() << endl;

			int idx = 2;
			while(p.pop())
			{
				if(p.get_top())
				{
					os << "\t" << idx << "˚" ;
					os << "\t" << *p.get_top() << "\n" ;
					idx ++;
				}
			}
			os << "\nEnd stack" << endl;
			
			return os;
	}

};

#endif