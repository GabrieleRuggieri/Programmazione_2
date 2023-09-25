#ifndef STUDENTI_H
#define STUDENTI_H

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Studente{
	
	protected:

		string name;
		string surname;
		int eta;
		int media;

	public:

		Studente(string name, string surname, int eta, int media){
		
			this->name = name;
			this->surname = surname;
			this->eta = eta;
			this->media = media;
		}

		//Studente() : Studente("", "", 0, 0){}

		Studente() : Studente("Alfio","Spoto", 20, 28){}

		friend istream& operator>> (istream& input, Studente& us){

			string eta_str, media_str;

			std::getline(input, us.surname, ' ');
			std::getline(input, us.name, ' ');
			std::getline(input, eta_str, ' ');
			std::getline(input, media_str);

			us.eta = std::atoi(eta_str.c_str());
			us.media = std::atoi(media_str.c_str());
			
			return input;
		}
		
		bool operator <= (Studente& us){
			return this->surname <= us.surname;
		}

		friend ostream& operator << (ostream& os, Studente& us)
		{
			os << us.surname << " " << us.name << " " << " " << us.eta << " " << us.media << endl;
			return os;
		}
};

void swap (Studente& u1, Studente& u2){
	Studente temp = u1;
	u1 = u2;
	u2 = temp;
}

int partition(Studente vet[], int p, int r){ //lista, primo indice e ultimo indice

	Studente pivot = vet[r];
	int i = p-1;  //Indice del minimo corrente all'interno della lista

	for(int j=p; j<r; j++)//J è l'indice dell'elemento corrente preso in esame
	{
		if(vet[j] <= pivot)
		{
			i++;
			swap(vet[i], vet[j]);
		}
	}
	swap(vet[i+1], vet[r]);  //posiziono correttemente il pivot e lo restituisco
	return i+1;

}

void quick_sort(Studente vet[], int p, int r){

	if(p < r)  //caso base
	{
		int pivot = partition(vet, p, r); //setto il pivot
		quick_sort(vet, p, pivot-1); //partizione di sx
		quick_sort(vet, pivot+1, r);  //partizione di dx
	}

}

void quick_sort(Studente a[],int dim){
	quick_sort(a, 0, dim-1);
}

#endif