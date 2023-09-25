#ifndef FILM_H
#define FILM_H

#include<iostream>
#include<fstream>

using namespace std;

class Film{
	
		string titolo;
		string genere;
		string data;

	public:

		Film(string t, string g, string d){

			this->titolo = t;
			this->genere = g;
			this->data = d;
		}

		Film() : Film("Titolo", "Genere", "aaaa-mm-gg"){}

		bool operator >= (Film& f){

			return this->data <= f.data;
		}

		bool operator == (Film& f){

			return this->data == f.data;
		}

		bool operator != (Film& f){

			return this->data != f.data;
		}

		friend istream& operator>> (istream& is, Film& f){  //INPUT

			std::getline(is, f.titolo, '\n');
			std::getline(is, f.genere, '\n');
			std::getline(is, f.data, '\n');
		
			return is;
		}

		friend ostream& operator<< (ostream& os, Film& f){  //OUTPUT

			os << "\nTitolo: " << f.titolo << endl;
			os << "Genere: " << f.genere << endl;
			os << "Data prima proiezione: " << f.data << endl;

			return os;
		}
};

#endif