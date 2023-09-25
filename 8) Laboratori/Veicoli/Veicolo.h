#ifndef VEICOLO_H
#define VEICOLO_H

#include<typeinfo>

class Veicolo{
	protected:
		int cilindrata;
		string type;
		
	public:
		Veicolo(int cilindrata, string type):cilindrata(cilindrata),type(type){}
		Veicolo(){}
        friend ostream& operator<<(ostream& os, const Veicolo& obj){
            os << "Tipo:" << obj.type << ", cilindrata= " << obj.cilindrata << endl;
            return os;
        }
		int getCilindrata(){return this->cilindrata;}
};

class Auto : public Veicolo{
	public:
		Auto(int cilindrata, string type) : Veicolo(cilindrata, type){}
};

class Moto : public Veicolo{
	public:
		Moto(int cilindrata, string type) : Veicolo(cilindrata, type){}
};

class Barca : public Veicolo{
	public:
		Barca(int cilindrata, string type) : Veicolo(cilindrata, type){}	
};

#endif