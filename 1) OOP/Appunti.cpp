/*
	1) Astrazione :

		Generalizzare il concetto da affrontare per ottenere un'interfaccia comune a tutti gli oggetti

	2) Incapsulamento(information hiding) :

		Utilizzo di "modificatori di accesso" in modo che alcune informazioni risultino pubbliche e altre rimangano private
		all'interno della classe e accessibili solo ai membri della classe stessa.

		+ public : accessibili anche al di fuori della classe;
		# protected : contenuti accessibili solo all'interno della classe e da classi derivate ed INACCESSIBILE all'esterno;
		- private : accessibili solo ai membri della classe;


	3) Ereditarietà :

		Meccanismo che consente livelli di astrazione gerarchici che consentono di conservare le proprietà della classe madre
		nelle classi figlie.

		-part of:
			Aggregazione : l'oggetto contenuto può essere istanziato a prescindere dall'oggetto che lo contiene (proprietario e automobile)
			Composizione : la vita dell'oggetto contenuto è legata all'oggetto che lo contiene (motore e automobile)

		- derivazione:
			un'oggetto di classe figlia viene istanziato per ampliare e specificare l'oggetto di classe madre:

				class [nome classe derivata] : <mod_accesso> [nome classe madre] {
					---
					attrib.
					---
					metodi
				};

		class Taxi : public Automobile {
			public rimane public
			protected rimane protected
			private rimane inaccessibile
		};

		class Taxi : private Automobile {
			public diventa private
			protected diventa private
			private rimane inaccessibile
		};

		class Taxi : protected Automobile {
			public diventa protected
			protected rimane protected
			private rimane inaccessibile
		};

	4) Polimorfismo

		la proprietà in base alla quale oggetti differenti possono rispondere in maniera diversa allo stesso messaggio.

		QUANDO LO OTTENGO ????
		Quando in una gerarchia ereditaria vi sono ridefinizioni degli stessi metodi (stessa signature, NO OVERLOADING) che assume un
		comportamento diverso a seconda del chiamante, quindi Overriding

		Binding -> connessione tra la chiamata di una funzione ed il blocco di codice che la implementa

		- statico : binding a compile-time
		- dinamico : binding a run-time (tramite puntatori e reference alla classe base)

		class formaGeometrica
		{
			public:
				virtual double getArea()const = 0; 		//virtual pure function
		};

		class Cerchio : public formaGeometrica
		{
			public:
				double getArea()const{	//overriding
					return PI*pow(r,2);
				}
		};

		class Rettangolo : public formaGeometrica
		{
			public:
				double getArea()const{	//overriding
					return base * altezza;
				}
		};

		int main()
		{
			formaGeometrica* s[20];
			for(int i=0; i<20; i++)
				s[i] -> getArea();	// il compilatore come lo interpreta ?!
		}

		Dinamic binding -> il compilatore non sa compe interpretare il getArea(), sarà determinato a run-time

		Come usarlo ?!

			1)	creo una gerarchia e definisco i metodi comuni a tutte le istanze nella classe madre
			2)	ridefinisco questi ultimi nelle classi figlie
			3)	invoco i metodi tramite puntatori o reference

		Vantaggi ?!

			Consento a programmi che manipolano puntatori a classe base di determinare il tipo di oggetto solo durante l'esecuzione del programma (run-time).

		Come invoco un metodo la cui istanza non è precisata a compile-time ?

			Sfrutto il meccanismo di RTTI

			1) dynamic_cast + controllo dell'esistenza puntatore

			2) typeid() + static_cast

	int main()
	{
		formaGeometrica* s[20];
		for(int i=0; i<20; i++)
		{
			if(typeid(s[i]) == typeid(Cerchio))
				static_cast<Cerchio*>(s[i])->getArea();

			if(typeid(s[i]) == typeid(Rettangolo))
				static_cast<Rettangolo*>(s[i])->getArea();
		}
	}
*/

// #include <iostream>
// using namespace std;

// class Rettangolo{
//   private:
//    int width;
//    int height;
//   public:
//     void set_values(int, int );
//     int area();
//
//     void Rettangolo::set_values(int x, int y){
//     height=x;
//     width=y;
//    }
// };

// void Rettangolo::set_values(int x, int y){
//     height=x;
//     width=y;
// }
// metodo voi che viene definito con operatore di scope per
// specificare la classe a cui appartiene..cosi puo accedere
//  ai suoi attributi private;

// Classe con 2 attributi private e due metodi public
//  set_values setta i valori e area che calcola
//  l'area dei valori scritti su width e height,

//---------------------------

/*  Si riscriva il seguente metodo utilizzando
l’inizializzazione dei membri mediante notazione :


#include<iostream>
using namespace std;

class RectangleV3 {
    int width, height;
  public:
    RectangleV3(int, int);
    int area() {return (width*height);}
};

RecangleV3::RectangleV3(int l) {
    width = l;
    height = l;
}
RectangleV3::RectangleV3(int l): width(l), height(l) {}

*/

//-------------------------------

//GET E SET

/*

NON possiamo mettere in output i membri private delle classi
percio utliziamo get e set per poter vederli manipolarli e sovrascriverli

#include<iostream>
using namespace std;

class RectangleV4 {
    int width, height;
  public:
    RectangleV4(int w, int h) : width(w), height(h){}
    int getWidth() {return width;}
    int getHeight() {return height;}
    int area() {return (width*height);}
};

int main(){

RectangleV4 r(2,3);

cout << r.getWidth() << endl;
cout << r.getHeight() << endl;



}






Se volessimo poter sovrascrivere questi valori, potremmo usare dei metodi “setter”:

#include<iostream>
using namespace std;

class RectangleV5 {
    int width, height;
  public:
    RectangleV5(int w, int h) : width(w), height(h){}

    int getWidth() {return width;}
    int getHeight() {return height;} //no parametri in input e ha return


    void setWidth(int w) {width=w;}// si parametri in input no return ma uguaglianza
    void setHeight(int h) {height=h;}

    int area() {return (width*height);}
};


esempio fatto in cerchio.cpp vedi ---> cerchio.cpp



*/

