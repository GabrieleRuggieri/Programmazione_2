#ifndef BST_NODE_H
#define BST_NODE_H

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

	friend ostream& operator<< (ostream& os, const BSTNode<T>& b){return os << "\tKey: " << *b.key << endl;}
	
};

#endif