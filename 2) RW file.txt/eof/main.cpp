#include <iostream>
#include <fstream>

using namespace std;

void write(ofstream &os)
{
	bool finish = false;
	int x;
	while (!finish)
	{
		cout << "Inserisci un numero (premi CTRL + D su Linux per terminare, CTRL + Z su Windows): ";
		cin >> x;

		if (cin.eof()) // true solo se si inserisce l'eof con CTRL + D, CTRL+Z su Windows
		{
			cout << "\n";
			finish = true;
		}
		else
			os << x << " ";
	}
	os.close();
}

void read(ifstream &is)
{
	cout << "Leggo: " << endl;
	string str;
	while (getline(is, str))
		cout << str << '\n';
}

int *buildArray(ifstream &is, int &n)
{
	ifstream is2("file.txt");
	char c;
	int x, i;

	while (is2.get(c))
	{
		if (c == ' ')
			n++;
	}
	cout << "Sono stati inseriti " << n << " numeri " << endl;

	int *vet = new int[n];
	while (is >> x)
		vet[i++] = x;

	is.close();
	return vet;
}

void printArray(int vet[], int n)
{
	cout << "Array : " << endl;
	for (int i = 0; i < n; i++)
		cout << vet[i] << " ";
	cout << endl;
}

//	Inserire in un file di testo i numeri interi dati da riga di comando e successivamente leggerli ed inserirli in un array

int main()
{
	ofstream os("file.txt");
	write(os); // Scrive sul file di testo

	ifstream is("file.txt");
	int n = 0;
	int *vet = buildArray(is, n);
	printArray(vet, n);
}