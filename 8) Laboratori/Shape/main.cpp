#include<iostream>
#include<limits>
using namespace std;

#include "shape.h"
#include "Queue_static.h"
#include "BST.h"

int main(){

	int N;

	//Permette di fare una nuova lettura in caso di errore di input
	bool okay = false;
	do{
		cout << "\nInserisci N: " << endl;
		cin >> N;

		if(cin.fail()){
			cerr << "Errore nell'inserimento di N!" << endl;
			cin.clear();	//resetta i flag di errore di cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	//svuota il buffer di cin
		}else
			okay = true;
	}while(!okay);

	Queue_static<Shape*> Rectangle_queue(N);
	Queue_static<Shape*> Circle_queue(N);
	Queue_static<Shape*> Triangle_queue(N);
		
	Shape* ptr;
	for(int i=0; i<N; i++){

		switch(rand()%3){

			case(0):	
				ptr = new Rectangle(1.5+rand()%6, 2.2+rand()%3);
				Rectangle_queue.enqueue(ptr);
				break;		

			case(1):	
				ptr = new Circle(1.8+rand()%4);
				Circle_queue.enqueue(ptr);
				break;	

			case(2):	
				ptr = new Triangle(2.5+rand()%3, 1.3+rand()%7);
				Triangle_queue.enqueue(ptr);
				break;
		}
	}

	//Mando in output le tre code
	cout << "\nCoda di rettangoli: \n" << Rectangle_queue << endl;
	cout << "\nCoda di circonferenze: \n" << Circle_queue << endl;
	cout << "\nCoda di triangoli: \n" << Triangle_queue << endl;

	BST<Shape*> bst_unico;

	while(Rectangle_queue.getFirst())
		bst_unico.insert(Rectangle_queue.dequeue());		

	while(Circle_queue.getFirst())
		bst_unico.insert(Circle_queue.dequeue());		

	while(Triangle_queue.getFirst())
		bst_unico.insert(Triangle_queue.dequeue());
		
	//Mando in output il bst
	cout << bst_unico << endl;	

	double val;
	okay = false;

	do{
		cout << "\nInserire un valore di area: " << endl;
		cin >> val;
		if(cin.fail()){
			cerr << "Errore nell'inserimento dell'area!" << endl;
			cin.clear();	
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}else
			okay = true;
	}while(!okay);

	bst_unico.remove_below(val);

	//Confermo l'avvenuta eliminazione dei nodi
	cout << bst_unico << endl;	
}