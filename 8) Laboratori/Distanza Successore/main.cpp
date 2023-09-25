#include<iostream>
using namespace std;

#include "BST.h"

int main(){
	
	BST<int> bst;

	bst.insert(7);
	bst.insert(2);
	bst.insert(9);
	bst.insert(12);
	bst.insert(4);
	bst.insert(8);

	cout << "\nVisita in order: " << endl;
	bst.in_order();

	cout << "\nDistanza da 7 al suo successore : " << bst.from_successor(7) << endl;
	cout << "\nDistanza tra 7 e 8 : " << bst.between_nodes(7, 8) << endl;

}