#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//Includo l'header
#include "BST.h"

int main(){

	cout << endl;

    ifstream is("input.txt");

    //int 10 ins:80 ins:172 ins:13 ins:138 ins:223 ins:245 ins:144 ins:152 ins:151 ins:270 151 138
 
    for(int i=0; i<6; i++)  //creazione di 6 oggetti di tipo BST
    {
		string type; //tipo del template generico "H"
		is >> type;
		int N; //numero di elementi da inserire nel BST
		is >> N;

		if(type == "int") //se il tipo è int istanzio un BST<int>
		{
			BST<int> bst; 
			for(int i=0; i<N; i++) //eseguo N operazioni di inserimento
			{
			    string toinsert; //elemento da inserire
			    is >> toinsert;
			    //toinsert = toinsert.substr(toinsert.find(":")+1, toinsert.length());
			    toinsert = toinsert.erase(0, 4); //elimino "ins:"
			    bst.insert(stoi(toinsert));
			}

			bst.in_order(); //visito l'albero

			//Chiavi k e h delle quali devo controllare la distanza
			int k;
			int h;
			is >> k;
			is >> h;

			cout<<"\n\nDistanza fra " << k << " e " << h << " = " << bst.distanzaChiavi(k, h) << endl;
      	}
	    else if(type == "char") //se il tipo è char istanzio un BST<char>
	    {
	        BST<char> bst;
	        for(int i=0; i<N; i++)
	        {
	            string toinsert;
	            is >> toinsert;
			    toinsert = toinsert.erase(0, 4); //elimino "ins:"
	            bst.insert(toinsert[0]); //inserisco il primo carattere (l'unico) della stringa
	        }

	        bst.in_order();

	        char k = 0;
	        char h =0;
	        is >> k;
	        is >> h;

	        cout<<"\n\nDistanza fra " << k << " e " << h << " = " << bst.distanzaChiavi(k,h) << endl;
	    }

	    cout << "\n-------------------------------------------------------------\n";
	}

    cout << endl;
}