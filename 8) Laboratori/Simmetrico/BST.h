#ifndef BST_H
#define BST_H

#include "Queue_dinamic.h"

template<typename T>
class BSTNode{
	T key;
	BSTNode<T>* parent;
	BSTNode<T>* right;
	BSTNode<T>* left;
	template<typename C>
	friend class BST;
public:
	BSTNode(T key) : key(key){
		parent = nullptr;
		right = nullptr;
		left = nullptr;
	}
	//Getter
	BSTNode<T>* getParent(){return this->parent;}
	BSTNode<T>* getRight(){return this->right;}
	BSTNode<T>* getLeft(){return this->left;}
	T getKey(){return this->key;}

	//Setter
	void setParent(BSTNode<T>* parent){this->parent = parent;}
	void setRight(BSTNode<T>* right){this->right = right;}
	void setLeft(BSTNode<T>* left){this->left = left;}
	void setKey(T key){this->key = key;}
	friend ostream& operator<< (ostream& os, const BSTNode<T>& b){return os << b.key;}
};

template<typename T>
class BST{
	BSTNode<T>* root;
	Queue_dynamic<T> nodes;
public:
	BST(){root = nullptr;}
	BSTNode<T>* getRoot(){return this->root;}
	bool isEmpty(){return !root;}
	void insert(T key){
		nodes.enqueue(key);
		if(isEmpty())
		{
			root = new BSTNode<T>(key);
			return;
		}
		insert(root, key);
	}
	void insert(BSTNode<T>* ptr, T key){
		if(!ptr->left && key <= ptr->key)
		{
			ptr->left = new BSTNode<T>(key);
			ptr->left->setParent(ptr);
			return;
		}
		if(!ptr->right && key > ptr->key)
		{
			ptr->right = new BSTNode<T>(key);
			ptr->right->setParent(ptr);
			return;
		}
		if(key <= ptr->key)
			insert(ptr->left, key);
		else
			insert(ptr->right, key);
	}
	void visit(BSTNode<T>* ptr) { 
		if(ptr == root){
			cout << "\n" << *ptr << "(root)" << endl; 
			return;
		}
		if(ptr == ptr->parent->left)
			cout << "\n" << *ptr << "(left son from " << *ptr->parent << ")" << endl; 

		else if(ptr == ptr->parent->right)
			cout << "\n" << *ptr << "(right son from " << *ptr->parent << ")" << endl; 
	} 
	void in_order(BSTNode<T>* ptr){
		if(!ptr)
			return;
		in_order(ptr->left);
		visit(ptr);
		in_order(ptr->right);
	}
	void in_order(){in_order(root);}
/*
	//Per il funzionamento inserire "int nodes" tra gli attributi ed incrementarlo dopo ogni inserimento;
	void put(BSTNode<T>* ptr, T*& vals){ 
		static int idx = 0;
		vals[idx++] = ptr->getKey(); 
	}
	void fill(BSTNode<T>* ptr, T* vals){	//Il metodo "riempie" l'array "vals" con tutte le chiavi dei nodi nell'albero
		if(!ptr)
			return ;
		put(ptr, vals);
		fill(ptr->left, vals);
		fill(ptr->right, vals);
	}
*/
	void insert_symmetric(T key){
		if(isEmpty())
		{
			root = new BSTNode<T>(key);
			return;
		}
		insert_symmetric(root, key);
	}
	void insert_symmetric(BSTNode<T>* ptr, T key){
		if(!ptr->left && key > ptr->key)
		{
			ptr->left = new BSTNode<T>(key);
			ptr->left->setParent(ptr);
			return;
		}
		if(!ptr->right && key <= ptr->key)
		{
			ptr->right = new BSTNode<T>(key);
			ptr->right->setParent(ptr);
			return;
		}
		if(key > ptr->key)
			insert_symmetric(ptr->left, key);
		else if(key <= ptr->key)
			insert_symmetric(ptr->right, key);
	}
	BST<T>* symmetric(){
		BST<T>* toreturn = new BST<T>;
		if(nodes.isEmpty())
			throw out_of_range("..symmetric fail! Empty BST!..");

		DLNode<T>* ptr  = nodes.head;
		while(ptr)
		{
			toreturn->insert_symmetric(ptr->getVal());
			ptr = ptr->getNext();
		}

		return toreturn;
	}
};

#endif