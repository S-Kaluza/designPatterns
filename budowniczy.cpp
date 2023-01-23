#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class ListaPlanowNoworocznych
{
public:
    vector<string> questions;
    ~ListaPlanowNoworocznych(){};
    void Lista() const
    {
        cout << "Lista planów noworocznych" << endl;
        for (size_t i = 0; i < questions.size(); i++)
        {
            cout << questions[i] << ", " << endl;
        }
        cout << endl
             << endl;
    }
};

class Budowniczy
{
public:
    ~Budowniczy(){};
    virtual void ustawPlan1() const = 0;
    virtual void ustawPlan2() const = 0;
    virtual void ustawPlan3() const = 0;
    virtual void ustawPlan4() const = 0;
    virtual void ustawPlan5() const = 0;
    virtual void ustawPlan6() const = 0;
};

class BudowniczyPlanowNoworocznych : public Budowniczy
{
    ListaPlanowNoworocznych *lista;
    string plan;

public:
    virtual ~BudowniczyPlanowNoworocznych(){};
    BudowniczyPlanowNoworocznych()
    {
        this->reset();
    }
    void reset()
    {
        this->lista = new ListaPlanowNoworocznych();
    }
    void ustawPlan1() const override
    {
        string plan1;
        cout << "Podaj plan 1: ";
        cin >> plan1;
        this->lista->questions.push_back(plan1);
    }
    void ustawPlan2() const override
    {
        string plan2;
        cout << "Podaj plan 2: ";
        cin >> plan2;
        this->lista->questions.push_back(plan2);
    }
    void ustawPlan3() const override
    {
        string plan3;
        cout << "Podaj plan 3: ";
        cin >> plan3;
        this->lista->questions.push_back(plan3);
    }
    void ustawPlan4() const override
    {
        string plan4;
        cout << "Podaj plan 4: ";
        cin >> plan4;
        this->lista->questions.push_back(plan4);
    }
    void ustawPlan5() const override
    {
        string plan5;
        cout << "Podaj plan 5: ";
        cin >> plan5;
        this->lista->questions.push_back(plan5);
    }
    void ustawPlan6() const override
    {
        string plan6;
        cout << "Podaj plan 6: ";
        cin >> plan6;
        this->lista->questions.push_back(plan6);
    }

    ListaPlanowNoworocznych *getLista()
    {
        ListaPlanowNoworocznych *result = this->lista;
        this->reset();
        return result;
    }
};

class Dyrektor
{
private:
    Budowniczy *budowniczy;

public:
    void ustaw_budowniczy(Budowniczy *budowniczy)
    {
        this->budowniczy = budowniczy;
    }

    void budujMinimalnaWersje()
    {
        this->budowniczy->ustawPlan1();
        this->budowniczy->ustawPlan2();
        this->budowniczy->ustawPlan3();
    }

    void budujPelnaWersje()
    {
        this->budowniczy->ustawPlan1();
        this->budowniczy->ustawPlan2();
        this->budowniczy->ustawPlan3();
        this->budowniczy->ustawPlan4();
        this->budowniczy->ustawPlan5();
        this->budowniczy->ustawPlan6();
    }
};

void Klient(Dyrektor &dyrektor)
{
    BudowniczyPlanowNoworocznych *budowniczy = new BudowniczyPlanowNoworocznych();
    dyrektor.ustaw_budowniczy(budowniczy);
    cout << "Minimalna wersja planow noworocznych" << endl;
    dyrektor.budujMinimalnaWersje();
    ListaPlanowNoworocznych *lista = budowniczy->getLista();
    lista->Lista();
    cout << "Pelna wersja planow noworocznych" << endl;
    dyrektor.budujPelnaWersje();
    lista = budowniczy->getLista();
    lista->Lista();
    delete lista;
    delete budowniczy;
}

int main()
{
    Dyrektor dyrektor;
    Klient(dyrektor);
    delete &dyrektor;
    return 0;
}