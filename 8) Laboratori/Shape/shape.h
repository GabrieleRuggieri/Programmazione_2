#ifndef SHAPE_H
#define SHAPE_H

#include<cmath>
#include<typeinfo>

class Shape{

public:

	Shape(){}

	virtual double getArea() const = 0;

	virtual ostream& print (ostream& os)const{return os << "\tShape: " << typeid(*this).name();}

	bool operator <= (const Shape& other){return getArea() <= other.getArea();}

	bool operator == (const Shape& other){return getArea() == other.getArea();}

	bool operator > (const Shape& other){return getArea() > other.getArea();}
};

ostream& operator<< (ostream& os, const Shape& ref){return ref.print(os);}

class Rectangle : public Shape{

	double base;
	double altezza;

public:

	Rectangle(double b, double h):Shape{}, base(b), altezza(h){}

	double getArea()const{return base*altezza;}

	ostream& print (ostream& os)const{
		Shape::print(os);
		return os << "Base= " << base << ", altezza= " << altezza << "\tArea= " << getArea();
	}
};

class Circle : public Shape{

	double raggio;

public:

	Circle(double r):Shape{}, raggio(r){}

	double getArea()const{return M_PI * pow(raggio,2);}

	ostream& print (ostream& os)const{
		Shape::print(os);
		return os << "Raggio= " << raggio << "\tArea= " << getArea();
	}
};

class Triangle : public Shape{

	double base;
	double altezza;

public:

	Triangle(double b, double h):Shape{}, base(b), altezza(h){}

	double getArea()const{return (base*altezza)/2;}

	ostream& print (ostream& os)const{
		Shape::print(os);
		return os << "Base= " << base << ", altezza= " << altezza << "\tArea= " << getArea();

	}
};

#endif