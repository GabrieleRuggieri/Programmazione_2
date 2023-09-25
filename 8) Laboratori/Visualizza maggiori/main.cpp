#include<iostream>
using namespace std;

#include "BST.h"

int main(){

	BST<int> b;

	b.insert(7);
	b.insert(3);	
	b.insert(9);	
	b.insert(2);	
	b.insert(10);	
	b.insert(13);

	b.print_above(9);	//Stampa tutti i nodi con chiave >= 9

}