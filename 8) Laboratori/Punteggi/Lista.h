#ifndef LISTA_H
#define LISTA_H

#include "Node.h"

#include <cstdlib>

class List{

		Node* head;
		Node* tail;

	public:

		List(){ 

			head = nullptr; 
			tail = nullptr; 
		}

		bool isEmpty(){ return head == nullptr && tail == nullptr; }

		void insertHead(Giocatore val){

			if(isEmpty())
			{
				head = new Node(val);
				tail = head;
				return;
			}

			Node* toinsert = new Node(val);
			toinsert->next = head;
			head = toinsert;
			return;
		}

		void insertTail(Giocatore val){

			if(isEmpty()){
				insertHead(val);
				return;
			}

			Node* toinsert = new Node(val);
			tail->next = toinsert;
			tail = toinsert;
			return;
		}

		void insert_in_order_ascending(Giocatore val){
			
			if(isEmpty() || val <= head->val)
			{
				insertHead(val);
				return;
			}
			
			Node* ptr = head;
						
			while(ptr->next && val >= ptr->val) 
			{
				if(val <= ptr->next->val)
					break;
				
				ptr = ptr->next;
			}
			
			if(!ptr->next)
			{
				insertTail(val);
				return;
			}
			
			Node* toinsert = new Node(val);
			toinsert->next = ptr->next;
			ptr->next = toinsert; 
			return;
		}
		
		void insert_in_order_descending(Giocatore val){
			
			if(isEmpty() || val <= head->val)
			{
				insertHead(val);
				return;
			}
			
			Node* ptr = head;
			
			while(ptr->next && val <= ptr->val) 
			{
				if(val >= ptr->next->val)
					break;
				
				ptr = ptr->next;
			}

			if(!ptr->next)
			{
				insertTail(val);
				return;
			}
			
			Node* toinsert = new Node(val);
			toinsert->next = ptr->next;
			ptr->next = toinsert; 
			return;
		}
		
		void insert_in_order(Giocatore val, string choise){
			
			if(choise == "Crescente")
			{
				insert_in_order_ascending(val);
				return;
			}
			
			if(choise == "Decrescente")
			{
				insert_in_order_descending(val);
				return;
			}

			cerr << "Crescente/Decrescente ?" << endl;
			return;
		}

		void removeHead(){
			
			if(isEmpty())
			{
				cerr << "Empty list!" << endl;
				return;
			}
			
			Node* tmp = head;
			head = head->next; 
			delete tmp;
			return;
		}
		
		void removeTail(){
			
			if(isEmpty())
			{
				cerr << "Empty list!" << endl;
				return;
			}
			
			if(head == tail) //Se c'è un solo elemento 
			{
				Node* ptr = tail;
				head = nullptr;  
				tail = nullptr;
				delete ptr;
			}
			
			Node* cur = head;
			Node* prev = nullptr;
			
			while(cur->next)
			{
				prev = cur;
				cur = cur->next;
			}
			
			tail = prev;
			prev->next = nullptr;
			delete cur;
			return;
		}

		void remove_element(Giocatore val){
			
			if(head->val == val)
			{
				removeHead();
				return;
			}

			Node* cur = head;
			Node* prev = nullptr;

			while(cur->next &&  cur->val != val)
			{
				prev = cur;
				cur = cur->next;
			}

			prev->next = cur->next;
			delete cur;
			return;

		}

		friend ostream& operator<< (ostream& os, List& l){
			
			if(l.isEmpty())
			{
				os << "\nEmpty list" << endl;
				return os;
			}

			int idx = 1;
			Node* ptr = l.head;
			while(ptr)
			{
				os << "\nGiocatore n°" << idx << endl;
				os << "\t" << *ptr << endl;
				ptr = ptr->get_next();

				idx++;
			}
			
			return os;
		}

		static List create(List& l){

			ifstream fin("Punteggi.txt");

			while(fin.good())
			{
				Giocatore g;
				fin >> g;  //Inizializza i parametri dell'istanza g
				l.insertTail(g);
			}
			fin.close();

			return l;
		}

		void swap (Node* & n1, Node* & n2){
			Giocatore tmp = n1->val;
			n1->val = n2->val;
			n2->val = tmp;

			return;
		}

		void sorting(string choise){

			if(choise == "Crescente")
			{
				Node* cur;
				Node* succ;

				for (cur = head; cur->next;  cur = cur->next)
			    {
			        for (succ = cur->next; succ; succ = succ->next)
			        {
			            if (cur->val >= succ->val)
			            	swap(cur, succ);
			        }
			    }

				return;
			}
			
			else if(choise == "Decrescente")
			{
				Node* cur;
				Node* succ;

				for (cur = head; cur->next;  cur = cur->next)
			    {
			        for (succ = cur->next; succ; succ = succ->next)
			        {
			            if (cur->val <= succ->val)
			            	swap(cur, succ);
			        }
			    }

				return;
			}

			else
				cerr << "Crescente/Decrescente ?" << endl;

			return;
		}

		static void print(List& l, string choise){

			if(choise == "Crescente")
				l.sorting("Crescente");
			
			else if(choise == "Decrescente")
				l.sorting("Decrescente");

			else 
				cerr << "Crescente/Decrescente ?" << endl;

			cout << l << endl;

			return;
		}

		static void get_info (List& l, string key){

			bool found = false;

			Node* tmp = l.head;
			while(tmp->next)
			{
				if(tmp->val.get_cognome() == key)
				{	
					found = true;
					break;
					cout << *tmp << endl;
				}

				tmp = tmp->next;
			}

			if(!found)
			{
				cerr << "Void list or Element with key " << key << " not found!" << endl;
				return;
			}
			else
				cout << *tmp << endl;

			cout << "Others players with same score are: " << endl;

			Node* ptr = l.head;  
			while(ptr->next)
			{
				if (ptr->val.get_punteggio() == tmp->val.get_punteggio())
				{
					if(ptr != tmp)
						cout << *ptr << endl;
				}

				ptr = ptr->next;
			}

			return;
		}

		void remove_player(List& l, double key){

			if(isEmpty())
			{
				cerr << "\nVoid list, impossible find element with key " << key << " !" << endl;
				return;
			}

			Node* cur = head;
			bool found = true;

			while(cur->next)
			{
				if(cur->val.get_punteggio() == key)
					remove_element(cur->val);

				cur = cur->next;
			}

			if(cur->val.get_punteggio() != key) 
				cerr << "\nElement with key " << key << " not found!" << endl;

			return;	
		}
};


#endif