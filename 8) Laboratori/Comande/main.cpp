#include "list.h"

int main() {
	list<comande> l;
	l.create(l);
	//l.raggruppa();
	//l.cerca("Sciortino");
	//l.elimina();

	comande obj = l.get_tail();

	cout << l << endl;

	l.elimina();
	cout << "--------------------\n Dopo : \n" << endl;
	cout << l;
}