#ifndef ADDIZIONE
#define ADDIZIONE
#include "operazione_aritmetica.h"

class Addizione : public OperazioneAritmetica {
	public:
	Addizione() : OperazioneAritmetica() {
		this->symbol = '+';
	}
	Addizione(double sx, double dx) : OperazioneAritmetica(sx, dx) {
		this->symbol = '+';
	}
	double eseguiCalcolo(double opSinistro, double opDestro) {
		return opSinistro + opDestro;
	}
};
#endif
