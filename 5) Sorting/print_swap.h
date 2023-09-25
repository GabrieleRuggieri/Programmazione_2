#ifndef PRINT_SWAP_H
#define PRINT_SWAP_H

#include <iostream>
using namespace std;

void print(int vet[], int n)
{

    cout << "\nArray: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << vet[i] << "\t";
    }
    cout << endl;
}

// Importante il passsaggio per riferimento
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
#endif