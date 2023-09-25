#ifndef BST_H
#define BST_H

template<typename T>
class BSTNode{

	T key;
	BSTNode<T>* parent;
	BSTNode<T>* right;
	BSTNode<T>* left;
	bool verbose;

	template<typename C>
	friend class BST;

public:

	BSTNode(T key, bool verbose = false) : key(key), verbose(verbose){
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

	friend ostream& operator<< (ostream& os, const BSTNode<T>& b){

		if(b.verbose){
			os << "BSTNode: " << &b << endl;
			os << "Key =" << b.key << endl;
			os << "left->" << b.left << "\t right->" << b.right << "\t parent->" << b.parent << endl;
			return os;
		}

		return os << b.key << endl;
	}
	
};

template<typename T>
class BST{
	
		BSTNode<T>* root;
		char last = 'l';	//indica come è avvenuto l'ultimo inserimento

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

			if(!ptr->left && key < ptr->key)
			{
				ptr->left = new BSTNode<T>(key);
				ptr->left->setParent(ptr);
				return;
			}

			if(!ptr->left && key == ptr->key && last == 'r')
			{
				ptr->left = new BSTNode<T>(key);
				ptr->left->setParent(ptr);
				last = 'l';
				return;
			}

			if(!ptr->right && key == ptr->key && last == 'l')
			{
				ptr->right = new BSTNode<T>(key);
				ptr->right->setParent(ptr);
				last = 'r';
				return;
			}

			if(!ptr->right && key > ptr->key)
			{
				ptr->right = new BSTNode<T>(key);
				ptr->right->setParent(ptr);
				return;
			}

			if(key < ptr->key)
				insert(ptr->left, key);

			if(key == ptr->key){
				if(last == 'l')
					insert(ptr->right, key);
				else
					insert(ptr->left, key);
			}

			if(key > ptr->key)
				insert(ptr->right, key);
		}

		void visit(BSTNode<T>* ptr) { 
			if(ptr == root){
				cout << "\nRoot: " << *ptr << endl; 
				return;
			}

			if(ptr == ptr->parent->left)
				cout << "\nLeft son: " << *ptr << endl; 

			else if(ptr == ptr->parent->right)
				cout << "\nRight son: " << *ptr << endl; 
		}

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