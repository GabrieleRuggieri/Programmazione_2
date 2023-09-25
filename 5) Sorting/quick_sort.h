#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "print_swap.h"

// Quick sort	--------------->	Complessità totale : 0(n log n) nel caso migliore e medio, O(n^2) nel caso peggiore

// Procedura Partition che effettua la partizione e restituisce la posizione del pivot
int partition(int vet[], int start, int end)
{

	int pivot = vet[end]; // scelgo l'ultimo elemento come pivot
	int i = start - 1;	  // Indice del minimo corrente all'interno della lista

	for (int j = start; j < end; j++) // J è l'indice dell'elemento corrente preso in esame
	{
		if (vet[j] <= pivot)
		{
			i++; // lo aggiorno solo se trovo un elemento minore del pivot
			swap(vet[i], vet[j]);
		}
	}
	swap(vet[i + 1], vet[end]); // posiziono correttemente il pivot e lo restituisco

	return i + 1;
}

void quick_sort(int vet[], int start, int end)
{

	if (start < end) // Se c'è più di un elemento
	{
		int pivot = partition(vet, start, end); // setto il pivot
		quick_sort(vet, start, pivot - 1);		// riordino la partizione di sx
		quick_sort(vet, pivot + 1, end);		// riordino la partizione di dx
	}
}

void quick_sort(int vet[], int n)
{
	// Richiamo passando il vettore, l'indice del primo e dell'ultimo elemento
	quick_sort(vet, 0, n - 1);
}

#endif