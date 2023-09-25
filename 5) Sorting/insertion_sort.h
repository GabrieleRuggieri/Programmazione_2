#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "print_swap.h"

// Insertion sort   --------------->    Complessità O(n)^2 nel caso medio e peggiore, O(n) nel caso migliore
// Si può migliorare sfruttando il meccanismo della ricerca binaria per collocare l'elemento corrente nella posizione corretta.

void insertionSort(int vet[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = vet[i];
        int j = i - 1;

        while (vet[j] > key && j >= 0)
        {
            vet[j + 1] = vet[j];
            j--;
        }

        vet[j + 1] = key;
    }
}

#endif