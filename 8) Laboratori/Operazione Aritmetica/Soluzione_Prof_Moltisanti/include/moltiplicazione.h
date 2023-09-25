#ifndef MOLTIPLICAZIONE
#define MOLTIPLICAZIONE
#include "operazione_aritmetica.h"

class Moltiplicazione : public OperazioneAritmetica {
	public:
	Moltiplicazione() : OperazioneAritmetica() {
		this->symbol = '*';
	}
	Moltiplicazione(double sx, double dx) : OperazioneAritmetica(sx, dx) {
		this->symbol = '*';
	}
	double eseguiCalcolo(double opSinistro, double opDestro) {
		return opSinistro * opDestro;
	}
};
#endif
