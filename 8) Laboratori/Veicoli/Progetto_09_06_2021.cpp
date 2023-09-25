#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

#include "Veicolo.h"
#include "Static_stack.h"
#include "bst.h"

int main(){

	int N = 500;
	StaticStack<Veicolo*> s_auto(N);
	StaticStack<Veicolo*> s_moto(N);
	StaticStack<Veicolo*> s_barca(N);

	ifstream is("Veicoli.txt");
	string type = "";
	string cilindrata = "";
	while(is.good())
	{
		Veicolo* v;
		getline(is, type, ',');
		getline(is, cilindrata);
		if(type == "AUTO")
		{
			v = new Auto(atoi(cilindrata.c_str()), type);
			s_auto.push(v);
		}
		if(type == "MOTO")
		{
			v = new Moto(atoi(cilindrata.c_str()), type);
			s_moto.push(v);
		}
		if(type == "BARCA")
		{
			v = new Barca(atoi(cilindrata.c_str()), type);
			s_barca.push(v);
		}
	}

	cout << "Stack di oggetti di tipo Auto" << s_auto << endl;
	cout << "Stack di oggetti di tipo Moto" << s_moto << endl;
	cout << "Stack di oggetti di tipo Barca" << s_barca << endl;

	BST<Veicolo*> b_auto;
	BST<Veicolo*> b_moto;
	BST<Veicolo*> b_barca;

	while(s_auto.getTop())
		b_auto.insert(s_auto.pop());

	while(s_moto.getTop())
		b_moto.insert(s_moto.pop());

	while(s_barca.getTop())
		b_barca.insert(s_barca.pop());
	
	cout << "\nBst di oggetti di tipo Auto" << endl;
	b_auto.inOrder();
	cout << "------------------------------------------------------" << endl;
	cout << "\nBst di oggetti di tipo Moto" << endl;
	b_moto.inOrder();
	cout << "------------------------------------------------------" << endl;
	cout << "\nBst di oggetti di tipo Barca" << endl;
	b_barca.inOrder();
	cout << "------------------------------------------------------" << endl;

	int val;
	bool okay = false;
	do{
		cout << "\nInserisci un valore di cilindrata (si consiglia un valore inferiore a 4900)" << endl;
		cin >> val;

		if(cin.fail() || val >= 4900){	
			cerr << "Errore nell'inserimento di val!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	
		}else
			okay = true;
	}while(!okay);

	b_auto.remove_below(val);
	b_moto.remove_below(val);
	b_barca.remove_below(val);

	cout << "\nBst di oggetti di tipo Auto dopo la rimozione: " << endl;
	b_auto.inOrder();
	cout << "------------------------------------------------------" << endl;
	cout << "\nBst di oggetti di tipo Moto dopo la rimozione: " << endl;
	b_moto.inOrder();
	cout << "------------------------------------------------------" << endl;
	cout << "\nBst di oggetti di tipo Barca dopo la rimozione: " << endl;
	b_barca.inOrder();
	cout << "------------------------------------------------------" << endl;

}