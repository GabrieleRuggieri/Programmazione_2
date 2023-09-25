#include "Lista.h"

int main(){

	List l;

	List::create(l);
/*
	cout << l << endl;

	List::print(l, "Crescente");
	List::print(l, "Decrescente");

	List::get_info(l, "Spoto");
*/
	l.remove_player(l, 25.8);

	cout << l << endl;

}