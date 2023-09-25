#ifndef BST_H
#define BST_H

#include "BSTNode.h"

template<typename T>
class BST{
	
		BSTNode<T>* root;

	public:

		BST(){root = nullptr;}
		
		bool isEmpty(){return root == nullptr;}

		void insert(T key){
			
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

		void visit(BSTNode<T>* ptr) { cout << "\n" << *ptr << endl; }
 
		void in_order(BSTNode<T>* ptr){

			if(!ptr)
				return;

			in_order(ptr->left);
			visit(ptr);
			in_order(ptr->right);
		}

		void in_order(){in_order(root);}
};

#endif