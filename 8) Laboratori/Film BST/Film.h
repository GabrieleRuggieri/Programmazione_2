#ifndef FILM_H
#define FILM_H

class Film{
	
    string titolo;
    int anno;
    double valutazione;

    public:

    Film(string t,int a,double v){
    	this->titolo = t;
    	this->anno = a;
    	this->valutazione = v;
    }

    Film(){}

    double get_valutazione(){return this->valutazione;}

    bool operator <= (Film& f){return this->valutazione <= f.valutazione;}

    bool operator >= (Film& f){return this->valutazione >= f.valutazione;}

    bool operator > (Film& f){return this->valutazione > f.valutazione;}

    bool operator < (Film& f){return this->valutazione < f.valutazione;}


	friend istream& operator>> (istream& is, Film& f){  //INPUT

		string anno_str;
		string valutazione_str;

		std::getline(is, f.titolo, ';');
		std::getline(is, anno_str, ';');
		std::getline(is, valutazione_str, '\n');

		f.anno = stoi(anno_str.c_str());
		f.valutazione = stod(valutazione_str.c_str());
	
		return is;
	}

	friend ostream& operator<< (ostream& os, Film& f){  //OUTPUT

		os << "\nTitolo: " << f.titolo << endl;
		os << "Anno: " << f.anno << endl;
		os << "Valutazione: " << f.valutazione << endl;

		return os;
	}
};

#endif