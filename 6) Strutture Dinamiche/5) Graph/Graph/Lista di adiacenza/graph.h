#ifndef GRAPH_H
#define GRAPH_H

#include "Linked_list.h"
// Specifica la classe lista, infatti ogni vertice è rappresentato da una lista che ha il vertice stesso
// come head e tutti i vertici a se adiacenti come nodi della lista

template <typename T>
class vertex : public List<T>
{

public:
    vertex(T key) : List<T>()
    {
        List<T>::insertHead(key);
    }

    friend ostream &operator<<(ostream &os, const vertex<T> &v)
    {

        os << "\nGraph vertex with key " << v.head->getVal() << ": ";

        os << "\tAdjecency list: "; // Stampo la lista di nodi adiacenti al vertice
        Node<T> *ptr = v.head;

        if (!ptr->getNext())
            return os << "no adjacent vertex !" << endl;

        while (ptr->getNext())
        {
            ptr = ptr->getNext();
            os << "-->" << ptr->getVal();
        }
        
        os << endl;

        return os;
    }
};

template <typename T>
class Graph
{

    List<vertex<T>> vertices;
    int n_vertices;
    bool isOriented;

public:
    Graph(bool isOriented = true) : isOriented(isOriented), n_vertices(0) {}

    bool isEmpty() const { return n_vertices == 0; }

    void add_vertex(T key)
    {

        vertex<T> toinsert(key);
        vertices.insertTail(toinsert);
        n_vertices++;
    }

    void add_edge(T key1, T key2)
    {

        Node<vertex<T>> *node1 = search(key1);
        Node<vertex<T>> *node2 = search(key2);

        if (node1 && node2)
        {
            // devo aggiungere node2 alla lista di adiacenza di node 1 per creare l'arco
            node1->getVal().insertTail(key2);

            if (!isOriented)
                node2->getVal().insertTail(key1);
        }
        else
        {
            if (!node1)
                cerr << "There isn't vertex with key " << key1 << endl;
            else
                cerr << "There isn't vertex with key " << key2 << endl;
        }
    }

    Node<vertex<T>> *search(T key)
    {

        if (isEmpty())
        {
            cerr << "Graph is empty!" << endl;
            return nullptr;
        }

        Node<vertex<T>> *ptr = vertices.getHead();
        
        while (ptr)
        {
            if (key == ptr->getVal().getHead()->getVal())
                return ptr;

            ptr = ptr->getNext();
        }

        cerr << "There isn't vertex with key " << key << endl;
        return nullptr;
    }

    friend ostream &operator<<(ostream &os, const Graph<T> &g)
    {

        if (g.isEmpty())
            return os << "\nEmpty Graph" << endl;

        if (!g.isOriented)
            os << "\nGraph isn't oriented";
        else
            os << "\nGraph is oriented";

        os << "\tNumber of vertices: " << g.n_vertices << endl;
        return os << g.vertices << endl;
    }
};

#endif