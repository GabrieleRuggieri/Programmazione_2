/*



Operatore +:

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





Costruttore di copia:

    Venditore(const Venditore &v) : codice(v.codice), prodotti(v.prodotti), num_prodotti(v.num_prodotti) {}






Operatore =

    Venditore &operator=(const Venditore &v)
    {
        if (this != &v)
        {
            codice = v.codice;
            num_prodotti = v.num_prodotti;
            
            prodotti = new Prodotto[num_prodotti];
            
            for (int i = 0; i < num_prodotti; i++)
            {
                prodotti[i] = v.prodotti[i];
            }
        }
        return *this;
    }

*/