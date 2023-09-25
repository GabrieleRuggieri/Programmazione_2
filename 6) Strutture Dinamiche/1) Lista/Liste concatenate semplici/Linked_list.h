#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
using namespace std;

template <typename T>
class Node
{

protected:
	T val;
	Node<T> *next;

	template <typename W>
	friend class List;

public:
	Node(T val) : val(val) { next = nullptr; }

	T getVal() { return this->val; }

	Node<T> *getNext() { return this->next; }

	friend ostream &operator<<(ostream &os, const Node<T> &n) { return os << n.val; }
};

template <typename T>
class List
{

	Node<T> *head;

public:
	List() { head = nullptr; }

	Node<T> *getHead() { return this->head; }

	bool isEmpty() { return !head; }

	void insertHead(T val)
	{

		if (isEmpty())
		{
			head = new Node<T>(val);
			return;
		}

		Node<T> *toinsert = new Node<T>(val);
		toinsert->next = head;
		head = toinsert;

	}

	void insertTail(T val)
	{

		if (isEmpty())
		{
			insertHead(val);
			return;
		}

		Node<T> *cur = head;

		while (cur->next)
			cur = cur->next;

		Node<T> *toinsert = new Node<T>(val);
		cur->next = toinsert;

	}

	void insertInOrder(T val, char c)
	{
		do
		{
			if (c == 'a') // ascending
			{
				insertInOrderAscending(val);
				return;
			}
			else if (c == 'd') // descending
			{
				insertInOrderDescending(val);
				return;
			}
			else
			{
				cerr << "\nChose between 'a' or 'd' ! " << endl;
				cin >> c;
			}

		} while (c != 'a' && c != 'd');
	}

	void insertInOrderAscending(T val)
	{

		if (isEmpty() || val <= head->val)
		{
			insertHead(val);
			return;
		}

		Node<T> *cur = head;

		while (cur->next && val >= cur->val)
		{
			if (val < cur->next->val)
				break;

			cur = cur->next;
		}

		if (!cur->next)
		{
			insertTail(val);
			return;
		}

		Node<T> *toinsert = new Node<T>(val);
		toinsert->next = cur->next;
		cur->next = toinsert;

		return;
	}

	void insertInOrderDescending(T val)
	{

		if (isEmpty() || val >= head->val)
		{
			insertHead(val);
			return;
		}

		Node<T> *cur = head;

		while (cur->next && val <= cur->val)
		{
			if (val > cur->next->val)
				break;

			cur = cur->next;
		}

		if (!cur->next)
		{
			insertTail(val);
			return;
		}

		Node<T> *toinsert = new Node<T>(val);
		toinsert->next = cur->next;
		cur->next = toinsert;

		return;
	}

	void removeHead()
	{

		if (isEmpty())
		{
			cerr << "Empty List! Operation isn't avaible! " << endl;
			return;
		}

		Node<T> *ptr = head;
		head = head->next;
		delete ptr;

		return;
	}

	void removeTail()
	{

		if (isEmpty())
		{
			cerr << "Empty List! Operation isn't avaible! " << endl;
			return;
		}

		Node<T> *cur = head;
		Node<T> *prev = nullptr; // prev lo uso per mantenere un riferimento al nodo precedente di cur

		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}

		prev->next = nullptr; // si interrompe il collegamento con l'ultimo nodo cosi posso rimuoverlo
		delete cur;

	}

	Node<T> *search(T val)
	{

		if (isEmpty())
			throw out_of_range("...list is empty...");

		if (head->val == val)
			return head;

		Node<T> *cur = head;

		while (cur->next && cur->val != val)
			cur = cur->next;

		if (cur->val != val)
		{
			cerr << "Element with key " << val << " not found!" << endl;
			return nullptr;
		}

		return cur;
	}

	void removeElement(T val)
	{

		if (isEmpty())
		{
			cerr << "Empty List! Operation isn't avaible! " << endl;
			return;
		}

		Node<T> *toremove = search(val);

		if (!toremove)
			return;

		if (toremove->val == head->val)
		{
			removeHead();

			return;
		}

		Node<T> *cur = head;
		Node<T> *prev = nullptr;

		while (cur->next && cur->val != toremove->val)
		{
			prev = cur;
			cur = cur->next;
		}

		prev->next = cur->next;
		delete cur;
	}

	void inverti(Node<T> *ptr)
	{
		Node<T> *cur = new Node<T>(*ptr); // inizializzato al puntatore di partenza
		Node<T> *prev = nullptr;
		Node<T> *succ = nullptr;

		while (cur)
		{
			succ = cur->next; // succ viene impostato per puntare al nodo successivo al nodo corrente cur.

			cur->next = prev; // Il puntatore next del nodo corrente cur viene impostato per puntare al nodo precedente prev. In pratica, si inverte il collegamento tra i nodi.

			prev = cur; // prev viene aggiornato per puntare al nodo corrente cur.
			cur = succ; // cur viene aggiornato per puntare al nodo successivo succ.
		}

		head = prev; // Quando il ciclo while termina, il puntatore head viene impostato per puntare all'ultimo nodo visitato, che diventa quindi il nuovo nodo di testa della lista invertita.
	}

	void inverti()
	{
		if (isEmpty())
		{
			cerr << "Empty List! Operation isn't avaible! " << endl;
			return;
		}

		inverti(this->head);
	}

	friend ostream &operator<<(ostream &os, List<T> &l)
	{

		if (l.isEmpty())
			return os << "\nEmpty List !" << endl;

		os << "\nHead: " << *l.head << endl;
		os << "\nLinked_list: " << endl;

		Node<T> *ptr = l.head;
		os << "\nHead --> ";
		while (ptr)
		{
			os << *ptr << " --> ";
			ptr = ptr->getNext();
		}

		return os << "NIL" << endl
				  << "\nEnd List\n"
				  << endl;
	}
};

#endif