#include<iostream>
#include<fstream>

using namespace std;

#include "Lista.h"
#include "BST.h"

int main(){

	List l;

    ifstream is("films.txt");

	while(is.good())
	{
		Film f;
		is >> f;
        l.insert_in_order(f);
	}

	cout << l << endl;

	BST<Film> b;

	while(l.get_head_ptr())
	{
		Film f = l.get_head();
		b.insert(f);
		l.remove_head();
	}

	b.in_order();
	
}