#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "print_swap.h"

// Selection sort   --------------->    Complessità O(n)^2 in qualunque caso

void selection_sort(int vet[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int idx = i;

        for (int j = i + 1; j < n; j++) // Scorro il sotto-array non ordinato
        {
            if (vet[j] < vet[idx]) // Conservo l'indice dell'elemento minimo
                idx = j;
        }
        
        swap(vet[i], vet[idx]);
    }
}

#endif