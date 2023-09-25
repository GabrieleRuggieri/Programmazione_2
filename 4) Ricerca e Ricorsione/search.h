#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
using namespace std;

/*
    Complessità :  quantità di risorse impiegate dall'algoritmo
    
    Problema di ricerca di un elemento k in un array di n elementi

    idea = ricerca sequenziale

    - caso migliore: k è il primo valore    --> Omega(1) = non posso fare meno di un confronto
    - caso medio: k è più o meno n/2
    - caso pessimo: k è all'indice n   --> O(n) = non posso fare più di n confronti

    O grande -> descrive un limite asintotico superiore per la funzione considerata (al più)
    Omega grande -> descrive un limite asintotico inferiore per la funzione considerata (almeno)
    Teta -> descrive un limite asintoticamente stretto (esattamente)
*/

/* Ricerca sequenziale(lineare)		Complessità 0(n) Lineare

Necessaria quando gli elementi non sono ordinati. Confronta la chiave mediamente con la metà degli
elementi presenti.

-Caso migliore: 1
-Caso peggiore: n
-Caso medio: (n+1)/2

*/

void search(int vet[], int n, int key)
{

    cout << "\nRicerca lineare" << endl;

    int iter = 0;

    for (int i = 0; i < n; i++)
    {
        iter++;

        if (vet[i] == key)
        {
            cout << "Trovata alla " << iter << "° iterazione" << endl;
            return;
        }
    }

    cout << "Chiave non trovata! " << endl;
}

/* Ricerca binaria(dicotomica)		Complessità 0(log n) logatirmica

Inizio dal centro, successivamente mi sposto nel sottoarray destro o sinistro, dimezzando ogni volta
il numero di elementi da confrontare.

*/

void binary_search(int vet[], int n, int key)
{
    // Si assume che l'array sia ordinato

    cout << "\nRicerca binaria" << endl;

    int iter = 0;

    // indici
    int start = 0;
    int end = n - 1;

    bool found = false;

    while (!found && start != end) // found == false oppure !found == true
    {
        int middle = start + (end - start) / 2;

        iter++;
        if (vet[middle] == key)
            found = true;

        if (key < vet[middle]) // cerco a sx
            end = middle;

        if (key > vet[middle]) // cerco a dx
            start = middle;
    }

    if (found)
        cout << "Trovata alla " << iter << "° iterazione" << endl;
    else
        cout << "Chiave non trovata! " << endl;
}

/*
    RICORSIONE --> Induzione matematica

    es. ricerca binaria O(log n)

    Caso base: vet[mid] = key
    Passo induttivo: vet[mid] < key || vet[mid] > key

    Posso riscrivere quindi la funzione di ricerca binaria in funzione di se stessa
*/

// Versione ricorsiva		        Complessità 0(log n) logatirmica

void binary_search_ricorsive(int vet[], int n, int key, int start, int end)
{
    
    // Si assume che l'array sia ordinato

    int middle = start + (end - start) / 2;

    if (vet[middle] == key)
    {
        cout << "Key " << key << " found at index " << middle << endl;
        return;
    }

    if (start == end && vet[middle] != key)
        cout << "Chiave non trovata! " << endl;

    if (key < vet[middle]) // cerco a sx
        binary_search_ricorsive(vet, n, key, start, middle - 1);

    if (key > vet[middle]) // cerco a dx
        binary_search_ricorsive(vet, n, key, middle + 1, end);
}

void binary_search_ricorsive(int vet[], int n, int key)
{
    cout << "\nRicerca binaria con ricorsione: " << endl;

    int start = 0;
    int end = n - 1;

    return binary_search_ricorsive(vet, n, key, start, end);
}

/*
1)	Successore di un numero n:
    -	vale 1 se n=0 (Base dell'induzione)
    -	vale 1 + successore(n-1) (Passo dell'induzione)

        ex. succ(3) = 1 + succ(2) = 1 + 3 = 4
*/

int succ(int x)
{
    if (x == 0)
        return 1;
    return 1 + succ(x - 1);
}

/*
2) Somma di x e y:

    -   vale x se y = 0
    -   vale 1 + somma(x, y-1)

    ex. somma(2, 4) = 1 + somma(2, 3) = 6
*/

int sum(int x, int y)
{
    if (y == 0)
        return x;
    return 1 + sum(x, y - 1);
}

/*
3) Fattoriale di un numero naturale :
   Fatt(n)
   -	vale 1 se n=0;
   -    vale n*fatt(n-1) n>0;
*/

int fatt(int x)
{
    if (x == 0)
        return 1;
    return x * fatt(x - 1);
}

#endif