/* Cerințe comune tuturor temelor:
1. utilizarea sabloanelor
2. utilizarea STL
3. utilizarea variabilelor, funcțiilor statice, constantelor și a unei functii const
4. utilizarea conceptelor de RTTI raportat la template-uri
5. tratarea excepțiilor
6. citirea informațiilor complete a n obiecte, memorarea și afișarea acestora
*/
/*Tema 6. Se dorește implementarea unei aplicații OOP care sa permita gestionarea activității
unor farmacii apartinand proprietarului X. Pentru fiecare farmacie se cunoaște cel puțin
denumirea, numărul de angajați și profiturile pe fiecare luna. Farmaciile pot fi și online. În
acest caz se cunoaște doar adresa web, numărul de vizitatori și discountul utilizat.
Structura de date: vector sau list <tuple<web, nr_vizitatori, discount>> se rețin farmaciile
online
Cerința suplimentară:
- Să se adauge toate campurile relevante pentru modelarea acestei probleme.
- Să se construiască clasa template GestionareFarmacie care sa conțină informații despre
diversele tipuri de farmacii. Clasa conține indexul farmaciei (incrementat automat la
adaugarea unei noi file), id-ul lanțului (constant) și o structura de obiecte, alocată dinamic.
Sa se supraincarce operatorul += pentru inserarea unei noi farmacii online în structura.
- Să se construiască o specializare pentru tipul Farmacie_online care sa conțină și să afișeze
doar numărul total de vizitatori ai farmaciilor online.*/
#include <iostream>
#include <tuple>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Farmacie {
public:
    string getProprietar() const {
        return proprietar;
    }

    void setProprietar(string Proprietar) {
        Farmacie::proprietar = Proprietar;
    }

    string getDenumire() const {
        return denumire;
    }

    void setDenumire(string Denumire) {
        Farmacie::denumire = Denumire;
    }

    int getNumarAngajati() const {
        return numar_angajati;
    }

    void setNumarAngajati(int numarAngajati) {
        numar_angajati = numarAngajati;
    }

    double getProfit() const {
        return profit;
    }

    void setProfit(double Profit) {
        Farmacie::profit = Profit;
    }

private:
    string proprietar;
    string denumire;
    static int index;
public:
    int getIndex() const {
        return index;
    }

    static void setIndex(int Index) {
        Farmacie::index = Index;
    }

private:
    int numar_angajati;
    double profit;

public:
    Farmacie() {}

    Farmacie(string proprietar, string denumire, int numarAngajati, double profit) : proprietar(proprietar),
                                                                                     denumire(denumire),
                                                                                     numar_angajati(numarAngajati),
                                                                                     profit(profit) {}

};

class FarmacieOnline : public Farmacie {
public:
    const string &getAdresaWeb() const {
        return adresa_web;
    }

    void setAdresaWeb(const string &adresaWeb) {
        adresa_web = adresaWeb;
    }

    int getNrVizitatori() const {
        return nr_vizitatori;
    }

    void setNrVizitatori(int nrVizitatori) {
        nr_vizitatori = nrVizitatori;
    }

    int getDiscount() const {
        return discount;
    }

    void setDiscount(int Discount) {
        FarmacieOnline::discount = Discount;
    }

private:
public:
    bool operator==(const FarmacieOnline &rhs) const {
      /*  return static_cast<const Farmacie &>(*this) == static_cast<const Farmacie &>(rhs) &&
               adresa_web == rhs.adresa_web &&
               nr_vizitatori == rhs.nr_vizitatori &&
               discount == rhs.discount;*/
    }

    bool operator!=(const FarmacieOnline &rhs) const {
        return !(rhs == *this);
    }
    FarmacieOnline& operator+=(const FarmacieOnline& rhs){}

private:
    string adresa_web;
    int nr_vizitatori;
    int discount;
public:
    friend ostream &operator<<(ostream &os, const FarmacieOnline &online) {
        os << " adresa_web: " << online.adresa_web << " nr_vizitatori: "
           << online.nr_vizitatori << " discount: " << online.discount;
        return os;
    }

public:
    FarmacieOnline() {
        adresa_web = "blank";
        nr_vizitatori = 0;
        discount = 0;
    }

