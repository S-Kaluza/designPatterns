#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;
using std::cout;
using std::endl;
using std::string;

class User
{
protected:
    User(const string userName, const string e_mail) : userName(userName), e_mail(e_mail) {}
    static User *user;
    string userName;
    string e_mail;

public:
    User(const User &) = delete;
    User &operator=(const User &) = delete;
    static User *getInstance(const string userName, const string e_mail);
    void wyswietlInformacje()
    {
        cout << "Nazwa uzytkownika: " << this->userName << endl;
        cout << "E-mail uzytkownika: " << this->e_mail << endl;
    };
    string getUserName() const
    {
        return this->userName;
    }

    string getE_mail() const
    {
        return this->e_mail;
    }
};

User *User::user = nullptr;

User *User::getInstance(const string userName, const string e_mail)
{
    if (user == nullptr)
    {
        user = new User(userName, e_mail);
    }
    return user;
}

void ThreadSetUser1()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    User *user1 = User::getInstance("Jan", "jan@gmail.com");
    cout << "Ustawiam uzytkownika 1: ";
    user1->wyswietlInformacje();
}

void ThreadSetUser2()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    User *user2 = User::getInstance("Adam", "adam@gmail.com");
    cout << "Ustawiam uzytkownika 2: ";
    user2->wyswietlInformacje();
}

int main()
{
    std::thread t1(ThreadSetUser1);
    std::thread t2(ThreadSetUser2);
    t1.join();
    t2.join();
    return 0;
}