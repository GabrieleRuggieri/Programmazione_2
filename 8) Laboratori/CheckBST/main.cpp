#include <iostream>
using namespace std;

#include "BST.h" 

int main()
{
	BST<int> bst1;

	bst1.insert(7);
	bst1.insert(2);
	bst1.insert(9);
	bst1.insert(12);
	bst1.insert(4);
	bst1.insert(8);

	cout << "Interi_giusto : " << (bst1.checkBST(bst1.getRoot()) ? "TRUE" : "FALSE") << endl;

	BST<int> bst1_sbagliato;

	bst1_sbagliato.inserisciMale(7);
	bst1_sbagliato.inserisciMale(2);
	bst1_sbagliato.inserisciMale(9);
	bst1_sbagliato.inserisciMale(12);
	bst1_sbagliato.inserisciMale(4);
	bst1_sbagliato.inserisciMale(8);

	cout << "Interi_sbagliato : " << (bst1_sbagliato.checkBST(bst1_sbagliato.getRoot()) ? "TRUE" : "FALSE") << endl;


	BST<char> bst2;

	bst2.insert('a');
	bst2.insert('r');
	bst2.insert('r');
	bst2.insert('e');
	bst2.insert('w');
	bst2.insert('q');

	cout << "Char_giusto : " << (bst2.checkBST(bst2.getRoot()) ? "TRUE" : "FALSE") << endl;

	BST<char> bst2_sbagliato;

	bst2_sbagliato.inserisciMale('a');
	bst2_sbagliato.inserisciMale('r');
	bst2_sbagliato.inserisciMale('r');
	bst2_sbagliato.inserisciMale('e');
	bst2_sbagliato.inserisciMale('w');
	bst2_sbagliato.inserisciMale('q');

	cout << "Char_sbagliato : " << (bst2_sbagliato.checkBST(bst2_sbagliato.getRoot()) ? "TRUE" : "FALSE") << endl;

}
