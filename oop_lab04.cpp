//5. Компанії та Працівники :
       //Базовий клас : Компанія
             //Похідний клас : Працівник
                  //Похідний клас : Менеджер
                       //Похідний клас : ВищийМенеджер
             //Похідний клас : Інженер
                  //Похідний клас : ГоловнийІнженер

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//Базовий клас : Компанія
class Company {
public:
    Company(const string& name) : name(name) {}

    void nameOfCompany() const {
        cout << "Назва компанії: " << name << endl;
    }
private:
    string name;
};

//Похідний клас : Працівник
class Employee : public Company {
public:
    Employee(const string& name, const string& start, const string& founders)
        : Company(name), start(start), founders(founders) {}

    void yearOfStart() const {
        cout << "Рік заснування: " << start << endl;
    }
    void foundersOfCompany() const {
        cout << "Ім'я засновників: " << founders << endl;
    }
private:
    string start;
    string founders;
};

//Похідний клас : Менеджер
class Manager : public Employee {
public:
    Manager(const string& name, const string& start, const string& founders, int capital)
        : Employee(name, start, founders), capital(capital) {}

    void startupCapital() const {
        cout << "Стартовий капітал $: " << capital << endl;
    }
private:
   int capital;
};

//Похідний клас : ВищийМенеджер
class seniorManager : public Manager {
public:
    seniorManager(const string& name, const string& start, const string& founders, int capital, const string& product)
        : Manager(name, start, founders, capital), product(product) {}

    void firstProduct() const {
        cout << "Перший продукт: " << product << endl;
    }
private:
    string product;
};

//Похідний клас : Інженер
class Engineer : public Company {
public:
    Engineer(const string& name, const string& founder, const string& president)
        : Company(name), founder(founder), president(president) {}

    void founderOfCompany() const {
        cout << "Ім'я засновника: " << founder << endl;
    }
    void presidentOfCompany() const {
        cout << "Ім'я президента компанії: " << president << endl;
    }
private:
    string founder;
    string president;
};

//Похідний клас : ГоловнийІнженер
class chiefEngineer : public Engineer {
public:
    chiefEngineer(const string& name, const string& founder, const string& president, const string& country)
        : Engineer(name, founder, president), country(country) {}

    void startCountry() const {
        cout << "Країна заснування: " << country << endl;
    }
private:
    string country;
};

int main() {
    SetConsoleOutputCP(1251);

    seniorManager Disney("Walt Disney", "16 жовтня 1923 року", "брати Уолт Дісней та Уолт Олівер Дісней", 500, "мультфільм 'Аліса на морі'");
    Disney.nameOfCompany();
    Disney.yearOfStart();
    Disney.foundersOfCompany();
    Disney.startupCapital();
    Disney.firstProduct();

    chiefEngineer Amazon("Amazon", "Джефф Безос", "Ендрю Р. Джессі", "США, Вашингтон");
    Amazon.nameOfCompany();
    Amazon.founderOfCompany();
    Amazon.presidentOfCompany();
    Amazon.startCountry();

    return 0;
}
