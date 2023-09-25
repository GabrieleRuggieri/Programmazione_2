#ifndef BST_H
#define BST_H

#include "bst_node.h"

template<typename T>
class BST{
	
		BSTNode<T>* root;

	public:

		BST(){root = nullptr;}
		
		BSTNode<T>* getRoot(){return this->root;}

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

			if(!ptr->left && key->getCilindrata() <= ptr->key->getCilindrata())
			{
				ptr->left = new BSTNode<T>(key);
				ptr->left->setParent(ptr);
				return;
			}

			if(!ptr->right && key->getCilindrata() > ptr->key->getCilindrata())
			{
				ptr->right = new BSTNode<T>(key);
				ptr->right->setParent(ptr);
				return;
			}

			if(key->getCilindrata() <= ptr->key->getCilindrata())
				insert(ptr->left, key);

			else
				insert(ptr->right, key);
		}

		void visit(BSTNode<T>* ptr) { cout << *ptr; }
		void inOrder(BSTNode<T>* ptr){

			if(!ptr)
				return;

			inOrder(ptr->left);
			visit(ptr);
			inOrder(ptr->right);
		}
		void inOrder(){
			if(isEmpty())
				throw out_of_range("...empty BST...");
			inOrder(root);
		}

		BSTNode<T>* min(){return min(root);}
		BSTNode<T>* min(BSTNode<T>* from){

			if(isEmpty())
                throw out_of_range("Empty bst...");

			BSTNode<T>* ptr = from;
			while(ptr->left)
				ptr = ptr->left;

			return ptr;
		}
        BSTNode<T>* max(){return max(root);}
		BSTNode<T>* max(BSTNode<T>* from){

			if(isEmpty())
                throw out_of_range("Empty bst...");

			BSTNode<T>* ptr = from;
			while(ptr->right)
				ptr = ptr->right;

			return ptr;
		}
		BSTNode<T>* successor(T key){

            BSTNode<T>* ptr = search(key);
            if(!ptr || ptr == max())
                throw out_of_range("...successor doesn't exist...");

            return successor(ptr);
        }
		BSTNode<T>* successor(BSTNode<T>* x){

			if(isEmpty())
				return nullptr;

			if(x->right) 
				return min(x->right);

			BSTNode<T>* y = x->parent;
			while(x && x == y->right)  //fino a che x non è un figlio sinistro
			{
				x = y;
				y = y->parent;
			}

			return y;
		}

		BSTNode<T>* search(T key){
			if(isEmpty())
                throw out_of_range("Empty bst...");

			return search(root, key);
		}
		BSTNode<T>* search(BSTNode<T>*ptr , T key){

			if(!ptr)
				return nullptr;

			if(ptr->key->getCilindrata() == key->getCilindrata())
				return ptr;

			if(key->getCilindrata() <= ptr->key->getCilindrata())
				return search(ptr->left, key);

			else
				return search(ptr->right, key);
		}

		BSTNode<T>* remove(BSTNode<T>* node){ 

			//Caso 1: node è una foglia
			if(!node->left && !node->right)
			{
				if(node == node->parent->left)
					node->parent->left = nullptr;

				else if(node == node->parent->right)
					node->parent->right = nullptr;

				return node;
			}

			//Caso 2: node ha un solo figlio
			if(!node->right && node->left)
			{
				node->left->setParent(node->parent);

				if(node == node->parent->left)
					node->parent->left = node->left;

				else if(node == node->parent->right)
					node->parent->right = node->left;

				return node;
			}

			if(!node->left && node->right)
			{
				node->right->setParent(node->parent);

				if(node == node->parent->left)
					node->parent->left = node->right;

				else if(node == node->parent->right)
					node->parent->right = node->right;

				return node;
			}

			return nullptr;
		}
		BSTNode<T>* remove(T key){

			if(isEmpty()) //albero vuoto
				return nullptr;

			BSTNode<T>* node = search(key);

			if(!node)  //nodo non trovato
				return nullptr;

			BSTNode<T>* toDelete = remove(node);

			//se non sono nel terzo caso mi ritorno il valore del nodo, che ho comunque cancellato con "remove(node)"

			if(toDelete != nullptr) 
				return toDelete;

			//Caso 3 -> Voglio eliminare un nodo con due figli

			//Sostituisco il nodo da cancellare con il successore
			BSTNode<T>* next = successor(node);

			//Sostituisco la chiave
			T swap = node->key;
			node->key = next->key;
			next->key = swap;

			toDelete = remove(next); //stavolta sono sicuramente in uno dei due casi precedenti
			return toDelete;
		}
		
        //Below 
	    void cancel_below(BSTNode<T>* ptr, int cilindrata){
	        if(ptr->key->getCilindrata() <= cilindrata)
	        	remove(ptr->key);
	    }
	    void remove_below(BSTNode<T>* ptr, int cilindrata){
	        if(!ptr)
	            return;
	        remove_below(ptr->right, cilindrata);
	        cancel_below(ptr, cilindrata);
	        remove_below(ptr->left, cilindrata);
	    }
	    void remove_below(int cilindrata){remove_below(root, cilindrata);}
};

#endif