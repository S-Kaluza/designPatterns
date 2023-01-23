#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Youtube
{
public:
    virtual ~Youtube(){};
    virtual string opiszProdukt() const = 0;
};

class PodstawowyYoutube : public Youtube
{
public:
    string opiszProdukt() const override
    {
        return "wersja bezpłatna z licznymi reklamami";
    }
};

class PremiumYoutube : public Youtube
{
public:
    string opiszProdukt() const override
    {
        return "wersja bezpłatna z bardzo ograniczoną pojemnością";
    }
};

class DyskGoogle
{
public:
    virtual ~DyskGoogle(){};
    virtual string opiszProdukt() const = 0;
};

class PremiumDyskGoogle : public DyskGoogle
{
public:
    string opiszProdukt() const override
    {
        return "wersja płatna z możliwością odtwarzania w tle, bez natarczywych reklam";
    }
};

class PodstawowyDyskGoogle : public DyskGoogle
{
public:
    string opiszProdukt() const override
    {
        return "wersja płatna z dużą pojemnością";
    }
};

class FabrykaAbstrakcjii
{
public:
    virtual DyskGoogle *UtworzDyskGoogle() const = 0;
    virtual Youtube *UtworzYoutube() const = 0;
};

class FabrykaPodstawowychProduktow : public FabrykaAbstrakcjii
{
    DyskGoogle *UtworzDyskGoogle() const override
    {
        return new PodstawowyDyskGoogle();
    }
    Youtube *UtworzYoutube() const override
    {
        return new PodstawowyYoutube();
    }

public:
    virtual ~FabrykaPodstawowychProduktow(){};
};

class FabrykaPremiumProduktow : public FabrykaAbstrakcjii
{
    DyskGoogle *UtworzDyskGoogle() const override
    {
        return new PremiumDyskGoogle();
    }
    Youtube *UtworzYoutube() const override
    {
        return new PremiumYoutube();
    }

public:
    virtual ~FabrykaPremiumProduktow(){};
};

void Klient(const FabrykaAbstrakcjii &fabryka)
{
    const DyskGoogle *dysk = fabryka.UtworzDyskGoogle();
    const Youtube *youtube = fabryka.UtworzYoutube();
    cout << "Dysk Google: " << dysk->opiszProdukt() << endl;
    cout << "Youtube: " << youtube->opiszProdukt() << endl;
    delete youtube;
    delete dysk;
}

int main()
{
    cout << "Klient: Testuję klienta z fabryką produktów podstawowych fabryką:" << endl;
    FabrykaPodstawowychProduktow *f1 = new FabrykaPodstawowychProduktow();
    Klient(*f1);
    delete f1;
    cout << "Klient: Testuję klienta z fabryką produktów premium:";
    FabrykaPremiumProduktow *f2 = new FabrykaPremiumProduktow();
    Klient(*f2);
    delete f2;
}