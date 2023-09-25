#ifndef OPERAZIONEARITMETICA_H
#define OPERAZIONEARITMETICA_H

#include<typeinfo>
#include<iostream> 
using namespace std;

class OperazioneAritmetica{

	protected:

		double OpSinistro;
		double OpDestro;

	public:

		OperazioneAritmetica(double sx = 0.0, double dx = 0.0) : OpSinistro(sx), OpDestro(dx){}

		virtual double eseguiCalcolo(double OpSinistro, double OpDestro) = 0;
		
		friend ostream& operator<< (ostream& os, const OperazioneAritmetica& oa)
		{
			os << "Tipo: "<< typeid(oa).name() << endl << endl;
			return os;
		}

};

class Addizione : public OperazioneAritmetica{

	public:

		Addizione(double sx, double dx) : OperazioneAritmetica(sx, dx){}

		Addizione() : OperazioneAritmetica(){}

		double eseguiCalcolo(double OpSinistro, double OpDestro) override {
			cout << "\nOpSinistro = " << OpSinistro << "\tOpDestro = " << OpDestro << endl;
			cout << "Risultato = ";
			return OpSinistro + OpDestro;
		}

};

class Sottrazione : public OperazioneAritmetica{

	public:

		Sottrazione(double sx, double dx) : OperazioneAritmetica(sx, dx){}

		Sottrazione() : OperazioneAritmetica(){}

		double eseguiCalcolo(double OpSinistro, double OpDestro) override {
			cout << "\nOpSinistro = " << OpSinistro << "\tOpDestro = " << OpDestro << endl;
			cout << "Risultato = ";
			return OpSinistro - OpDestro;
		}

};

class Moltiplicazione : public OperazioneAritmetica{

	public:

		Moltiplicazione(double sx, double dx) : OperazioneAritmetica(sx, dx){}

		Moltiplicazione() : OperazioneAritmetica(){}

		double eseguiCalcolo(double OpSinistro, double OpDestro) override {
			cout << "\nOpSinistro = " << OpSinistro << "\tOpDestro = " << OpDestro << endl;
			cout << "Risultato = ";
			return OpSinistro * OpDestro;
		}

};

class Divisione : public OperazioneAritmetica{

	public:

		Divisione(double sx, double dx) : OperazioneAritmetica(sx, dx){}

		Divisione() : OperazioneAritmetica(){}

		double eseguiCalcolo(double OpSinistro, double OpDestro) override {
			if(OpDestro != 0)
			{
				cout << "\nOpSinistro = " << OpSinistro << "\tOpDestro = " << OpDestro << endl;
				cout << "Risultato = ";
				return (double) OpSinistro / OpDestro;
			}

			throw out_of_range("Not possible to divide by zero!");
			return -1;
		}

};

 #endif