// OVERLOADING COSTRUTTORI

/*
#include<iostream>
using namespace std;

class RectangleV2 {
    int width, height;
  public:
    RectangleV2() { //rettangolo "vuoto"
        width = 0;
        height = 0;
    }
    RectangleV2(int l) { //quadrato di lato l
        width = l;
        height = l;
    }
    RectangleV2(int w, int h) { //quadrato standard
        width = w;
        height = h;
    }
    int area() {return (width*height);}
};



int main(){
   RectangleV2 r1; //vuoto
   RectangleV2 r2(5); //quadrato 5 x 5
   RectangleV2 r3(2,3); //rettangolo 2 x 3

   cout << r1.area() << endl;
   cout << r2.area() << endl;
   cout << r3.area() << endl;




  */

//--------------------------------

// PUNTATORI A OGGETTI

/*




//CREATO OGGETTO


CREATO PUNTATORE A OGGETTO
PASSATA LA REFERENZE DELL' OGGETTO

RectangleV5 r(2,3);
RectangleV5 *r_ptr;
r_ptr = &r;





//ALLOCAZIONE DINAMICA

RectangleV2 *r1 = new RectangleV2;
RectangleV2 *r2 = new RectangleV2(); //analogo al precedente
RectangleV2 *r3 = new RectangleV2(2);
RectangleV2 *r4 = new RectangleV2(2,3);



//RICORDA DI DEREFERENZIARE

cout << (*r1).area() << endl;
cout << (*r2).area() << endl;
cout << (*r3).area() << endl;
cout << (*r4).area() << endl;

oppure

cout << r1->area() << endl;


VEDI PUNTATORICLASS.CPP
*/

