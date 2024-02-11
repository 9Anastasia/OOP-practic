//1. дати користувачеві можливість редагувати та видаляти книги

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
        cout << "Книга: " << title << ", Автор: " << author << ", Рік: " << year << endl;
    }

    void edit() {
        cout << "Нова назва книги: "; cin >> this->title;
        cout << "Новий автор книги: "; cin >> this->author;
        cout << "Новий рік випуску книги: "; cin >> this->year;
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

    cout << "Інформація про книги в бібліотеці:" << endl;
    for (const auto& book : library) {
        book.displayInfo();
    }

    sort(library.begin(), library.end());

    cout << "\nБібліотека після сортування за назвою книги:" << endl;
    for (const auto& book : library) {
        book.displayInfo();
    }

    int variant; string edit; string remove;

    do {
        cout << "------------------------------------- \n";
        cout << "1. Редагувати книгу" << endl;
        cout << "2. Видалити книгу" << endl;
        cout << "3. Подивитися оновлений список" << endl;
        cout << "Оберіть дію:"; cin >> variant;


        if (variant == 1) {
            cout << "\nОберіть назву книги: "; cin >> edit;
            for (int i = 0; i < library.size(); i++) {
                if (library[i].bookTitle(edit)) {
                    library[i].edit();
                    break;
                }
            }
            cout << "Список книг: \n";
            for (const auto& book : library) {
                book.displayInfo();
            }
        }
        if (variant == 2) {
            cin.ignore();
            cout << "\nОберіть назву книги: ";  getline(cin, remove);
            for (int i = 0; i < library.size(); i++) {
                if (library[i].bookTitle(remove)) {
                    library.erase(library.begin() + i);
                    break;
                }
            }
            cout << "Список книг: \n";
            for (const auto& book : library) {
                book.displayInfo();
            }
        }
    } while (variant != 3);

    cout << "------------------------------------- \n";
    cout << "Оновлений список книг: \n";
    for (const auto& book : library) {
        book.displayInfo();
    }

    return 0;
}



//2. дати користувачеві можливість обрати в якій послідовності сортувати фрукти(у порядку зростання, чи у порядку зменшення)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    vector<string> favoriteFruits;

    cout << "Ласкаво просимо до гри 'Сортування фруктів'!" << endl;
    cout << "Введіть свої улюблені фрукти (введіть '0', щоб завершити введення):" << endl;

    string fruit;
    while (true) {
        cout << "Фрукт: ";
        cin >> fruit;

        // Перевірка на вихід з гри
        if (fruit == "0") {
            break;
        }

        favoriteFruits.push_back(fruit);
    }

    cout << "В якому порядку сортувати фрукти?" << endl;
    cout << "1. Від А до Я" << endl;
    cout << "2. Від Я до А" << endl;

    int n;
    cout << "Оберіть цифру: "; cin >> n;

    if (n == 1) {
        sort(favoriteFruits.begin(), favoriteFruits.end());
    }
    if (n == 2) {
        sort(favoriteFruits.rbegin(), favoriteFruits.rend());
    }

    cout << "\nВаші улюблені фрукти в обраному порядку:" << endl;
    for (const auto& favoriteFruit : favoriteFruits) {
        cout << favoriteFruit << endl;
    }

    cout << "Гра завершена. Дякуємо за участь!" << endl;

    return 0;
}



//3. дати можливість декільком користувачам оцінити жарти(кількість користувачів визначає перший гравець)

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
        cout << "Жарт: " << text << endl;
        cout << "Оцінка: " << fixed << setprecision(2) << getAverageRating() << " (Голосів: " << votes << ")" << endl;
    }

    void rateJoke(int rating) {
        if (rating >= 1 && rating <= 5) {
            votes++;
            totalRating += rating;
        }
        else {
            cout << "Оцінка повинна бути від 1 до 5!" << endl;
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

    jokeList.push_back(Joke("Чому програмісти так погано сплять? Тому що вони давно звикли до багів!"));
    jokeList.push_back(Joke("Існує два види мов програмування: на одні усі скаржаться, іншими не користуються."));
    jokeList.push_back(Joke("Що робить програміст після розставання? Переходить на інший репозиторій!"));
    jokeList.push_back(Joke("Основні зміни у новій версії програми: виправлені старі баги, додані нові."));

    cout << "Ласкаво просимо до програми для оцінювання жартів!" << endl;

    int players;
    cout << "Введіть кількість гравців:"; cin >> players;

    for (int i = 1; i <= players; i++) {
        cout << "Голосує гравець номер " << i << endl;
        for (auto& joke : jokeList) {
            joke.tellJoke();

            int userRating;
            cout << "Ваша оцінка (1-5): ";
            cin >> userRating;

            joke.rateJoke(userRating);
        }
        cout << "-------------------------------------" << endl;
    }

    cout << "\nЖарти з високим рейтингом:" << endl;
    for (const auto& joke : jokeList) {
        if (joke.getAverageRating() >= 4.0) {
            joke.tellJoke();
        } 
    }

    return 0;
}


//4. додати журнал пошукових запитів користувача(запит та результат)
 
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

    cout << "Інформація про студентів:" << endl;
    for (const auto& student : studentGrades) {
        cout << student.first << ": " << student.second << endl;
    }

    string searchStudent;
    do {
        cout << "\nВведіть ім'я студента для пошуку середнього балу. Щоб зупинити пошук натисніть '0': ";
        cin >> searchStudent;
        request.push_back(searchStudent);

        auto it = studentGrades.find(searchStudent);
        if (it != studentGrades.end()) {
            cout << "Середній бал студента " << searchStudent << ": " << it->second << endl;

            result.push_back(to_string(it->second));
        }
        else if (searchStudent != "0") {
            cout << "Студент з іменем " << searchStudent << " не знайдений." << endl;

            result.push_back("none");
        }

    } while (searchStudent != "0");

    for (int i = 0; i < result.size(); i++) {
        cout << "Запит: " << request[i] << endl;
        cout << "Результат: " << result[i] << endl;
    }


    return 0;
}

