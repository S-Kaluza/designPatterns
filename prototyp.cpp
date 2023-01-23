#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

enum Type
{
    PRZECIWNIK_1 = 0,
    PRZECIWNIK_2,
    PRZECIWNIK_3,
    PRZECIWNIK_4,
};

class PrototypPrzeciwnika
{
protected:
    string nazwa_przeciwnika;
    float sila_przeciwnika;

public:
    virtual ~PrototypPrzeciwnika(){};
    virtual PrototypPrzeciwnika *kopiuj() const = 0;
    virtual void wyswietlInformacje()
    {
        cout << "Nazwa przeciwnika: " << this->nazwa_przeciwnika << endl;
        cout << "Sila przeciwnika: " << this->sila_przeciwnika << endl;
    };
};

class Wilk : public PrototypPrzeciwnika
{
private:
    float sila_przeciwnika;

public:
    Wilk(string nazwa_przeciwnika, float sila_przeciwnika)
    {
        this->nazwa_przeciwnika = nazwa_przeciwnika;
        this->sila_przeciwnika = sila_przeciwnika;
    }

    PrototypPrzeciwnika *kopiuj() const override
    {
        return new Wilk(*this);
    }
};

class DzikiPies : public PrototypPrzeciwnika
{
private:
    float sila_przeciwnika;

public:
    DzikiPies(string nazwa_przeciwnika, float sila_przeciwnika)
    {
        this->nazwa_przeciwnika = nazwa_przeciwnika;
        this->sila_przeciwnika = sila_przeciwnika;
    }

    PrototypPrzeciwnika *kopiuj() const override
    {
        return new DzikiPies(*this);
    }
};

class FabrykaPrototypow
{
private:
    unordered_map<Type, PrototypPrzeciwnika *, std::hash<int>> prototypy;

public:
    FabrykaPrototypow()
    {
        this->prototypy[PRZECIWNIK_1] = new Wilk("Slaby Wilk", 10);
        this->prototypy[PRZECIWNIK_2] = new Wilk("Szary Wilk 2", 20);
        this->prototypy[PRZECIWNIK_3] = new DzikiPies("Słaby Dziki pies", 30);
        this->prototypy[PRZECIWNIK_4] = new DzikiPies("Dziki pies", 40);
    }

    ~FabrykaPrototypow()
    {
        delete this->prototypy[PRZECIWNIK_1];
        delete this->prototypy[PRZECIWNIK_2];
        delete this->prototypy[PRZECIWNIK_3];
        delete this->prototypy[PRZECIWNIK_4];
    }

    PrototypPrzeciwnika *utworzPrototyp(Type type)
    {
        return this->prototypy[type]->kopiuj();
    }
};

void Klient(FabrykaPrototypow &fabryka)
{
    PrototypPrzeciwnika *prototyp1 = fabryka.utworzPrototyp(PRZECIWNIK_1);
    PrototypPrzeciwnika *prototyp2 = fabryka.utworzPrototyp(PRZECIWNIK_2);
    PrototypPrzeciwnika *prototyp3 = fabryka.utworzPrototyp(PRZECIWNIK_3);
    PrototypPrzeciwnika *prototyp4 = fabryka.utworzPrototyp(PRZECIWNIK_4);

    cout << "Prototyp 1: " << endl;
    prototyp1->wyswietlInformacje();
    cout << endl;

    cout << "Prototyp 2: " << endl;
    prototyp2->wyswietlInformacje();
    cout << endl;

    cout << "Prototyp 3: " << endl;
    prototyp3->wyswietlInformacje();
    cout << endl;

    cout << "Prototyp 4: " << endl;
    prototyp4->wyswietlInformacje();
    cout << endl;

    delete prototyp1;
    delete prototyp2;
    delete prototyp3;
    delete prototyp4;
}

int main()
{
    FabrykaPrototypow *fabryka = new FabrykaPrototypow();
    Klient(*fabryka);
    delete fabryka;

    return 0;
}