//---------------------
/*


RELAZIONE AGGREGAZIONE E COMPOSIZIONE

AGGREGAZIONE NON PER FORZA L'OGGETTO CONTENUTO HA STESSO CICLO DI VITA DEL OGGETTO
CONTENITORE,


definiamo la classe persona

class Persona {
    string nome;
    string cognome;
    int eta;

    public:
        Persona(string n, string c, int e) : nome(n), cognome(c), eta(e) {}
};

Una classe automobile può mantere un riferimento al suo proprietario mediante
 l’attributo proprietario di tipo Persona. Tuttavia, dato che una persona può
 possedere più di una automobile, la relazione non sarà di composizione.
 In questo caso, ha senso che proprietario sia
in effetti un puntatore a Persona in modo da mantenere l’indipendenza tra i due oggetti:



class Automobile {
    string modello;
    Persona *proprietario;
    public:
        Automobile(string m, Persona *p) : modello(m), proprietario(p) {}
        void cambiaProprietario(Persona *p) {};
};

Persona p1("Mario", "Rossi", 23);
Persona p2("Giuseppe", "Verdi", 77);
Automobile a1("Ford Fiesta", &p1);
Automobile a2("Renault Captur", &p1);
a2.cambiaProprietario(&p2); //reference ad oggetto



ARRAY OGGETTI

#include<cmath>
#include<iostream>
using namespace std;

class Punto2D {
    double x, y;
    public:
        Punto2D(double _x, double _y): x(_x), y(_y) {}
        double distanzaDalCentro() {return sqrt(x*x+y*y);}
        void stampa() {cout << "("<<x<<","<<y<<")"<<endl;}
};



Possiamo definire un punto 2D come segue:

Punto2D p(2,3);
p.stampa();


Possiamo anche definire un array di punti 2D come segue:

Punto2D punti[3] = {Punto2D(2,3),Punto2D(4,5),Punto2D(7,7)};
for (int i=0; i<3; i++)
    punti[i].stampa();

(2,3)
(4,5)
(7,7)

Alternativamente, posso scrivere:

Punto2D punti[3] = {{2,3},{4,5},{7,7}};
for (int i=0; i<3; i++)
    punti[i].stampa();

(2,3)
(4,5)
(7,7)


Notiamo che insieme alla dichiarazione dell’array di punti abbiamo effettuato
anche la costruzione degli oggetti mediante l’inizializzazione unificata.
Questo è necessario in quanto l’oggetto Punto2D non ha un costruttore di default con zero parametri.



Punto2D punti[3]; //nessuna inizializzazioni
Punto2D punti[3] = {{2,3},{4,5}}; //troppo pochi inizializzatori
Punto2D punti[3] = {{2,3}}; //troppo pochi inizializzatori


Se voglio poter definire l’array
senza una inizializzazione esplicita, devo definire un costruttore di default:


#include<cmath>
#include<iostream>
using namespace std;
class Punto2D {
    double x, y;
    public:
        Punto2D(): x(0), y(0) {}
        Punto2D(double _x, double _y): x(_x), y(_y) {}
        double distanzaDalCentro() {return sqrt(x*x+y*y);}
        void stampa() {cout << "("<<x<<","<<y<<")"<<endl;}
};


ARGOMENTI DALLA RIGA DI COMANDO

I programmi da riga di comando possono accettare in input uno o più argomenti.
Questi vengono specificati dall’utente quando viene richiamato il programma da console.
Esempio:

main.exe argomento_1 argomento_2 argomento_3 ...

Quando gli argomenti sono specificati dall’utente, questi vengono resi disponibili
come argomenti della funzione main. Vediamo un esempio:



#include<iostream>

using namespace std;

int main(int argc, char *argv[]) {
    //argc sarà uguale al numero di argomenti specificati
    //argv[] è un vettore di stringhe (intese come char*)
    //contenenti i valori dei parametri

    //questo ciclo scorre e stampa gli argomenti
    for(int i=0; i<argc; i++)
        cout << "Argomento #"<<i<<": "<<argv[i]<<endl;
}


//PUNTATORI E I SUOI LIMITI:
i puntatori sono utili per il passaggio di strutture di dati piu pesanti
es:
bool fun(Oggetto o){
    //operazioni su o
    return o.check()
}

poco efficiente mettendo caso che quello che e l oggetto é pesante 3gb



vediamo ora che con il puntatore viene  copiato solo l'indirizzo e non lo stato di o



ovviamente con i puntatori sono un po tediosi sopratutto per la propria sintassi




REFERENCE

In C++, una "reference" è un tipo di dato che permette di creare un alias, 
o un altro nome, per una variabile esistente. Le reference forniscono un 
modo per accedere a una variabile utilizzando un nome diverso, ma senza creare 
una copia separata dei dati.

una reference puo essere definita con la seguente sintassi
<tipo>& nome_referece
portiamo un esempio:


class Classe {
    int x;
    public:
        Classe() : x(0) {}
        Classe(int _x): x(_x) {}
        void setX(int _x) {x=_x;}
        int getX() {return x;}
};

Classe o;
Classe &ref_o = o; // é detto alias di o (copia in memoria di o)


inoltre agire su ref_o equivale a reagire su quello che e o
una reference deve essere contestualizzata al momento della creazione

-----NB:
diverso da puntatore che puo essere inizializzata un po quando vogliamo

classe &ref2; //NON SI PUO FARE  bisogna assegnare indirizzo di memoria...

non possiamo fare puntare una reference ad un nuovo oggetto dello stesso tipo mediante un
assegnamento del tipo

ref_o= altro_oggetto
copia lo stato di altro_oggetto dentro o che e puntato da ref_o



Classe o2(7); oggetto ha parametro 7
ref_o =o2; abbiamo creato la reference (dichiarata prima) che ha lo stesso valore di o
cout << o.getX()<<endl; //stampa o cioe 7
o2.setX(-1); sovrascriviamo -1 su o2
cout << ref_o.getX(); mandiamo in output la ref e vediamo che e 7 come risultato




Riferimenti in sola lettura:
i riferimenti di cui abbiamo parlato sono (left value) possono trovarsi
nel lato sinistro di un asegnamento
per definire un elemento solo in lettura utilizziamo la chiave const

int x = 8;
const int &r = x;
cout << r << endl; //stampa 8

se scriviamo r=2 questo accesso in scrittura non è ammesso darà errore

stessa cosa vale per gli oggetti in particolare i riferimenti costanti possono invocare solo metodi
che non  modifichino lo stato dell'oggetto
per far capire al compilatore che i metodi sono di sola lettura mettiamo la chiave const per farglielo capire

vediamo esempio


 class Classe {
    int x;
    public:
     Classe() : x(0) {}
     Classe(int _x): x(_x) {}
     void setX(int _x) {x=_x;}
     int getX() const {return x;}

     //inserisco "const" per indicare che il metodo non modifica lo stato dell'oggetto

};


In analogia con gli lvalue, gli oggetti/i valori di tipo rvalue sono invece non modificabili.
Ad esempio, i letterali sono di tipo rvalue.
Possiamo far puntare un riferimento a un rvalue (esempio un letterale) solo se costante:

const int &r = 8; //valore 8 ha stesso ciclo di vita del riferimento &

int &r = 8; // NON VALIDA!!!!!!!!! NON E CONST!!!!!!
in quanto un riferimento non é costante non puo puntare a rvalue
(non possiamo assegnare un valore constante ad una reference se non e dihiarata const
fosse stata int &r= i; allora poteva essere utilizzata si copia in r lo stato di i..)


reference come parametri formali si possono passare come parametri formali


void fun(Classe &o) {
    o.setX(0);
}

Classe o(10);
cout << o.getX() << endl;
fun(o);
cout << o.getX() << endl;


analogo al passaggio per puntatore
inoltre se vogliamo essere sicuri che il metodo non modifichi il valore allora meglio dichiarare const il riferimento!!!
 es


 void print(const Classe &o) {
    cout << o.getX() << endl;
}

Classe o(10);
print(o);




/*


#include <iostream>
using namespace std;


class Persona{

  private:
    string nome;
    string cognome;
  public:
    Persona(string n, string c) : nome(n), cognome(c) {}
     void setNome(string n) {nome=n;}
     void setCognome(string c) {cognome=c;}

     void saluta(){
        cout<<"Salgo in auto"<<endl;
     }

};

class Automobile{
 private:
  string modello;
  Persona &proprietario;
 public:
  Automobile(string m, Persona &proprietario): modello(m) , proprietario(proprietario) {}


};



int main(){
    Persona p1("alessandro" , "aiello");
    Persona p2("federico" ,"mastro");
    Automobile a1("Ferrari" , p1);
    Automobile a2("audi", p2);


é POSSSIBILE CAmbiare il proprietario di un automobile cambiando il riferimento
nell'oggetto Automobile
 a1.proprietario = p2;
a1 é ora posseduta da proprietario p2;



--STATIC;

La parola static può essere utilizzata per dichiarare delle variabili di classe.
Queste sono diverse dalle variabili (o attributi) viste finora, che sono invece di istanza.
 Le variabili di istanza sono allocate in una memoria “privata” della singola istanza della classe (il singolo oggetto).
 Pertanto ogni oggetto ha una sua copia delle variabili di istanza.
 
 Le variabili di classe sono invece condivise tra tutte le istanze di una data classe.
 Vediamo un esempio:



class Classe {
    static int contatore; //variabile di istanza, condivisa tra tutti gli oggetti
    int x; //variabile di istanza: ogni oggetto avrà la sua copia
    public:
        Classe() : x(0) {contatore++;}
        int getX() const {return x;}
        void setX(int _x) {x=_x;}
        int getCount() {return contatore;}
};

La variabile di classe non può essere inizializzata nella definizione.
 Non posso quindi scrivere:



class Classe {
    static int contatore=0; //errore
    int x;
    public:
        Classe() : x(0) {contatore++;}
        int getX() const {return x;}
        void setX(int _x) {x=_x;}
        int getCount() {return contatore;}
};





L’inizializzazione è comunque obbligatoria e
va fatta “fuori” dalla definizione della classe:



class Classe {
    static int contatore;
    int x;
    public:
        Classe() : x(0) {contatore++;}
        int getX() const {return x;}
        void setX(int _x) {x=_x;}
        int getCount() {return contatore;}
};
int Classe::contatore =0;  -->  //inizializzata fuori dalla classe
                                  ma definita static dentro





//COSA STAMPA QUESTO CODICE=????????


#include <iostream>
using namespace std;


class Classe {
    static int contatore;
    int x;
    public:
        Classe() : x(0) {contatore++;}
        int getX() const {return x;}
        void setX(int _x) {x=_x;}
        int getCount() {return contatore;}
};
int Classe::contatore =0;


int main(){


Classe c1;
Classe c2;
cout <<c1.getCount();



------STAMPA 2 ------


perche abbiamo il counter++ nel costruttore ogni volta che viene definito un oggetto
aumenta il count ne abbiamo definit due percio due volte si è incrementato




VARIABILE LOCALE STATIC

Una variabile static definita all’interno di una funzione o un metodo,
viene dichiarata e inizializzata solo la prima volta che il metodo viene invocato e
utilizzata nelle successive invocazioni.
Consideriamo ad esempio la seguente funzione:

int count() {
    static int c=0;
    return c++;
}

VERRA INIZIALIZZATA la prima volta che si richiama il metodo non appena si richiamera
il metodo count()  altre  volte verra AGGIORNATO C percio la variabile esistera ancora
e morira a termine del programma.

ex----------------------------------------------------------------------

#include<iostream>
using namespace std;


int main(){

for (int i=0;i<10;i++)
    cout << count() << " ";
}

stampa 0 1 2 3 4 5 6 7 8 9




METODI STATIC


I metodi static sono dei metodi il cui funzionamento non dipende dallo stato dell’istanza.
 Ad esempio, il metodo getCount definito prima non dipende dallo stato,
 ma solo da una variabile static, quindi può essere definito come static:




  class Classe {
    static int contatore=0;         //errore
    int x;
    public:
        Classe() : x(0) {contatore++;}
        int getX() const {return x;}
        void setX(int _x) {x=_x;}
        static int getCount() {return contatore;}
};
int Classe::contatore =0;




Il metodo static può essere richiamato regolarmente così:

Classe o;
o.getCount();




Dato che l’esecuzione di un metodo statico non dipende da una specifica istanza,
posso anche richiamare un metodo statico anche in maniera indipendente da una istanza:

Classe::getCount();



FRIEND

UNA FUNZIONE FRIEND NON risiede nello scoope della classe, ha accesso a tutta la parte
privata della classe
(ha accesso a tutti i membri della classe per cui è stata dichiarata friend)






Supponiamo di voler definire una funzione capace di normalizzare un vettore.
Per effettuare la normalizzazione, la funzione deve poter accedere allo stato del vettore.
 Una possibile funzione è la seguente:

void normalize(Point2D &p) {
    double mod = sqrt(p.x*p.x + p.y*p.y);
    p.x/=mod;
    p.y/=mod;
}





Tuttavia la funzione sopra non ha accesso alle proprietà degli oggetti di tipo Point2D.
Per far si che la funzione possa accedere ai membri privati degli oggetti di classe Point2D,
possiamo dichiararla come “funzione amica” mediante la parola friend in fase di definizione della classe:

class Point2D {
    private:
        double x, y;
    public:
        friend void normalize(Point2D &p);
        Point2D() : x(0), y(0) {}
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        double getX() const {return x;}
        double getY() const {return y;}
};



A questo punto possiamo definire la funzione fuori dalla classe:

#include<cmath>

void normalize(Point2D &p) {
    double mod = sqrt(p.x*p.x + p.y*p.y);
    p.x/=mod;
    p.y/=mod;
}

Vediamo un esempio di utilizzo della funzione:

Point2D p1(2.2,4.3);
cout << "("<< p1.getX() << ", " << p1.getY() << ")"<< endl;

normalize(p1);
cout << "("<< p1.getX() << ", " << p1.getY() << ")"<< endl;






NAMESPACE

namespace geometric {
    class Rectangle {
        double base;
        double height;
        public:
            Rectangle(double b, double h) :base(b), height(h) {}
            double area() {return base*height;}
    };

    class Square {
        double side;
        public:
            Square(double s) : side(s) {}
            double area() {return side*side;}
    };

    class Circle {
        double r;
        public:
            Circle(double _r): r(_r) {}
            double area() {return 3.14*r*r;}
    };
}

Una volta definite le classi nel namespace, posso accedervi in diversi modi.
Usando il selettore di scope:

#include<iostream>
using namespace std;

geometric::Square s(2);
cout << s.area();

4
---------------------------------
Importando il simbolo Square:

using geometric::Square;
Square s(2);
cout << s.area();

4

-------------------------


oppure includendo using namespace geometric:

using namespace geometric;
Square s(2);
cout << s.area();



--------------------



Overloading di funzioni e metodi

C++ permette di effettuare l’overloading di funzioni e metodi,
ovvero di definire diverse “versioni” di una funzione/metodo che hanno lo stesso nome e
lo stesso tipo di ritorno, ma prendono in input numeri diversi tipi di parametri con tipi diversi.
Lo scopo è quello di semplificare l’invocazione dei metodi.

Posso però definire una nuova funzione che permette di concatenare una stringa e un intero.
Potrei chiamare la funzione concat_string_int,
 ma C++ mi permette di dare lo stesso nome e
 di selezionare in automatico quale avviare sulla base dei tipi a runtime:

#include<sstream>

string concat(string s1, int x) {
    stringstream ss;
    ss << s1 << x;
    return ss.str();
}

Posso adesso usare la funzione per concatenare una stringa a un intero:

cout << concat("hello", "world") << endl;
cout << concat("hello", 2) << endl;
cout << concat(2, "world") << endl;



Potrei anche definire una funzione con un numero diverso di parametri:

string concat(string s1, string s2, string s3) {
    return s1 + s2 + s3;
}

L’uso resta sempre automatico:

cout << concat("hello","world","hello");





COPIA OGGETTI:

Quando un oggetto viene assegnato a un altro oggetto, C++ opera una copia “member-wise”
dello stato.
In pratica il valore di ciascun attributo viene copiato nel nuovo oggetto.
Vediamo un esempio:

#include<iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(int a, int b) : x(a), y(b) {}
        double getX() const {return x;}
        double getY() const {return y;}
};

Point2D p1(3,2);
Point2D p2(4,5);

cout << p1.getX() << ", "<<p1.getY() << endl;
cout << p2.getX() << ", "<<p2.getY() << endl;

p2=p1; //copia automatica membro a membro di C++
cout << p2.getX() << ", "<<p2.getY() << endl;

3, 2
4, 5
3, 2

Quando l’assegnamento viene fatto in fase di inializzazione,
C++ opera lo stesso tipo di copia di default:

Point2D p3 = p1;
Point2D p4(p1);

cout << p3.getX() << ", "<<p3.getY() << endl;
cout << p4.getX() << ", "<<p4.getY() << endl;

3, 2
3, 2

C++ permette però di specificare un costruttore di copia,
che permette di specificare esattamente cosa fare quando la copia è richiesta in fase di inizializzazione dell’oggetto.
 Ciò viene fatto specificando un nuovo costruttore che prende in input un riferimento a
 un oggetto dello stesso tipo:

class Point2D {
    double x, y;
    public:
        Point2D(Point2D &p) :x(p.x), y(p.y) { //costruttore di copia
            //codice custom
            cout << "costruttore di copia"<<endl;
        }
        Point2D(int a, int b) : x(a), y(b) {}
        double getX() const {return x;}
        double getY() const {return y;}
};

Vediamo alcuni esempi di utilizzo:

Point2D p1(2,3);
Point2D p2 = p1; //richiama il costruttore di copia
Point2D p3(p1); //richiama il costruttore di copia

//non richiama il costruttore di copia, ma fa una copia membro a membro
p3 = p2;

costruttore di copia
costruttore di copia





DISTRUTTORE DI OGGETTI:


Quando un oggetto viene distrutto, in automatico vengono deallocati tutti
gli attributi dichiarati staticamente. Se però abbiamo allocato della memoria dinamicamente
durante la costruzione o l’interazione con l’oggetto,
la memoria allocata va liberata manualmente specificando
uno speciale metodo chiamato distruttore che ha lo stesso nome della classe
preceduto dalla tilde ~.
Vediamo un esempio:


class Classe {
    int *x;
    int n;
    public:
        Classe(int _n) : n(_n) {
            x = new int[n];
            for(int i=0; i<n; i++)
                x[i] = i+1;
        }
        int getNum(int i) {return x[i];}
};


Nell’esempio sopra, il costruttore alloca dinamicamente della memoria per un array di n interi e fa sì che x punti a tale memoria.
Alla fine del ciclo vita dell’oggetto, perderemo il puntatore x, ma la memoria da esso puntato non sarà liberata.
Un codice di questo tipo genera dunque un memory leak:

Classe *o = new Classe(3);
delete o;


In C++, possiamo definire uno speciale metodo “distruttore”,
che verrà richiamato automaticamente quando l’oggetto viene distrutto.
Il distruttore va dichiarato come un costruttore senza parametri,
ma anteponendo al nome la tilde (~):



class Classe {
    int *x;
    int n;
    public:
        Classe(int _n) : n(_n) {
            x = new int[n];
            for(int i=0; i<n; i++)
                x[i] = i+1;
        }
        int getNum(int i) {return x[i];}
        ~Classe() {
            delete[] x;
            cout << "Eseguito il distruttore";
        }
};

Adesso, la delete richiamerà il distruttore, che libererà la memoria correttamente:



OVERLOADING CON FUNZIONI NON MEMBRO




Vediamo un esempio di overloading degli operatori con funzioni non membro della classe.
Supponiamo di avere una classe che implementa un punto nello spazio 2D:

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        Point2D(): x(0), y(0) {}
        double getX() {return x;}
        double getY() {return y;}
};

Se volessimo sommare
due punti potremmo fare così (in maniera un po’ rocambolesca):

Point2D p1(2,3);
Point2D p2(3,3);
Point2D p3(p1.getX()+p2.getX(), p1.getY()+p2.getY());
cout << "("<<p3.getX() << "," << p3.getY() << ")" << endl;

Un’ovvia alternativa consiste nel definire un metodo sum:

Point2D sum(Point2D p) {
 return Point2D(x+p.x, y+p.y);



Possiamo dunque effettuare la somma più semplicemente come segue:


Point2D p1(2,3);
Point2D p2(3,3);
Point2D p3 = p1.sum(p2);
cout << "("<<p3.getX() << "," << p3.getY() << ")" << endl;


Per semplificare ancora la sintassi,
posso fare overloading dell’operatore come segue:

#include<iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        Point2D(): x(0), y(0) {}
        double getX() {return x;}
        double getY() {return y;}
};

Point2D operator+(Point2D a, Point2D b){
    return Point2D(a.getX()+b.getX(), a.getY()+b.getY());
}

int main() {
    Point2D p1(2,3);
    Point2D p2(3,3);

    Point2D p3 = p1+p2;
    cout << "("<<p3.getX() << "," << p3.getY() << ")" << endl;
}





Se vogliamo ancora semplificare la sintassi,
possiamo dichiarare la funzione che fa overloading dell’operatore come “friend”.
In questo modo,
la funzione può accedere allo stato interno degli oggetti di tipo Point2D:



#include<iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        Point2D(): x(0), y(0) {}
        double getX() {return x;}
        double getY() {return y;}
        friend Point2D operator+(Point2D, Point2D);
};

Point2D operator+(Point2D a, Point2D b){
    return Point2D(a.x+b.x, a.y+b.y);
}

int main() {
    Point2D p1(2,3);
    Point2D p2(3,3);

    Point2D p3 = p1+p2;
    cout << "("<<p3.getX() << "," << p3.getY() << ")" << endl;
}

L’operatore può essere anche richiamato esplicitamente così:

Point2D p3 = operator+(p1,p2);


OVERLOADING CON FUNZIONI MEMBRO


In alternativa, è possibile effettuare l’overloading degli operatori mediante funzioni membro.
In questo caso, dovremo passare in input solo
l’operando di sinistra nel caso di operatori binari o
nessun operando nel caso di operatori unari.
Ad esempio:

#include<iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        Point2D(): x(0), y(0) {}
        Point2D(double _x) : x(_x), y(_x) {}
        double getX() {return x;}
        double getY() {return y;}

        Point2D operator+(Point2D a){
            return Point2D(a.x+x, a.y+y);
        }
        Point2D operator-() {
            return Point2D(-x,-y);
        }
};

int main() {
    Point2D p1(2,3);
    Point2D p2(1,2);
    Point2D p3 = -(p1 + p2);
    cout << "("<<p3.getX() << "," << p3.getY() << ")" << endl;
}

Possiamo richiamare gli operatori come segue

Point2D p3 = p1.operator+(p2);
Point2D p4 = p3.operator-();

Si noti che in questo caso, l’operazione che segue è permessa:

Point2D p3 = p1 +2; //promozione di 2 a Point2D permessa

Mentre la seguente non lo è:

Point2D p3 = 2 + p1; //promozione non permessa! l'operatore non è membro di "2"




Operatore <<




L’overloading dell’operatore << permette di “stampare” facilmente oggetti a schermo.
Ricordiamo che la stampa avviene così:

cout << obj << obj <<obj << ...

Dove obj rappresenta un oggetto (es. una stringa).
L’operatore << è dunque un operatore binario che ha due operandi:

Un ostream (ad esempio cout);
Un oggetto di un determinato tipo.
Per mantenere l’associatività, l’operatore restituisce un riferimento a ostream.
Infatti, la catena sopra può essere letta come:

(cout << obj) << obj ...

Dove (cout << obj) restituisce un riferimento a cout.
Se vogliamo abilitare l’operatore << nel nostro oggetto,
dobbiamo implementare l’operatore come funzione friend
(non possiamo implementarlo come membro perché il primo operando non è del tipo di obj). Vediamo un esempio:

#include<iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        double getX() {return x;}
        double getY() {return y;}
        friend ostream& operator<<(ostream &, Point2D);
};

ostream& operator<<(ostream &s, Point2D& p) {
    // inserisco una rapresentazione di p nel riferimento a ostream
    s << "(" << p.x << "," << p.y << ")";
    return s; //restituisco il riferimento
}

int main() {
    Point2D p(2,3);
    cout << p;
}




Ereditarietà

L’ereditarietà permette di definire una classe che acquisisce specifici elementi di un’altra classe.
Questa pratica mira a favorire il riutilizzo del codice. Vediamo un esempio:

class A{
  int x;
  //B b;
  public:
    A(){
      x = 10;
    }

    void f() { cout << "A.f(), x=" << x <<  endl;}
    int getX() { return x;}
};

questa classe ha un funzionamento molto semplice
nel main
A a;
a.f();


stampera A.f(), x= 10


definiamo la classe B
class B: public A{  // la classe B eredita i public di a
  float y;

  public:
    B() {y=18;}
    void g() { cout << "B.g(), y=" << y << endl;}
};

nel codice sopa A viene ereditata da B con il modificatore public
che indica che cio che é private, public o protected in A
manterra la stessa visibilta in B

B ha ereditato lo stato di A(x) e i metodi f e getX che possiamo richiamare con
gli oggetti della classe B
la classe B ha anche aggiunto un metodo void g() -------------------------------------->>>>>>>>>  ///vedi questa parte ti schiarisce i concetti inerenti allere
e lo potremmo usare con gli oggetti della classe B

Possiamo ridefinire i metodi di A mediante ovveriding

OVERRIDING:
- é LA RIDEFINIZIONE DI UN METODO PPRECEDENTEMENTE DEFINITO IN UNA CLASSE BASE,
IN UNA CLASSE DERIVATA (SI HA OVERRIDING SE I DUE METODI HANNO STESSO PROTOTIPO )

class B: public A{
  float y;

  public:
    // ridefinendo una funzione con lo stesso nome
    // facciamo overriding
    void f() { cout << "override di A.f(), x=" << getX() <<  endl;}
    void g() { cout << "B.g(), y=" << y << endl;}
};

NB: NON CONFODERE overriding con overloading, se facciamo overloading di un metodo effettuiamo anche
overriding

NB: OVERLOADING avviene la ridefinizione di un metodo presente in uno scope con un metodo con
NOME UGUALE MA SEGNATURA DIFFERENTE (numero parametri e/o tipo);


class B: public A{
  float y;

  public:
    // ridefinendo una funzione con lo stesso nome
    // facciamo overriding
    void f(int) { cout << "override di A.f(), x=" << getX() <<  endl;}
    void g() { cout << "B.g(), y=" << y << endl;}
};

Non posso più richiamare B.f(), in quanto l’override mediante B::f(int) non
permette più di accedere a A::f().
Posso forzare l’accesso a A::f() come segue:

b.A::f();
oppure
using A::f;

non è possibile ereditare costruttori e distruttori ma è possibile richiamare il costruttore della classe base



POLIMORFISMO:

IN C++ un puntatore on reference ad un oggetto di tipo A puo puntare
ad ogni tipo A e a qualsiasi sottotipo di A, ovvero tipi che ereditano da A
con modificatore PUBLIC

ESEMPIO
A *pa = new A(10);
B *pb = new B(20, 4.4);
pb->g();
pa = pb;
pa->f();

B.g(), y=4.4
A.f(), x=20



Da notare che, benché pa punti a un oggetto di tipo B, verra in automatico richiamata
l'implementazione di f presente in A, ma con lo stato di B
un raggionamento simile per le reference
queste caratteristiche ci permettono di implementare polimorfismo


class Animale {
    public:
        void parla() {}
};

class Cane: public Animale {
    public:
        void parla() {cout << "bau"<<endl;}
};

class Gatto: public Animale {
    public:
        void parla() {cout << "miao"<<endl;}
};

Animale *a;
string animale = "cane";

if(animale=="gatto")
    a = new Gatto();
else if(animale=="cane")
    a = new Cane();
else
    a = new Animale();

a->parla();

In questo caso, a->parla() invocherà sempre il metodo parla implementato in
Animale in quanto il tipo dell’oggetto è noto solo a run-time.
Possiamo chiedere a C++ di richiamare il metodo della classe nota a runtime,
indicando il metodo come virtual:

class Animale {
    public:
        virtual void parla() {}
};

class Cane: public Animale {
    public:
        void parla() {cout << "bau"<<endl;}
};

class Gatto: public Animale {
    public:
        void parla() {cout << "miao"<<endl;}
};

Animale *a;
string animale = "gatto";

if(animale=="gatto")
    a = new Gatto();
else if(animale=="cane")
    a = new Cane();
else
    a = new Animale();

a->parla();





FUNZIONI VIRTUALI PURI CLASSE ASTRATTE E INTERFACCE

 in certi casi, puo avere senso non implementare alcuni metodi nella classe di base
 in quanto il comportamento é definito bene solo della classe che ereditano.
 in questo casi, é possibili definire il metodo come "pure virtuali".



pure virtuali quando noi andiamo a porre un metodo virtual = 0 e lo definiamo in un altro
parte del programma.

class Animale {
    public:
        virtual void parla() = 0;
};

class Cane: public Animale {
    public:
        void parla() {cout << "bau"<<endl;}
};

class Gatto: public Animale {
    public:
        void parla() {cout << "miao"<<endl;}
};

Animale *a;
string animale = "gatto";

if(animale=="gatto")
    a = new Gatto();
else if(animale=="cane")
    a = new Cane();

a->parla();

In questo caso la classe animal é detta una classe astratta in quanto presenta
almeno un metodo virtuale puro.
Le classi astratte non possono essere istanziate,
pertanto la seguente riga di codice darebbe un errore:

Animali a;


Una  classe base astratta che contiene solo attributi costntu
e funzionu virtuali pure, si dice interfaccia
nell'esempio prima la classe animale é interfaccia




CLASSI POLIMORFE COSTRUTTORI E DISTRUTTORI VIRTUALI

Un costruttore non può essere dichiarato come virtuale.
Se vogliamo che la classe venga vista come polimorfa,
il distruttore va invece dichiarato come virtuale.
In questo modo, quando effettuiamo la delete di un puntatore di tipo A*
che punto a un oggetto di tipo B (con B che eredita da A con modificatore public),
verrà correttamente richiamato il distruttore di B.
Per far si che A sia polimorfa nell’esempio precedente,
dobbiamo dunque dichiarare il distruttore come virtuale:





RTTI RUN TIME TYPE IDENTIFICATION

Abbiamo visto che un puntatore di tipo A può puntare a un oggetto di tipo B
se B eredita da A con modificatore public.
Abbiamo però visto che se invochiamo un metodo contenuto anche in A
mediante il puntatore a B di tipo A*,
verrà richiamata la versione di A a meno che il metodo non sia dichiarato virtual:

A *p =  new B(10, 4.4);
p->f();

--> stampa A.f();

per richiamare il metodo f di B possiamo fare il cast dinamico

B *pp = dynamic_cast<B*>(p);
if(pp)
    pp->f();



--> stampa override di A.f();


il dynamic_cast é un cast sicuro che restituisce un nullptr se il cast non
é possibile.
Una alternativa NON SICURA del C é fare un cast standard o in alternativa il static_cast
questi cast non sono sicuri perche possono creare problematiche a run time
una soluzione al dinamyc_cast é l'operatore typeid che controlla i tipi a runtime             
con un cast statico

if(typeid(*p)==typeid(B))
    static_cast<B*>(p)->f();




IN C++ UNA CLASSE PUO EREDITARE DA PIU CLASSE IN CONTEMPORANE EX

class Gatto : public Animale, public Parlante, public Quadrupete {

 private:
 ///


 public:
 ///




};

pero questo scenario puo generare ambiguita nella risoluzione dei nomi
risoluzione dichiarare lo specificatore virtual nella derivazione diretta della classe base
class B {....../......}

class D1: virtual public B
in questo modo l'attributo x sara ereditato solo una volta dalla classe X



TEMPLATE

IN C++ é possibile definire funzioni e classi template che operano su tipi generici
consentono al programmatore di trattare i tipi dei dati come parametri,
esistono per consentire di riutilizzare un codice rispetto a tipi differenti
consideriamo questa funzione

void print(int x[], int n) {
    for (int i=0; i<n; i++) {
        cout << x[i];
        if(i!=n-1)
            cout << " - ";
    }
    cout << endl;
}

int a[] = {1,2,3};
print(a, 3);

stampa --> 1-2-3

tuttavia non potrei usare la stessa funzione per stampare un array di double


un modo per aggirare il problema consiste nel fare overloading della funzione
specificandone una versione che opera sui double


void print(double x[], int n) {
    for (int i=0; i<n; i++) {
        cout << x[i];
        if(i!=n-1)
            cout << " - ";
    }
    cout << endl;
}

FUNZIONI TEMPLATE

una funzione template é un modello dal quale il compilatore genera
opportune specializzazioni in corrispondenza di chiamate a funzione con parametri differenti.

per dichiarare una funzione template, bisogna anteporre la notazione
template <class C1, class C2, ...>
oppure
template <typename T1, typename T2,....>

Nel prototipo e nel corpo della funzione sara dunque possibile riferirsi a Cx e Tx per ottenere
il tipo passsato a runtime.
Vediamo un esempio con la funzione print:

template<typename T>
void print(T x[], int n) {
    for (int i=0; i<n; i++) {
        cout << x[i];
        if(i!=n-1)
            cout << " - ";
    }
    cout << endl;
}

quando richiamo la funzione template, dobbiamo specificare il tipo esatto tra parenti angolari "<>"

argument deduction=tipo del parametro attuale a tipo generico, avviene a tempo di compilazione
in corrispondenza delle invocazioni della funzione template
NB: (Ogni tipo generico deve essere presente nella lista dei perametri formali della funzione senno ERRORE CUMPILE_TIME)


 #include <string>



int a[] = {1,2,3};
double b[] = {2.2, 3.3, 4.4};
string s[] = {"hello", "world"};

print<int>(a, 3);
print<double>(b, 3);
print<string>(s, 2);




1 - 2 - 3
2.2 - 3.3 - 4.4
hello - world


una funzione puo anche avere due tipi di template

template<typename T1, typename T2>
T1* sum(T1 a[], T2 b[], int n) {    //prende in input due array di tipo t1 e t2 e un intero n
    T1 *out = new T1(n);            //l'array in output è di tipo t1
    for(int i=0; i<n; i++) {
        out[i] = a[i] + b[i];
    }
    return out;
}

portiamo un esempio di funzione template:
template<class T>
void print(T a , T b){

    ....istrezioni....ecc...
}

essendo una funzione con tipologia di parametri da definire a e b devono avere lo stesso tipo;



OVERLOADING DI FUNZIONI TEMPLATE

e' possibile effettuare un overloading delle funzioni template

template<typename T>
T* sum(T a[], T b[], int n) { //prende in input due array di tipo t1 e t2 e un intero n
    T *out = new T(n); //l'array in output è di tipo t1
    for(int i=0; i<n; i++) {
        out[i] = a[i] + b[i];
    }
    return out;
}

questo overloading ci permettera di eseguire istruzioni del tipo

int x[] = {1,2,3};
int y[] =  {4,5,6};
int *out = sum<int>(x, y, 3);
print<int>(out, 3);

5-6-9

il sovraccaricamento puo avvenire anche con funzioni non generiche (senza template)

int* sum(int a[], int b[], int n) { //prende in input due array di tipo t1 e t2 e un intero n
    int *out = new int(n); //l'array in output è di tipo t1
    for(int i=0; i<n; i++) {
        out[i] = a[i] + b[i];
    }
    return out;
}

per cui possiamo scrivere:

int *out = sum(x, y, 3);
print<int>(out, 3);


5-7-9

per definire un overloading di una classe template dobbiamo definire una classe con due tipi di parametri template esempio

template <class C, class T>
void print(T a, C b);
sono due tipi di template differenti
percio se il tipo dei due parametri di una seguente funzione é diverso verra richianata questa funzione

se invece era:
template <class T> void print (T a, T b) sono lo stesso template percio sarann due tipi identici ex (int , int).





CLASSI TEMPLATE


i template permettono di definire anche classi generiche
in questo caso la specifica typename rende disponibile
un tipo generico all'interno dell'intera classe: (cioé T).
----
template<typename T>
class Point2D {
    T x, y;
    public:
        Point2D(T _x, T _y) : x(_x), y(_y) {}
        T getX() {return x;}
        T getY() {return y;}
        void print() {cout << "("<<x<<","<<y<<")"<<endl;}
};



PER ISTANZIARE GLI OGGETTI DELLA CLASSE:

una volta definita la classe generica possiamo istanziare un oggetto della classe
specificando i tipi:

Point2D<int> p_int(2,3);
p_int.print();

Possiamo anche definire un Point2D basato su double come segue:

Point2D<double> p_double(2.1,3.2);
p_double.print();


(2.1,3.2);


Vediamo un esempio in cui scorporiamo la dichiarazione della
classe dall’implementazione dei metodi:

template<typename T>
class Point2D {
    T x, y;
    public:
        Point2D(T _x, T _y);
        T getX();
        T getY();
        void print();
};

In questo caso, i metodi vanno implementati come se fossero delle funzioni template.
Inoltre l’oggetto va richiamato specificando i tipi definiti dal template:

template<typename T>
Point2D<T>::Point2D(T _x, T _y) : x(_x), y(_y) {}

template<typename T>
T Point2D<T>::getY() {return y;}

template<typename T>
void Point2D<T>::print() {cout << "("<<x<<","<<y<<")"<<endl;}

Una classe generica può anche contenere funzioni membro generiche:

template<typename T>
class Point2D {
    T x, y;
    public:
        Point2D(T _x, T _y);
        T getX();
        T getY();
        template<typename T2>
        void sum(T2 num);
        void print();
};


template<typename T>
Point2D<T>::Point2D(T _x, T _y) : x(_x), y(_y) {}

template<typename T>
T Point2D<T>::getX() {return x;}


template<typename T>
template<typename T2>
void Point2D<T>::sum(T2 num) {x+=num; y+=num;}

template<typename T>
void Point2D<T>::print() {cout << "("<<x<<","<<y<<")"<<endl;}



IN questo esempio abbiamo visto come nella classe template possiamo definire anche tipi di dato non primitivi
gli argomenti corrispondenti nelle dichiarazioni di oggetti devono essere costanti.


ex:

template<class T, int DIM=10>
Stack{
    T ptr[DIM];
    //...
}


int main(){

    Stack<int, 50> Interi;
    Stack<double>; uguale a dire Stack< double, dim 10>;




}



*/

