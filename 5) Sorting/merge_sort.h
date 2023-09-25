#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "print_swap.h"

// Merge sort	--------------->	Complessità totale : O(n log n) in ogni caso

// Procedura Merge per la combinazione
void merge(int vet[], int start, int middle, int end)
{
    int i = start;      // indice inizio array sinistra
    int j = middle + 1; // indice inizio array di destra

    int aux[end + 1]; // vettore ausiliario di dimensione n
    int k = start;    // indice inizio vettore ausiliario

    while (i <= middle && j <= end)
    {
        if (vet[i] <= vet[j]) // Inserisco in aux l'elemento minore delle partizioni ordinate
            aux[k++] = vet[i++];
        else
            aux[k++] = vet[j++];
    }

    // Se "consumo" una delle due partizioni devo inserire in ordine tutti gli elementi dell'altra
    while (i <= middle)
        aux[k++] = vet[i++];

    while (j <= end)
        aux[k++] = vet[j++];

    for (k = start; k <= end; k++) // Copio i valori nell'array di partenza
        vet[k] = aux[k];
}

// Algoritmo di suddivisione
void merge_sort(int vet[], int start, int end)
{
    if (start >= end) // Se c'è più di un elemento
        return;

    else
    {
        int middle = (start + end) / 2;

        merge_sort(vet, start, middle);
        merge_sort(vet, middle + 1, end);
        merge(vet, start, middle, end);
    }
}

void merge_sort(int vet[], int n)
{
    // Richiamo passando il vettore, l'indice del primo e dell'ultimo elemento
    merge_sort(vet, 0, n - 1);
}

#endif