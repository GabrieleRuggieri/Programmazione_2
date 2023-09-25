#ifndef PILA_H
#define PILA_H

#include "OperazioneAritmetica.h"

using namespace std;

class Pila{

	OperazioneAritmetica** vet;
	int top = -1;
	int size = 0;
	int max_size = -1;

	public: 

		Pila(int max_size) : max_size(max_size){
			vet = new OperazioneAritmetica*[max_size];
		}

		bool isEmpty(){
			return size == 0;
		}

		OperazioneAritmetica* get_top(){

			if(isEmpty())
			{
				//throw out_of_range("Empty Queue");
				return nullptr;
			}

			return vet[top];

		}

		void push(OperazioneAritmetica* val){

			if(size == max_size)
			{
				cerr << "Full Stack" << endl;
				return;
			}

			vet[++top] = val;
			size ++;
		}

		OperazioneAritmetica* pop(){

			if(isEmpty())
			{
				//throw out_of_range("Empty Queue");
				return nullptr;
			}

			size --;
			return vet[top--];
		}

		friend ostream& operator<< (ostream& os, Pila& p){
			
			os << "\nNumero di operazioni: " << p.size << endl << endl;
					
			if(p.isEmpty())
			{
				os << "\nEmpty Stack!" << endl;
				return os;
			}

			int idx = 1;
			for(int i=p.top; i>=0; i--)
			{
				if(p.get_top())
				{
					os << "\t" << idx << "˚" ;
					os << "\t" << *p.vet[i];

					idx ++;
				}
			}
			os << "End stack" << endl;
			
			return os;
		}
};

#endif