#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int rollno;
    string name;
    Student(int rollno, string name) {
        this->rollno = rollno;
        this->name = name;
    }
};

class result : public Student {
    int first, second, third;
public:
    result(int rollno, string name, int first, int second, int third)
        : Student(rollno, name), first(first), second(second), third(third) {}

    void calculate() {
        cout << "Roll No: " << rollno << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << first << ", " << second << ", " << third << endl;
        int total = first + second + third;
        cout << "Total: " << total << endl;
        cout << "Percentage: " << (total / 300.0) * 100 << "%" << endl;
    }
};

int main() {
    int rollno, mark1, mark2, mark3;
    string name;
    cout << "Enter Roll No, Name, and Marks (3 subjects):" << endl;
    cin >> rollno;
    cin.ignore(); 
    getline(cin, name);
    cin >> mark1 >> mark2 >> mark3;

    result r(rollno, name, mark1, mark2, mark3);
    r.calculate();
    return 0;
}