    FarmacieOnline(const string &adresaWeb, int nrVizitatori, int discount) : adresa_web(adresaWeb),
                                                                              nr_vizitatori(nrVizitatori),
                                                                              discount(discount) {}

    virtual ~FarmacieOnline() {

    }

};

using namespace std;

template<class T>
class GestionareFarmacie {
    T obj;
    int a, b;
    string web;
    string s1, s2;
    int c1;
    double c2;
public:
    GestionareFarmacie() {};

    GestionareFarmacie(string unu, int doi, int trei) {
        web = unu;
        a = doi;
        b = trei;
    }

    GestionareFarmacie(string proprietar, string denumire, int angajati, double profit) {
        s1 = proprietar;
        s2 = denumire;
        c1 = angajati;
        c2 = profit;
    }

    T Meniu();

    T MeniuClasic();

};

template<class T>
T GestionareFarmacie<T>::Meniu() {
    int operatie = -1;
    while (operatie != 0) {
        cout
                << "\nCe operatie se doreste ? 1.Schimbare adresa web \n 2.Schimbare numar vizualizari \n 3.Schimbare Discount \n 4.Vizualizare date actuale \n 0.Iesire";
        try{
            cin >> operatie;
            if(operatie<0 || operatie>5)
                throw(operatie);
            }
        catch(int operatie)
        {
            cout<<"Operatie Nevalida";
        }
        switch (operatie) {
            case 1: {
                string noua_adresa;
                cout << "Noua adresa web:";
                cin >> noua_adresa;
                web = noua_adresa;
                break;
            }
            case 2: {
                int nou_viz;
                cout << "Nr Viz nou:";
                try{
                    cin >> nou_viz;
                    if(nou_viz<0)
                        throw(nou_viz);
                    }
                catch(int nou_viz)
                {
                    cout<<"Operatie Nevalida";
                }
                a = nou_viz;
                break;
            }
            case 3: {
                int nou_discount;
                cout << "Discount nou:";
                try{
                    cin >> nou_discount;
                    if(nou_discount<0)
                        throw(nou_discount);
                    }
                catch(int nou_discount)
                {
                    cout<<"Operatie Nevalida";
                }
                b = nou_discount;
                break;
            }
            case 4: {
                cout << "\nAdresa Web:" << web;
                cout << "\nNr Vizualizatori:" << a;
                cout << "\nDiscount actual:" << b;
                break;
            }
            case 0:{
                cout<<"iesire";break;
            }
        }
    }
}

template<class T>
T GestionareFarmacie<T>::MeniuClasic() {
    int operatie = -1;
    while (operatie != 0) {
        cout
                << "\nCe operatie se doreste ? 1.Schimbare Proprietar \n 2.Schimbare Denumire \n 3.Schimbare Numar Angajati \n 4.Actualizare profit \n 5.Vizualizare date curente \n 0.Iesire";
        cin >> operatie;
        switch (operatie) {
            case 1: {
                string nou_proprietar;
                cout << "\nNumele noului proprietar";
                cin >> nou_proprietar;
                s1 = nou_proprietar;
                break;
            }
            case 2: {
                string noua_denumire;
                cout << "\nDenumire noua:";
                cin >> noua_denumire;
                s2 = noua_denumire;
                break;
            }
            case 3: {
                int nou_nrang;
                cout << "\nNumar nou angajati:";
                cin >> nou_nrang;
                c1 = nou_nrang;
                break;
            }
            case 4: {
                double profit_nou;
                cout << "\nProfit nou:";
                cin >> profit_nou;
                c2 = profit_nou;
                break;
            }
            case 5: {
                cout << "\nProprietar:" << s1;
                cout << "\nDenumire:" << s2;
                cout << "\nNr Angajati:" << c1;
                cout << "\nProfit anual:" << c2;
                break;
            }
            case 0:{
                cout<<"\nIesire inc";break;
            }
        }
    }
}

template<class T>
class GestionareFarmacii {
    T obj[10];
    string proprietar[10];
    string denumire[10];
    int nr_angajati[10];
    double profit[10];
    string web[10];
    int vizualizari[10];
    int discount[10];
public:
    GestionareFarmacii() {};

