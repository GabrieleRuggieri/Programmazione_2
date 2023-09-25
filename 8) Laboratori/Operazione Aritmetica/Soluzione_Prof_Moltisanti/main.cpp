#include <iostream>
#include "include/static_queue.h"
#include "include/static_stack.h"
#include "include/operazioni.h"
#include <cstdlib>

int main() {
	int N;
	std::cout << "Inserire il numero di operazioni da effettuare: ";
	std::cin >> N;
	StaticStack<OperazioneAritmetica*> operazioni(N);
	for(int i=0; i<N; i++) {
		int selection = std::rand() % 4;
		OperazioneAritmetica* operazione = nullptr;
		switch(selection) {
			case 0: operazione = new Addizione(); break;
			case 1: operazione = new Sottrazione(); break;
			case 2: operazione = new Moltiplicazione(); break;
			case 3: operazione = new Divisione(); break;
		}
		operazioni.push(operazione);
	}
	std::cout << operazioni << std::endl;

	StaticQueue<double> operandi(2*N);
	for(int i=0; i < 2*N; i++) {
		double r = ((double)std::rand() / RAND_MAX) * 100.0;
		operandi.enqueue(r);
	}

	std::cout << operandi << std::endl;
	
	for(int i=0; i < N; i++) {
		OperazioneAritmetica* op = operazioni.pop();
		double n1 = operandi.dequeue();
		double n2 = operandi.dequeue();

		std::cout << *op << " = " << op->eseguiCalcolo(n1, n2) << std::endl;
	}
}
