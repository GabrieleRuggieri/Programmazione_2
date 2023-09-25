#ifndef DIVISIONE
#define DIVISIONE
#include "operazione_aritmetica.h"

class Divisione : public OperazioneAritmetica {
	public:
	Divisione() : OperazioneAritmetica() {
		this->symbol = '/';
	}
	Divisione(double sx, double dx) : OperazioneAritmetica(sx, dx) {
		this->symbol = '/';
	}
	double eseguiCalcolo(double opSinistro, double opDestro) {
		return opSinistro / opDestro;
	}
};
#endif
