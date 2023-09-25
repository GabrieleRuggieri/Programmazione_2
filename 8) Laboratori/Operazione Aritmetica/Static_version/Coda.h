#ifndef CODA_H
#define CODA_H

#include<iostream>

class Coda{

	double* vet;
	int size = 0;
	int max_size;

	int head = -1;
	int tail = -1;

	public:

		Coda(int max_size) : max_size(max_size){
			vet = new double[max_size];
		}

		bool isEmpty()
		{
			return size == 0;
		}

		void enqueue(double val){

			if(size == max_size)
			{
				throw out_of_range("Full Queue");
				return;
			}

			if(head == -1)
				head = 0;

			tail = (++tail) % max_size;
			vet[tail] = val;
			size ++;
		}

		double dequeue(){

			if(isEmpty())
			{
				cerr << "Empty Queue" << endl;
				return -1;
			}

			double tmp = vet[head];
			head = (++head) % max_size;
			size--;
			return tmp;
		}

		friend ostream& operator<< (ostream& os, Coda& q){

			os << "\nNumero operandi: " << q.size << endl << endl;

			if(q.size == 0)
			{
				os << "\nEmpty Queue" << endl;
				return os;
			}

			for(int i=q.head, count=0; count < q.size; count++)
			{
				os << "\tOperando n˚" << i+1 << " = " << q.vet[i] << endl;
				i = (i+1) % q.max_size; //Incremento i e ne faccio il modulo per essere sicuro di verificare la condizione di uscita
			}
			
			os << endl;
			return os;
		}
};

#endif