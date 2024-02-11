//5. ������ �� ���������� :
       //������� ���� : �������
             //�������� ���� : ���������
                  //�������� ���� : ��������
                       //�������� ���� : �������������
             //�������� ���� : �������
                  //�������� ���� : ��������������

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//������� ���� : �������
class Company {
public:
    Company(const string& name) : name(name) {}

    void nameOfCompany() const {
        cout << "����� ������: " << name << endl;
    }
private:
    string name;
};

//�������� ���� : ���������
class Employee : public Company {
public:
    Employee(const string& name, const string& start, const string& founders)
        : Company(name), start(start), founders(founders) {}

    void yearOfStart() const {
        cout << "г� ����������: " << start << endl;
    }
    void foundersOfCompany() const {
        cout << "��'� ����������: " << founders << endl;
    }
private:
    string start;
    string founders;
};

//�������� ���� : ��������
class Manager : public Employee {
public:
    Manager(const string& name, const string& start, const string& founders, int capital)
        : Employee(name, start, founders), capital(capital) {}

    void startupCapital() const {
        cout << "��������� ������ $: " << capital << endl;
    }
private:
   int capital;
};

//�������� ���� : �������������
class seniorManager : public Manager {
public:
    seniorManager(const string& name, const string& start, const string& founders, int capital, const string& product)
        : Manager(name, start, founders, capital), product(product) {}

    void firstProduct() const {
        cout << "������ �������: " << product << endl;
    }
private:
    string product;
};

//�������� ���� : �������
class Engineer : public Company {
public:
    Engineer(const string& name, const string& founder, const string& president)
        : Company(name), founder(founder), president(president) {}

    void founderOfCompany() const {
        cout << "��'� ����������: " << founder << endl;
    }
    void presidentOfCompany() const {
        cout << "��'� ���������� ������: " << president << endl;
    }
private:
    string founder;
    string president;
};

//�������� ���� : ��������������
class chiefEngineer : public Engineer {
public:
    chiefEngineer(const string& name, const string& founder, const string& president, const string& country)
        : Engineer(name, founder, president), country(country) {}

    void startCountry() const {
        cout << "����� ����������: " << country << endl;
    }
private:
    string country;
};

int main() {
    SetConsoleOutputCP(1251);

    seniorManager Disney("Walt Disney", "16 ������ 1923 ����", "����� ���� ĳ���� �� ���� ����� ĳ����", 500, "���������� '���� �� ���'");
    Disney.nameOfCompany();
    Disney.yearOfStart();
    Disney.foundersOfCompany();
    Disney.startupCapital();
    Disney.firstProduct();

    chiefEngineer Amazon("Amazon", "����� �����", "����� �. �����", "���, ���������");
    Amazon.nameOfCompany();
    Amazon.founderOfCompany();
    Amazon.presidentOfCompany();
    Amazon.startCountry();

    return 0;
}
