#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

template <typename T>
class vertex
{

protected:
    T key;

    template <typename C>
    friend class Graph;

public:
    vertex(T key) : key(key) {}

    T get_key() { return key; }

    friend ostream &operator<<(ostream &os, const vertex<T> &v) { return os << v.key; }
};

template <typename T>
class Graph
{

    vertex<T> **vertices; // array di puntatori a vertici
    bool **adj;           // matrice di adiacenza
    int n_vertices;
    int max_vertices;
    bool isOriented;

public:
    Graph()
    {
        n_vertices = 0;
        max_vertices = 10;
        isOriented = true;

        vertices = new vertex<T> *[max_vertices];

        adj = new bool *[max_vertices];
        for (int i = 0; i < max_vertices; i++)
            adj[i] = new bool[max_vertices]{false};
    }

    bool isEmpty() { return n_vertices == 0; }

    bool isFull() { return n_vertices == max_vertices; }

    void add_vertex(T key)
    {

        if (isFull())
        {
            cerr << "Graph is full! " << endl;
            return;
        }

        vertices[n_vertices++] = new vertex<T>(key);
    }

    int search(T key)
    {

        if (isEmpty())
        {
            cerr << "Empty graph..." << endl;
            return -1;
        }

        for (int i = 0; i < n_vertices; i++)
        {

            if (vertices[i]->key == key)
                return i;
        }

        return -1;
    }

    void add_edge(T key1, T key2)
    {

        int i = search(key1);
        int j = search(key2);

        if (i != -1 && j != -1)
        {
            adj[i][j] = true;

            if (!isOriented)
                adj[j][i] = true;
        }

        else
        {
            if (i == -1)
                cerr << "There isn't vertex with key " << key1 << endl;
            else
                cerr << "There isn't vertex with key " << key2 << endl;
        }
    }

    friend ostream &operator<<(ostream &os, Graph<T> &g)
    {

        if (g.isEmpty())
            return os << "\nGraph is empty!" << endl;

        os << "\nVertices: " << endl;

        for (int i = 0; i < g.n_vertices; i++)
            os << "\nv[" << i << "] = " << g.vertices[i]->get_key() << "\t";

        os << endl;
        os << "\nEdges: " << endl;

        for (int i = 0; i < g.n_vertices; i++)
        {
            for (int j = 0; j < g.n_vertices; j++)
            {
                if (g.adj[i][j])
                    os << "(" << i << ")-----(" << j << ")" << endl;
            }
        }

        return os;
    }

    void print_adj()
    {

        cout << "\nAdj: \n"
             << endl;

        cout << "V:";

        for (int i = 0; i < n_vertices; i++)
            cout << "\t" << *vertices[i] << "   ";

        cout << "\n------------------------------------\n";

        for (int i = 0; i < n_vertices; i++)
        {
            cout << *vertices[i] << ":";

            for (int j = 0; j < n_vertices; j++)
                cout << "\t" << adj[i][j] << "   ";

            cout << endl;
        }
    }
};

#endif