/*
OVERLOADING CHE PUO CHIEDERE ALL'ORALE

RICORDIAMO: (vedi Overloading nei nostri appunti);(funzione memebro non membro ecc.)


OVERLOADING ASSEGNAMENTO "=" ;
class X{

    class X(int, float);
    X(const X &);
    X &operator=(const X&)const;
}

X x1{ 1, 4.5};
X x2 {x1};  // costruttore copia
X x3= x1;  //costruttore copia
x3=x2; //x3.operator=(x2)




--------------------------------------------------------

OVERLOADING "[]"
int& operator[] (int i){
    return arr[i%len];
}

(*vett[5])[3] =7;
cour<<"vett[5]="<<(*vett[5]) [3]<<endl;


-----------------------------------------------------

OVERLOADING OPERATORE N-ARIO "()"

int operator() (int i1, int i2){
    int sum=0;
    for(int i=0; i<len;i++){
        if(a>=i1 && a<=i2)
            sum += vec[i];

    }
    return sum;
}

-------------------------------------------------------

OPERATORE --, ++  :

B operator++(int){  //postfisso
 B aux = *this;
 p++;
 return aux;
}

B& operator++ (){ //prefisso
p++;
return *this;
}


B operator--(int){ //postfisso
    B aux = *this;
    p--;
    return aux;
}


B& opertor--(){ //prefisso
    p--;
    return *this;
}

*/