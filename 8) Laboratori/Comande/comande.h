#include<iostream>
#include<fstream>
using namespace std;
#ifndef COMANDE_H
#define COMANDE_H
class comande {
	string cognome, pizza;
	int qta;
	double prezzo, totale;
public:

	comande(string cognome, string pizza, int qta, double prezzo) : cognome(cognome), pizza(pizza), qta(qta), prezzo(prezzo), totale(totale) {}
	
	bool operator!= (comande& obj){return this->totale != obj.totale;}
	bool operator== (comande& obj){return this->totale == obj.totale;}
	bool operator<= (comande& obj){return this->totale <= obj.totale;}
	bool operator> (comande& obj){return this->totale > obj.totale;}


	friend ostream &operator<<(ostream &os, comande & c) {
		os << "cognome = " << c.cognome << endl;
		os << "pizza = " << c.pizza << endl;
		os << "quantita' = " << c.qta << endl;
		os << "prezzo = " << c.prezzo << endl;
		os << "totale = " << c.prezzo * c.qta << endl;
		return os;
	}

	friend istream &operator>>(istream &is, comande & c) {
		string qta_str, prezzo_str;
		std::getline(is, c.cognome, ',');
		std::getline(is, c.pizza, ',');
		std::getline(is, qta_str, ',');
		std::getline(is, prezzo_str, '\n');
		c.qta = std::atoi(qta_str.c_str());
		c.prezzo = std::atof(prezzo_str.c_str());
		return is;
	}
	string getCognome() {return this->cognome; }
	string getPizza() {return this->pizza; }
	int getQta() {return this->qta; }
	double getPrezzo() {return this->prezzo; } 
	//bool operator !=(comande &c) { return this->p
	double getTotale(){return this->prezzo * this->qta; }
};
#endif
	

	
