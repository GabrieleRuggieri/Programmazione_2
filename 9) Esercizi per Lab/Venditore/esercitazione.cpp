#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Prodotto
{

private:
    int codice;
    double prezzo;

public:
    Prodotto() : codice(0), prezzo(0.0) {}

    Prodotto(int _codice, double _prezzo) : codice(_codice), prezzo(_prezzo) {}

    int getCodice() const { return codice; }

    void setCodice(int codice) { this->codice = codice; }

    double getPrezzo() const { return prezzo; }

    void setPrezzo(double prezzo) { this->prezzo = prezzo; }

    friend ostream &operator<<(ostream &out, const Prodotto &prodotto)
    {
        out << "Codice: " << prodotto.codice << ", Prezzo: " << prodotto.prezzo;
        return out;
    }

    friend bool operator>(const Prodotto &p1, const Prodotto &p2) // necessario per insertion sort
    {
        return p1.getPrezzo() > p2.getPrezzo();
    }

    friend bool operator<(const Prodotto &p1, const Prodotto &p2) // necessario per insertion sort
    {
        return p1.getPrezzo() < p2.getPrezzo();
    }
};

class ProdottoAlimentare : public Prodotto
{
private:
    string scadenza;

public:
    ProdottoAlimentare() : Prodotto(), scadenza("") {}

    ProdottoAlimentare(int _codice, double _prezzo, const string &_scadenza) : Prodotto(_codice, _prezzo), scadenza(_scadenza) {}

    const string &getScadenza() const { return scadenza; }

    void setScadenza(const string &scadenza) { this->scadenza = scadenza; }

    bool verifica() const
    {
        // Supponiamo che la data di oggi sia il 7 giugno 2023
        const string oggi = "07/06/2023";

        if (scadenza > oggi)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    friend ostream &operator<<(ostream &out, const ProdottoAlimentare &prodotto)
    {
        out << static_cast<const Prodotto &>(prodotto);
        out << ", Scadenza: " << prodotto.scadenza;
        return out;
    }
};

class ProdottoPerBambini : public Prodotto
{
public:
    enum FasciaEta
    {
        FASCIA_0_3,
        FASCIA_3_6,
        FASCIA_6_9,
        FASCIA_9_12
    };

private:
    FasciaEta fascia_eta;

public:
    ProdottoPerBambini() : Prodotto(), fascia_eta(FASCIA_0_3) {}

    ProdottoPerBambini(int _codice, double _prezzo, FasciaEta _fascia_eta)
        : Prodotto(_codice, _prezzo), fascia_eta(_fascia_eta) {}

    FasciaEta getFasciaEta() const { return fascia_eta; }

    void setFasciaEta(FasciaEta fascia_eta) { this->fascia_eta = fascia_eta; }

    friend ostream &operator<<(ostream &out, const ProdottoPerBambini &prodotto)
    {
        out << static_cast<const Prodotto &>(prodotto);
        out << ", Fascia Eta: " << prodotto.fascia_eta;
        return out;
    }
};

class Venditore
{
private:
    int codice;
    Prodotto *prodotti;
    int num_prodotti;

public:
    Venditore() : codice(0), prodotti(nullptr), num_prodotti(0) {}

    Venditore(int _codice) : codice(_codice), prodotti(nullptr), num_prodotti(0) {}

    Venditore(const Venditore &v) : codice(v.codice), prodotti(v.prodotti), num_prodotti(v.num_prodotti) {}

    Venditore &operator=(const Venditore &v)
    {
        if (this != &v)
        {
            codice = v.codice;
            num_prodotti = v.num_prodotti;
            delete[] prodotti;
            prodotti = new Prodotto[num_prodotti];
            for (int i = 0; i < num_prodotti; i++)
            {
                prodotti[i] = v.prodotti[i];
            }
        }
        return *this;
    }

    int getCodice() const { return codice; }

    void setCodice(int codice) { this->codice = codice; }

    Prodotto *getProdotti() const { return prodotti; }

    int getNumProdotti() const { return num_prodotti; }

    void aggiungiProdotto(const Prodotto &prodotto)
    {
        if (prodotti == nullptr)
        {
            prodotti = new Prodotto[1];
        }
        else
        {
            Prodotto *new_prodotti = new Prodotto[num_prodotti + 1];
            for (int i = 0; i < num_prodotti; i++)
            {
                new_prodotti[i] = prodotti[i];
            }
            delete[] prodotti;
            prodotti = new_prodotti;
        }
        prodotti[num_prodotti] = prodotto;
        num_prodotti++;
    }