    GestionareFarmacii(int i, string Proprietar, string Denumire, int Nr_angajati, double Profit) {
        proprietar[i] = Proprietar;
        denumire[i] = Denumire;
        nr_angajati[i] = Nr_angajati;
        profit[i] = Profit;
    }

    GestionareFarmacii(int i, string Web, int Vizualizari, int Discount) {
        web[i] = Web;
        vizualizari[i] = Vizualizari;
        discount[i] = Discount;
    }

    T MeniuClasic(int i);
    T Meniu(int i);
    T Show(int i);
};
template<class T>
T GestionareFarmacii<T>::Show(int i){
    cout << "\nProprietar:" << proprietar[i];
    cout << "\nDenumire:" << denumire[i];
    cout << "\nNr Angajati:" << nr_angajati[i];
    cout << "\nProfit anual:" << profit[i];
}
template<>
FarmacieOnline GestionareFarmacii<FarmacieOnline>::Show(int i) {

    cout << "\nAdresa Web:" << web[i];
    cout << "\nNr Vizualizatori:" << vizualizari[i];
    cout << "\nDiscount actual:" << discount[i];
}

template<class T>
T GestionareFarmacii<T>::MeniuClasic(int i) {

    int operatie = -1;
    while (operatie != 0) {
        cout
                << "\nCe operatie se doreste ? 1.Schimbare Proprietar \n 2.Schimbare Denumire \n 3.Schimbare Numar Angajati \n 4.Actualizare profit \n 5.Vizualizare date curente \n 0.Iesire";
        cin >> operatie;
        switch (operatie) {
            case 1: {
                string nou_proprietar;
                cout << "\nNumele noului proprietar";
                cin >> nou_proprietar;
                proprietar[i] = nou_proprietar;
                break;
            }
            case 2: {
                string noua_denumire;
                cout << "\nDenumire noua:";
                cin >> noua_denumire;
                denumire[i] = noua_denumire;
                break;
            }
            case 3: {
                int nou_nrang;
                cout << "\nNumar nou angajati:";
                cin >> nou_nrang;
                nr_angajati[i] = nou_nrang;
                break;
            }
            case 4: {
                double profit_nou;
                cout << "\nProfit nou:";
                cin >> profit_nou;
                profit[i] = profit_nou;
                break;
            }
            case 5: {
                cout << "\nProprietar:" << proprietar[i];
                cout << "\nDenumire:" << denumire[i];
                cout << "\nNr Angajati:" << nr_angajati[i];
                cout << "\nProfit anual:" << profit[i];
                break;
            }
        }
    }

}

template<class T>
T GestionareFarmacii<T>::Meniu(int i) {

    int operatie = -1;
    while (operatie != 0) {
        cout
                << "\nCe operatie se doreste ? 1.Schimbare adresa web \n 2.Schimbare numar vizualizari \n 3.Schimbare Discount \n 4.Vizualizare date actuale \n 0.Iesire";
        cin >> operatie;
        switch (operatie) {
            case 1: {
                string noua_adresa;
                cout << "Noua adresa web:";
                cin >> noua_adresa;
                web[i] = noua_adresa;
                break;
            }
            case 2: {
                int nou_viz;
                cout << "Nr Viz nou:";
                cin >> nou_viz;
                vizualizari[i] = nou_viz;
                break;
            }
            case 3: {
                int nou_discount;
                cout << "Discount nou:";
                cin >> nou_discount;
                discount[i] = nou_discount;
                break;
            }
            case 4: {
                cout << "\nAdresa Web:" << web[i];
                cout << "\nNr Vizualizatori:" << vizualizari[i];
                cout << "\nDiscount actual:" << discount[i];
                break;
            }
        }
    }
}

