#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	// SCRIVO IN "file.txt"
	ofstream os("file.txt");
	os << "Ciao mondo\nCome stai\nTerzariga";
	os.close();

	// LEGGO DA "file.txt"
	ifstream is("file.txt");
	string str;
	while (getline(is, str))
		cout << str << '\n';

	is.close();
}