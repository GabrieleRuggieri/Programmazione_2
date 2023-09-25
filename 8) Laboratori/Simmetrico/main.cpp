#include<iostream>
using namespace std;

#include "BST.h"

int main(){
	
	BST<int> o;

	o.insert(7);
	o.insert(2);
	o.insert(4);
	o.insert(9);
	o.insert(12);

	cout << "\nBST originale: " << endl << "-------------------------" << endl;
	o.in_order();
	cout << endl;

	cout << "\nBST simmetrico: " << endl << "-------------------------" << endl;
	o.symmetric()->in_order();
	cout << endl;
}