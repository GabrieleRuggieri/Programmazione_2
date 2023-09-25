#ifndef GIOCATORE_H
#define GICATORE_H

#include<fstream>
#include<iostream>
using namespace std;

class Giocatore{

		string cognome;
		string nome;
		string circolo;
		double punteggio;
		int anno;

	public:

		Giocatore(string c, string n, string circ, double p, int a){

			this->cognome = c;
			this->nome = n;
			this->circolo = circ;
			this->punteggio = p;
			this->anno = a;
		}

		Giocatore() : Giocatore("Cognome", "Nome", "Circolo_x", 0.0, 2000){}

		bool operator>= (Giocatore& g){

			return this->punteggio >= g.punteggio;
		}

		bool operator<= (Giocatore& g){

			return this->punteggio <= g.punteggio;
		}

		bool operator== (Giocatore& g){

			return this->punteggio == g.punteggio;
		}

		bool operator!= (Giocatore& g){

			return this->punteggio != g.punteggio;
		}

		string get_cognome()const{ return this->cognome; }

		double get_punteggio()const{ return this->punteggio; }


		friend istream& operator>> (istream& is, Giocatore& g){

			string punteggio_str = "";
			string anno_str = "";

			std::getline(is, g.cognome, ';');
			std::getline(is, g.nome, ';');
			std::getline(is, g.circolo, ';');
			std::getline(is, punteggio_str, ';');
			std::getline(is, anno_str, '\n');

			g.punteggio = std::atof(punteggio_str.c_str());
			g.anno = std::atoi(anno_str.c_str());

			return is;
		}

		friend ostream& operator<< (ostream& os, Giocatore& g){

			os << "\nCognome: "<< g.cognome << "\tNome: " << g.nome << endl;
			os << "\n\tCircolo: " << g.circolo << endl;
			os << "\n\tPunteggio: " << g.punteggio << endl;
			os << "\n\tAnno: " << g.anno << endl;
			os << "----------------------------------------------------------------------------------" << endl;

			return os;
		}
};

#endif