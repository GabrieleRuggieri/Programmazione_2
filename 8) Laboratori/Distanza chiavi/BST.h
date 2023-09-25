#ifndef BST_H
#define BST_H

template<typename H>
class BSTNode{

	H key;
	BSTNode<H>* parent;
	BSTNode<H>* right;
	BSTNode<H>* left;

	template<typename T>
	friend class BST;

	public:

	BSTNode(H key) : key(key){
		parent = nullptr;
		right = nullptr;
		left = nullptr;
	}

	//Getter
	BSTNode<H>* getParent(){return this->parent;}
	BSTNode<H>* getRight(){return this->right;}
	BSTNode<H>* getLeft(){return this->left;}
	H getKey(){return this->key;}

	//Setter
	void setParent(BSTNode<H>* parent){this->parent = parent;}
	void setRight(BSTNode<H>* right){this->right = right;}
	void setLeft(BSTNode<H>* left){this->left = left;}
	void setKey(H key){this->key = key;}

	friend ostream& operator<< (ostream& os, BSTNode<H>& b){
		os << "key= " << b.key;
		return os;
	}
};

template<typename H>
class BST{
	
		BSTNode<H>* root;
		static int count;

	public:

		BST(){root = nullptr; count=0;}
		
		BSTNode<H>* getRoot(){return this->root;}

		bool isEmpty(){return root == nullptr;}

		void insert(H key){
			
			if(isEmpty())
			{
				root = new BSTNode<H>(key);
				return;
			}

			insert(root, key);
		}

		void insert(BSTNode<H>* ptr, H key){

			if(!ptr->left && key <= ptr->key)
			{
				ptr->left = new BSTNode<H>(key);
				ptr->left->setParent(ptr);
				return;
			}

			if(!ptr->right && key > ptr->key)
			{
				ptr->right = new BSTNode<H>(key);
				ptr->right->setParent(ptr);
				return;
			}

			if(key <= ptr->key)
				insert(ptr->left, key);

			else
				insert(ptr->right, key);
		}

		void visit(BSTNode<H>* ptr) { cout << "\n" << ++count << ") " << *ptr ; }
		
		void in_order(BSTNode<H>* ptr){

			if(!ptr)
				return;

			in_order(ptr->left);
			visit(ptr);
			in_order(ptr->right);
		}

		void in_order(){in_order(root);}

		BSTNode<H>* min(){return min(root);}

		BSTNode<H>* min(BSTNode<H>* from){

			if(isEmpty())
				throw "Void BST!";

			BSTNode<H>* ptr = from;
			while(ptr->left)
				ptr = ptr->left;

			return ptr;
		}

		BSTNode<H>* successor(BSTNode<H>* x){

			if(isEmpty())
				return nullptr;

			if(x->right)
				return min(x->right);

			BSTNode<H>* y = x->parent;
			while(x && x == y->right)  //fino a che x non è un figlio sinistro
			{
				x = y;
				y = y->parent;
			}

			return y;
		}

		BSTNode<H>* search(H key){return search(root, key);}

		BSTNode<H>* search(BSTNode<H>*ptr , H key){

			if(!ptr)
				return nullptr;

			if(ptr->key == key)
				return ptr;

			if(key <= ptr->key)
				return search(ptr->left, key);

			else
				return search(ptr->right, key);
		}

		/*prese in input due chiavi k e h, sia in grado di calcolare la distanza tra i nodi 
		che contengono k e h rispettivamente.*/
/*
		int distanzaChiavi(H k, H h){

			BSTNode<H>* nodo_k = search(k);
			BSTNode<H>* nodo_h = search(h);

			if(!nodo_k || !nodo_h)
			{
				cout << "Chiavi errate!" << endl;
				return -1;
			}

			if(nodo_k == nodo_h)
				return 0;

			int distanza = 0;

			//Se entrambe le chiavi appartengono a dei nodi dell'albero
			if(k <= h)
			{
				while(successor(nodo_k))
				{
					nodo_k = successor(nodo_k);
					distanza++;
					
					if(nodo_k == nodo_h)
						break;
				}
				return distanza;
			}
			else
				return distanzaChiavi(h, k);
		}
*/
		int from_root(BSTNode<H>* nodo_h, BSTNode<H>* partenza){

			//partenza = radice del sottoalbero ottenuto mettendo nodo_k come radice

			if(partenza->key == nodo_h->key) //distanza tra un nodo e se stesso
				return 0;

			BSTNode<H>* tmp = partenza;
			int counter = 0;  //distanza tra padre e figlio

			while(tmp && tmp->key != nodo_h->key) //esco quando arrivo ad una foglia 
												//oppure quando trovo il nodo
			{
				if(nodo_h->key > tmp->key) 
					tmp = tmp->right;
				else 
					tmp=tmp->left;

				counter++;
			}
			
			if(!tmp) 
				return -1;
			else 
				return counter;  
			
		}

		int distanzaChiavi(H k, H h) {

			BSTNode<H>* nodo_k = search(k);
			BSTNode<H>* nodo_h = search(h);

			int counter=0;

			if(!nodo_k || !nodo_h)
				throw ("Chiavi errate!");		//Sollevo un eccezzione
					
			if(k <= h)
			{
				BSTNode<H>* tmp = nodo_k;
				bool flag = true;

				while(tmp && flag) 
				{
					int distance = from_root(nodo_h, tmp); 

					if(distance == 0) //k e h coincidono
						flag = false;
					
					else if(distance == -1)
					{
						tmp = tmp->parent;  //salgo 
						counter++; 
					}
					else 
					{
						counter += distance;
						flag = false;
					}
				}

				return counter;
			}
			else
				return distanzaChiavi(h, k); //inverto per ottenere k <= h
		}
};

template<typename H>
int BST<H> :: count = 0;

#endif