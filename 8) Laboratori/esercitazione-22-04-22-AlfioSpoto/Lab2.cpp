#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class user{
	
		int ID;
		string name;
		string surname;
		double popolarita;
	
	public:
		user(int ID, string name, string surname, double popolarita){
			this->ID = ID;
			this->name = name;
			this->surname = surname;
			this->popolarita = popolarita;
		}

		user() : user(-1, "", "", 0.0){}

		friend istream& operator>> (istream& input, user& us){
			string id_string, pop_string;
			std::getline(input, id_string, ';');
			std::getline(input, us.surname, ';');
			std::getline(input, us.name, ';');
			std::getline(input, pop_string, '\n');
			us.ID = std::atoi(id_string.c_str());
			us.popolarita = std::atof(pop_string.c_str());
			//this.print();
			return input;
		}
		
		void print(){
			cout<<ID<<"; "<<surname<<"; "<<name<<"; "<<popolarita<<endl;
		}
		
		bool operator <= (user& us){
			return this->popolarita <= us.popolarita;
		}
};

void swap (user& u1, user& u2){
	user temp = u1;
	u1 = u2;
	u2 = temp;
}

int partition(user vet[], int p, int r){ //lista, primo indice e ultimo indice

	user pivot = vet[r];
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

void quick_sort(user vet[], int p, int r){

	if(p < r)  //caso base
	{
		int pivot = partition(vet, p, r); //setto il pivot
		quick_sort(vet, p, pivot-1); //partizione di sx
		quick_sort(vet, pivot+1, r);  //partizione di dx
	}

}

void quick_sort(user a[],int dim){
	quick_sort(a, 0, dim-1);
}

int main(){

	const int DIM = 2000;
	user* vet = new user[DIM];
	int count = 0;

	char c;
	ifstream fin("utenti.txt");
	
	while(fin.good()){
		user u;
		fin >> u;
		vet[count++] = u;
	}
	fin.close();

	quick_sort(vet, DIM);
	for(int i=0; i<DIM; i++){
		vet[i].print();
	}

}