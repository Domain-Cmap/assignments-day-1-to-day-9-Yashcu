#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string title;
    string author;
    int isbn;

public:
    void setBookDetails(const string& t, const string& a, int i) {
        title = t;
        author = a;
        isbn = i;
    }

    void displayBookDetails() const {
        cout << "\"" << title << "\" by " << author << " (ISBN: " << isbn << ")";
    }
};

class Borrower {
protected:
    string name;
    int id;

public:
    void setBorrowerDetails(const string& n, int i) {
        name = n;
        id = i;
    }

    void displayBorrowerDetails() const {
        cout << "Borrower " << name << " (ID: " << id << ")";
    }
};

class Library : public Book, public Borrower {
public:
    void borrowBook() {
        cout << "Borrower ";
        displayBorrowerDetails();
        cout << " has borrowed ";
        displayBookDetails();
        cout << "." << endl;
    }

    void returnBook() {
        cout << "Borrower ";
        displayBorrowerDetails();
        cout << " has returned ";
        displayBookDetails();
        cout << "." << endl;
    }
};

int main() {
    Library library;
    string title, author, name;
    int isbn, id, action;

    cout << "Enter book details:\nTitle: ";
    getline(cin, title);
    cout << "Author: ";
    getline(cin, author);
    cout << "ISBN: ";
    cin >> isbn;

    cout << "Enter borrower details:\nName: ";
    cin.ignore();
    getline(cin, name);
    cout << "ID: ";
    cin >> id;

    cout << "Enter action type (1 to Borrow, 2 to Return): ";
    cin >> action;

    if (isbn < 1000 || isbn > 9999 || id < 1 || id > 1000) {
        cout << "Invalid book or borrower details." << endl;
        return 1;
    }

    library.setBookDetails(title, author, isbn);
    library.setBorrowerDetails(name, id);

    switch (action) {
        case 1:
            library.borrowBook();
            break;
        case 2:
            library.returnBook();
            break;
        default:
            cout << "Invalid action type." << endl;
    }

    return 0;
}
