#include <iostream>
using namespace std;

#include "search.h"

int main()
{
    int vet[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(vet) / sizeof(vet[0]);

    search(vet, n, 9);
    cout << endl;
    binary_search_ricorsive(vet, n, 9);
    cout << endl;

    //---------------------------

    cout << "Succ di 5 = " << succ(5) << endl;
    cout << "Sum di 2 e 4 = " << sum(2, 4) << endl;
    cout << "Fatt di 4 = " << fatt(4) << endl;
}
