//Simulare un appello con una coda

#include<iostream>
#include<stdlib.h>
#include<ctime>
#include "Studenti.h"
#define CapienzaMAX 20

using namespace std;

class Static_Queue{

		Studente* fila;
		int size = 0;  //aula vuota
		int capienza_aula;

		int head = -1;
		int tail = -1;

	public:

		Static_Queue(int capienza_aula = CapienzaMAX) : capienza_aula(capienza_aula){

			srand(time(NULL));
			fila = new Studente[capienza_aula];
		}

		void enqueue(Studente val){

			if(size == capienza_aula)
			{
				cerr << "Aula piena" << endl;
				return;
			}

			if(head == -1)
				head = 0;

			tail = (++tail) % capienza_aula;
			fila [tail] = val;
			size++;
			return;
		}

		Studente dequeue(){

			if(size == 0)
			{
				cerr << "Aula vuota" << endl;
				Studente empty;
				return empty;
			}

			Studente tmp = fila[head];
			head = (++head) % capienza_aula;
			size--;
			cout << "Voto :" << 12 + rand() % 19 << endl;
			return tmp;
		}

		friend ostream& operator<< (ostream& os, Static_Queue& sq){

				if(sq.size == 0)
				{
					os << "\nAula vuota" << endl;
					return os;
				}

				os << "\nNumero alunni in aula = " << sq.size << endl;
				os << "\nCapienza aula = " << sq.capienza_aula << " posti" << endl << endl;

				for(int i=sq.head, count=0; count<sq.size; count++)
				{
					os << "\t" << i+1 << "° alunno --> " << sq.fila[i] << endl;
					i = (i + 1) % sq.capienza_aula;
				}

				os << endl;
				return os;
		}
};

int main(){

	const int DIM = 20;
	Studente* vet = new Studente[DIM];
	int count = 0;

	char c;
	ifstream fin("Studenti.txt");
	
	while( fin.good() )
	{
		Studente u;
		fin >> u;
		vet[count++] = u;	
	}

	fin.close();

	//Lista di studenti 
	cout << "Studenti presenti all'appello" << endl;
	for(int i=0; i<DIM; i++)
		cout << vet[i] << endl;

	cout << "----------------------------------------------" << endl;

	cout << "ORDINE DI INGRESSO IN AULA: " << endl << endl;
	quick_sort(vet, DIM);
	for(int i=0; i<DIM; i++)
		cout << vet[i] << endl;

	cout << "----------------------------------------------" << endl;

	Static_Queue sq (20);

	for(int i=0; i<DIM; i++)
		sq.enqueue(vet[i]);

	cout << sq << endl;
}