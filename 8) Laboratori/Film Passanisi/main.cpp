/* 
Dato il file film.txt che contiene : 

	-titolo film; 
	-stringa che contiene il genere; 
	-stringa che contiene la data della prima proiezione;

Scrivere un programma che consente di inserire i dati in una lista ordinata rispetto alla data, e stampa della lista.
Ricerca del film piu nuovo e piu vecchio, ed estrazioni dei film di un dato genere. 
*/

#include<iostream>
using namespace std;

#include "Film.h"
#include "Lista.h"

int main(){
	
	List l;

	ifstream fin("film.txt");

	while(fin.good())
	{
		Film f;
		fin >> f;  //Inizializza i parametri di f
		l.insert_in_order(f);
	}

	fin.close();

	cout << l << endl;
}