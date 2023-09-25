#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "print_swap.h"

// Bubble sort  --------------->    Complessità O(n)^2 in qualunque caso

/*
Si può migliorare la strategia utilizzando un flag che consente di ripetere fino a quando ci sono degli
scambi da fare  --------------->    O(n)
*/

void bubble_sort(int vet[], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) // Confronta gli elementi adiacenti
        {
            if (vet[j] < vet[i])
                swap(vet[j], vet[i]); // Fa "risalire" quelli più leggeri
        }
    }
}
// Dopo n-1 iterazioni l’array risulterà ordinato

#endif