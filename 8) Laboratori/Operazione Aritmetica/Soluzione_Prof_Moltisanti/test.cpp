#include "include/operazione_aritmetica.h"
#include "include/addizione.h"
#include "include/sottrazione.h"
#include "include/moltiplicazione.h"
#include "include/divisione.h"

void test_addizione() {
	Addizione a(4.5, 4.5);
	std::cout << a.eseguiCalcolo() << std::endl;
}


void test_sottrazione() {
	Sottrazione s(5.3, 4.5);
	std::cout << s.eseguiCalcolo() << std::endl;
}

void test_moltiplicazione() {
	Moltiplicazione m(4.5, 2.0);
	std::cout << m.eseguiCalcolo() << std::endl;
}

void test_divisione() {
	Divisione d(9.0, 2.0);
	std::cout << d.eseguiCalcolo() << std::endl;
}

int main() {
	test_addizione();
	test_sottrazione();
	test_moltiplicazione();
	test_divisione();
}