    friend ostream &operator<<(ostream &out, const Venditore &venditore)
    {
        out << "Codice Venditore: " << venditore.codice << endl;
        out << "Prodotti: " << endl;
        for (int i = 0; i < venditore.num_prodotti; i++)
        {
            out << venditore.prodotti[i] << endl;
        }
        return out;
    }

    double calcolaPrezzoTotale()
    {
        double totale = 0.0;

        for (int i = 0; i < num_prodotti; i++)
        {
            totale += prodotti[i].getPrezzo();
        }

        return totale;
    }
    double calcolaValoreMagazzino()
    {
        double valoreMagazzino = 0.0;

        for (int i = 0; i < num_prodotti; i++)
        {
            if (typeid(prodotti[i]) == typeid(ProdottoAlimentare))
            {
                ProdottoAlimentare *prodottoAlimentare = static_cast<ProdottoAlimentare *>(&prodotti[i]);
                if (prodottoAlimentare->verifica())
                {
                    valoreMagazzino += prodotti[i].getPrezzo();
                }
            }

            else
            {
                valoreMagazzino += prodotti[i].getPrezzo();
            }
        }

        return valoreMagazzino;
    }
};

template <typename T>
void insertion_sort(T arr[], int n, bool ascending = true)
{
    for (int i = 1; i < n; i++)
    {
        T key = arr[i];
        int j = i - 1;
        if (ascending)
        {
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        else
        {
            while (j >= 0 && arr[j] < key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        arr[j + 1] = key;
    }
}

int main()
{
    // Creazione dei venditori
    Venditore v1(1);
    Venditore v2(2);
    Venditore v3(3);

    // Aggiunta di 5 prodotti a ciascun venditore
    v1.aggiungiProdotto(ProdottoAlimentare(1, 2.99, "1/06/2023"));
    v1.aggiungiProdotto(ProdottoAlimentare(2, 1.99, "15/06/2023"));
    v1.aggiungiProdotto(ProdottoPerBambini(3, 15.99, ProdottoPerBambini::FASCIA_3_6));
    v1.aggiungiProdotto(ProdottoPerBambini(4, 12.99, ProdottoPerBambini::FASCIA_6_9));
    v1.aggiungiProdotto(Prodotto(5, 9.99));

    v2.aggiungiProdotto(Prodotto(6, 7.99));
    v2.aggiungiProdotto(Prodotto(7, 11.99));
    v2.aggiungiProdotto(ProdottoPerBambini(8, 8.99, ProdottoPerBambini::FASCIA_0_3));
    v2.aggiungiProdotto(ProdottoAlimentare(9, 3.99, "22/06/2023"));
    v2.aggiungiProdotto(ProdottoPerBambini(10, 19.99, ProdottoPerBambini::FASCIA_9_12));

    v3.aggiungiProdotto(ProdottoPerBambini(11, 14.99, ProdottoPerBambini::FASCIA_6_9));
    v3.aggiungiProdotto(Prodotto(12, 5.99));
    v3.aggiungiProdotto(ProdottoAlimentare(13, 2.49, "10/06/2023"));
    v3.aggiungiProdotto(ProdottoPerBambini(14, 18.99, ProdottoPerBambini::FASCIA_3_6));
    v3.aggiungiProdotto(Prodotto(15, 8.99));

    // Array of all sellers
    Venditore venditori[] = {v1, v2, v3};

    // Sort the products of each seller in ascending order by price
    for (int i = 0; i < sizeof(venditori) / sizeof(Venditore); i++)
    {
        // Get the products of the current seller
        Prodotto *prodotti = venditori[i].getProdotti();
        int num_prodotti = venditori[i].getNumProdotti();

        // Sort the products in ascending order by price
        insertion_sort(prodotti, num_prodotti);
    }

    // Print the sellers and their products in ascending order by price
    for (const auto &venditore : venditori)
    {
        cout << venditore << endl;
    }

    cout << "Total price of all products: " << v1.calcolaPrezzoTotale() << endl;
    cout << "Total value of the inventory (excluding expired products): " << v1.calcolaValoreMagazzino() << endl;

    return 0;
}