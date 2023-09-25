#include<iostream>
#include<stdlib.h>
#include<time.h>

#include "Pila.h"
#include "Coda.h"
#include "OperazioneAritmetica.h"

using namespace std;

int main(){

	int N;
	cout << "\nInserisci un intero N:" << endl;
	cin >> N;

	Pila stack;  //Pila che conterrà le istanze di operazioni aritmetiche

	srand(time(NULL));  //Imposto il seed

	//Genero N istanze di oggetti OperazioneAritmetca e passo gli operandi come parametri al costruttore delle operazioni
	for(int i=0; i<N; i++)
	{
		int r = rand() % 4;		

		OperazioneAritmetica* obj;

		switch(r){

            case 0:
                {
                	obj = new Addizione;
                	break;
                }

            case 1:
                {
					obj = new Sottrazione;
                    break;
                }

            case 2:
                {
                    obj = new Moltiplicazione;
                    break;
                }

            case 3:
                {
                    obj = new Divisione;
                    break;
                }
            }

             stack.push(obj);
	}

	//cout << stack;  //Stampo a video il risultato delle operazioni eseguite

	Coda queue;  //Coda che conterrà i valori degli operandi 

	double op;
	for(int i=0; i<2*N; i++)
	{
		//Valori double tra -100 a 100
		int a = -100;
		int b = 100;

		op = (b-a)*(1.0*rand()/RAND_MAX)+a;
		queue.enqueue(op);
	}

	cout << queue;

	for(int i=0; i < N; i++) {
		OperazioneAritmetica* op = stack.pop();

		double n1 = queue.dequeue()->get_val();
		double n2 = queue.dequeue()->get_val();
		
		cout <<"\n" << *op << op->eseguiCalcolo(n1, n2) << endl << endl;
		cout << "\n------------------------------------------------\n" ;
	}

}
