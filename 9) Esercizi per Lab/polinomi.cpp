#include <iostream>
#include <cmath>

using namespace std;

class Polinomio
{

private:
    int gradoMax;
    double *coeff;

public:
    // Costruttore per inizializzare un polinomio con un grado massimo dato
    Polinomio(int maxGrado) : gradoMax(maxGrado)
    {
        coeff = new double[maxGrado + 1];

        for (int i = 0; i <= maxGrado; i++)
        {
            coeff[i] = 0.0;
        }
    }

    // Metodo per impostare il coefficiente di un termine
    void ImpostaCoefficiente(int grado, double coefficiente)
    {
        if (grado >= 0 && grado <= gradoMax)
        {
            coeff[grado] = coefficiente;
        }
    }

    // Metodo per calcolare il grado del polinomio
    int Grado() const
    {
        for (int i = gradoMax; i >= 0; i--)
        {
            if (coeff[i] != 0.0)
            {
                return i;
            }
        }
        
        return 0;
    }

    // Overloading dell'operatore + per la somma di due polinomi
    Polinomio operator+(const Polinomio &other) 
    {
        int maxGrado = max(Grado(), other.Grado());
        Polinomio risultato(maxGrado);

        for (int i = 0; i <= maxGrado; i++)
        {
            risultato.ImpostaCoefficiente(i, coeff[i] + other.coeff[i]);
        }

        return risultato;
    }

    // Overloading dell'operatore - per la differenza tra due polinomi
    Polinomio operator-(const Polinomio &other) 
    {
        int maxGrado = max(Grado(), other.Grado());
        Polinomio risultato(maxGrado);

        for (int i = 0; i <= maxGrado; i++)
        {
            risultato.ImpostaCoefficiente(i, coeff[i] - other.coeff[i]);
        }

        return risultato;
    }

    // Overloading dell'operatore << per stampare il polinomio
    friend ostream &operator<<(ostream &os, const Polinomio &p)
    {
        int grado = p.Grado();
        bool primaParte = true;

        for (int i = grado; i >= 0; i--)
        {
            if (p.coeff[i] != 0.0)
            {
                if (!primaParte)
                    os << " + ";

                os << p.coeff[i] << "x^" << i;
                primaParte = false;
            }
        }

        return os;
    }
};

int main()
{
    Polinomio polinomio1(2);
    polinomio1.ImpostaCoefficiente(2, 5.0);
    polinomio1.ImpostaCoefficiente(1, 2.0);
    polinomio1.ImpostaCoefficiente(0, -3.0);

    Polinomio polinomio2(2);
    polinomio2.ImpostaCoefficiente(2, 2.0);
    polinomio2.ImpostaCoefficiente(1, -1.0);
    polinomio2.ImpostaCoefficiente(0, 1.0);

    Polinomio somma = polinomio1 + polinomio2;
    Polinomio differenza = polinomio1 - polinomio2;

    cout << "Polinomio 1: " << polinomio1 << endl;
    cout << "Polinomio 2: " << polinomio2 << endl;
    cout << "Somma: " << somma << endl;
    cout << "Differenza: " << differenza << endl;

    return 0;
}