int main() {
    typedef vector<tuple<string, int, int>> online;
    online fo;
    fo.push_back(tuple<string, int, int>("www.farmacie1.ro", 253, 10));
    fo.push_back(tuple<string, int, int>("www.farmacie2.ro", 323, 12));
    fo.push_back(tuple<string, int, int>("www.farmacie3.ro", 3623, 5));
    FarmacieOnline fo1;
    online tuple_fo1;
    online tuple_fos;
    FarmacieOnline fos[100];
    Farmacie f1;
    Farmacie fn[100];
    int farmacii_normale = 0;
    //meniu
    int option = -1;
    cout
            << "Operatii:1.Adaugare o farmacie \n 2.Adaugare o farmacie online \n 3.Creare n farmacii \n 4.Creare n farmacii online";
    cin >> option;
    switch (option) {

        case 1: {
            string nume;
            double nr;
            cout << "\nNume Proprietar:";
            cin >> nume;
            f1.setProprietar(nume);
            cout << "\nNume Farmacie:";
            cin >> nume;
            fo1.setDenumire(nume);
            cout << "\nNr Angajati:";
            cin >> nr;
            fo1.setNumarAngajati(int(nr));
            cout << "\nProfit Anual";
            cin >> nr;
            fo1.setProfit(nr);
            break;
        }

        case 2: {

            string web;
            int viz;
            int discount;
            cout << "Introduceti adresa web:";
            cin >> web;
            fo1.setAdresaWeb(web);
            cout << "\nNumar vizitatori:";
            cin >> viz;
            fo1.setNrVizitatori(viz);
            cout << "\nDiscount:";
            cin >> discount;
            fo1.setDiscount(discount);
            tuple_fo1.push_back(tuple<string, int, int>(web, viz, discount));
            cout << "\nweb:" << get<0>(tuple_fo1[0]);
            cout << "\nviz:" << get<1>(tuple_fo1[0]);
            cout << "\ndiscount:" << get<2>(tuple_fo1[0]);
            break;
        }
        case 3: {
            cout << "Cate farmacii?:";
            double nr;
            int nr1;

            cin >> nr1;
            string nume;
            for (int i = 0; i < nr1; i++) {
                farmacii_normale++;
                cout << "\nNume Proprietar:";
                cin >> nume;
                fn[i].setProprietar(nume);
                cout << "\nNume Farmacie:";
                cin >> nume;
                fn[i].setDenumire(nume);
                cout << "\nNr Angajati:";
                cin >> nr;
                fn[i].setNumarAngajati(int(nr));
                cout << "\nProfit Anual";
                cin >> nr;
                fn[i].setProfit(nr);

            }
            break;

        }
        case 4: {
            int nr = 0;
            cout << "\nCate farmacii?:";
            cin >> nr;
            for (int i = 0; i < nr; i++) {
                string web;
                farmacii_normale++;
                int viz;
                int discount;
                cout << "Introduceti adresa web:";
                cin >> web;
                fos[i].setAdresaWeb(web);
                cout << "\nNumar vizitatori:";
                cin >> viz;
                fos[i].setNrVizitatori(viz);
                cout << "\nDiscount:";
                cin >> discount;
                fos[i].setDiscount(discount);
                tuple_fos.push_back(tuple<string, int, int>(web, viz, discount));

            }
            break;
        }


    }

    if (option == 2) {
        GestionareFarmacie<FarmacieOnline> obj(fo1.getAdresaWeb(), fo1.getNrVizitatori(), fo1.getDiscount());
        obj.Meniu();
    }
    if (option == 1) {
        GestionareFarmacie<Farmacie> obj2(f1.getProprietar(), f1.getDenumire(), f1.getNumarAngajati(), f1.getProfit());
        obj2.MeniuClasic();
    }

    if (option == 3) {
        for (int i = 0; i < farmacii_normale; i++) {

            GestionareFarmacii<Farmacie> objs(i, fn[i].getProprietar(), fn[i].getDenumire(), fn[i].getNumarAngajati(),
                                              fn[i].getProfit());
            if (i == (farmacii_normale - 1)) {
                cout << "\nCe farmacie sa fie manageriata? Index:0-" << farmacii_normale - 1;
                int dorinta = 0;
                cin >> dorinta;
                objs.MeniuClasic(i);
            }
        }


    }
    if (option == 4) {
        for (int i = 0; i < farmacii_normale; i++) {
            GestionareFarmacii<FarmacieOnline> objs(i, fos[i].getAdresaWeb(), fos[i].getNrVizitatori(),
                                                    fos[i].getDiscount());
            if (i == (farmacii_normale - 1)) {
                cout << "\nCe farmacie sa fie manageriata? Index:0-" << farmacii_normale - 1;
                int dorinta = 0;
                cin >> dorinta;
                objs.Meniu(i);
            }
        }

    }


    return 0;
}