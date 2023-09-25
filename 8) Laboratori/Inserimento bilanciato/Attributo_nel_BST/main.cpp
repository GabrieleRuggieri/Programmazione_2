#include<iostream>
using namespace std;

#include "BST.h"

int main(){

	BST<int> in;
	in.insert(5);
	in.insert(3);	//left
	in.insert(3);	//right
	in.insert(3);	//left
	in.insert(3);	//right	
	in.insert(3);	//left
	cout << "Visita del BST<int>: " << endl;
	in.in_order();
	cout << endl;

	BST<char> ch;
	ch.insert('d');
	ch.insert('f');	//right
	ch.insert('f');	//left
	ch.insert('f');	//right
	ch.insert('f');	//left
	ch.insert('f');	//right
	cout << "Visita del BST<char>: " << endl;
	ch.in_order();
	cout << endl;
}