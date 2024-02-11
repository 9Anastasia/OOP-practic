//1. ���� ������������ ��������� ���������� �� �������� �����

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <Windows.h>

using namespace std;

class Book {
public:
    Book(string title, string author, int year) : title(title), author(author), year(year) {}

    void displayInfo() const {
        cout << "�����: " << title << ", �����: " << author << ", г�: " << year << endl;
    }

    void edit() {
        cout << "���� ����� �����: "; cin >> this->title;
        cout << "����� ����� �����: "; cin >> this->author;
        cout << "����� �� ������� �����: "; cin >> this->year;
    }
    
    bool operator<(const Book& other) const {
        return title < other.title;
    }

    int bookTitle(string other) {
        if (this->title == other) {
            return 1;
        }
        else return 0;
    }

private:
    string title;
    string author;
    int year;

};

int main() {
    SetConsoleOutputCP(1251);
    vector<Book> library;

    library.push_back(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.push_back(Book("1984", "George Orwell", 1949));
    library.push_back(Book("The Catcher in the Rye", "J.D. Salinger", 1951));

    cout << "���������� ��� ����� � ��������:" << endl;
    for (const auto& book : library) {
        book.displayInfo();
    }

    sort(library.begin(), library.end());

    cout << "\n��������� ���� ���������� �� ������ �����:" << endl;
    for (const auto& book : library) {
        book.displayInfo();
    }

    int variant; string edit; string remove;

    do {
        cout << "------------------------------------- \n";
        cout << "1. ���������� �����" << endl;
        cout << "2. �������� �����" << endl;
        cout << "3. ���������� ��������� ������" << endl;
        cout << "������ ��:"; cin >> variant;


        if (variant == 1) {
            cout << "\n������ ����� �����: "; cin >> edit;
            for (int i = 0; i < library.size(); i++) {
                if (library[i].bookTitle(edit)) {
                    library[i].edit();
                    break;
                }
            }
            cout << "������ ����: \n";
            for (const auto& book : library) {
                book.displayInfo();
            }
        }
        if (variant == 2) {
            cin.ignore();
            cout << "\n������ ����� �����: ";  getline(cin, remove);
            for (int i = 0; i < library.size(); i++) {
                if (library[i].bookTitle(remove)) {
                    library.erase(library.begin() + i);
                    break;
                }
            }
            cout << "������ ����: \n";
            for (const auto& book : library) {
                book.displayInfo();
            }
        }
    } while (variant != 3);

    cout << "------------------------------------- \n";
    cout << "��������� ������ ����: \n";
    for (const auto& book : library) {
        book.displayInfo();
    }

    return 0;
}



//2. ���� ������������ ��������� ������ � ��� ����������� ��������� ������(� ������� ���������, �� � ������� ���������)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    vector<string> favoriteFruits;

    cout << "������� ������� �� ��� '���������� ������'!" << endl;
    cout << "������ ��� ������� ������ (������ '0', ��� ��������� ��������):" << endl;

    string fruit;
    while (true) {
        cout << "�����: ";
        cin >> fruit;

        // �������� �� ����� � ���
        if (fruit == "0") {
            break;
        }

        favoriteFruits.push_back(fruit);
    }

    cout << "� ����� ������� ��������� ������?" << endl;
    cout << "1. ³� � �� �" << endl;
    cout << "2. ³� � �� �" << endl;

    int n;
    cout << "������ �����: "; cin >> n;

    if (n == 1) {
        sort(favoriteFruits.begin(), favoriteFruits.end());
    }
    if (n == 2) {
        sort(favoriteFruits.rbegin(), favoriteFruits.rend());
    }

    cout << "\n���� ������� ������ � �������� �������:" << endl;
    for (const auto& favoriteFruit : favoriteFruits) {
        cout << favoriteFruit << endl;
    }

    cout << "��� ���������. ������ �� ������!" << endl;

    return 0;
}



//3. ���� ��������� �������� ������������ ������� �����(������� ������������ ������� ������ �������)

#include <iostream>
#include <list>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

class Joke {
public:
    Joke(string text) : text(text), votes(0), totalRating(0) {}

    void tellJoke() const {
        cout << "����: " << text << endl;
        cout << "������: " << fixed << setprecision(2) << getAverageRating() << " (������: " << votes << ")" << endl;
    }

    void rateJoke(int rating) {
        if (rating >= 1 && rating <= 5) {
            votes++;
            totalRating += rating;
        }
        else {
            cout << "������ ������� ���� �� 1 �� 5!" << endl;
        }
    }

    double getAverageRating() const {
        return (votes > 0) ? static_cast<double>(totalRating) / votes : 0.0;
    }

private:
    string text;
    int votes;
    int totalRating;
};

int main() {
    SetConsoleOutputCP(1251);
    list<Joke> jokeList;

    jokeList.push_back(Joke("���� ���������� ��� ������ ������? ���� �� ���� ����� ������ �� ����!"));
    jokeList.push_back(Joke("���� ��� ���� ��� �������������: �� ��� �� ����������, ������ �� ������������."));
    jokeList.push_back(Joke("�� ������ ��������� ���� �����������? ���������� �� ����� ����������!"));
    jokeList.push_back(Joke("������ ���� � ���� ���� ��������: ��������� ���� ����, ����� ���."));

    cout << "������� ������� �� �������� ��� ���������� �����!" << endl;

    int players;
    cout << "������ ������� �������:"; cin >> players;

    for (int i = 1; i <= players; i++) {
        cout << "������ ������� ����� " << i << endl;
        for (auto& joke : jokeList) {
            joke.tellJoke();

            int userRating;
            cout << "���� ������ (1-5): ";
            cin >> userRating;

            joke.rateJoke(userRating);
        }
        cout << "-------------------------------------" << endl;
    }

    cout << "\n����� � ������� ���������:" << endl;
    for (const auto& joke : jokeList) {
        if (joke.getAverageRating() >= 4.0) {
            joke.tellJoke();
        } 
    }

    return 0;
}


//4. ������ ������ ��������� ������ �����������(����� �� ���������)
 
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");

    map<string, double> studentGrades;
    vector<string> request;
    vector<string> result;

    studentGrades["Anna"] = 4.5;
    studentGrades["Jeremy"] = 3.8;
    studentGrades["Katrin"] = 4.2;
    studentGrades["Dmitry"] = 4.0;

    cout << "���������� ��� ��������:" << endl;
    for (const auto& student : studentGrades) {
        cout << student.first << ": " << student.second << endl;
    }

    string searchStudent;
    do {
        cout << "\n������ ��'� �������� ��� ������ ���������� ����. ��� �������� ����� �������� '0': ";
        cin >> searchStudent;
        request.push_back(searchStudent);

        auto it = studentGrades.find(searchStudent);
        if (it != studentGrades.end()) {
            cout << "������� ��� �������� " << searchStudent << ": " << it->second << endl;

            result.push_back(to_string(it->second));
        }
        else if (searchStudent != "0") {
            cout << "������� � ������ " << searchStudent << " �� ���������." << endl;

            result.push_back("none");
        }

    } while (searchStudent != "0");

    for (int i = 0; i < result.size(); i++) {
        cout << "�����: " << request[i] << endl;
        cout << "���������: " << result[i] << endl;
    }


    return 0;
}

