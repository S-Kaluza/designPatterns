#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Auto
{
public:
    virtual ~Auto(){};
    virtual string Operation() const = 0;
};

class Ciezarowka : public Auto
{
public:
    string Operation() const override
    {
        return "Ciezarowka";
    }
};

class Osobowe : public Auto
{
public:
    string Operation() const override
    {
        return "Osobowe";
    }
};

class Fabryka
{
public:
    virtual ~Fabryka(){};
    virtual Auto *FabrykaWytworcza() const = 0;
    string kimJestes() const
    {
        Auto *product = this->FabrykaWytworcza();
        string result = "\nFabryka: " + product->Operation();
        delete product;
        return result;
    }
};

class FabrykaCiezarowek : public Fabryka
{
    Auto *FabrykaWytworcza() const override
    {
        return new Ciezarowka();
    }
};

class FabrykaOsobowych : public Fabryka
{
    Auto *FabrykaWytworcza() const override
    {
        return new Osobowe();
    }
};

void ClientCode(const Fabryka &fabryka)
{
    cout << "jestem" << fabryka.kimJestes() << endl;
}

int main()
{
    cout << "Fabryka Ciezarowek" << endl;
    Fabryka *fabryka = new FabrykaCiezarowek();
    ClientCode(*fabryka);
    cout << "Fabryka Osobowych" << endl;
    Fabryka *fabryka2 = new FabrykaOsobowych();
    ClientCode(*fabryka2);
}