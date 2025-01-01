#include <iostream>
#include <cmath>
using namespace std;

// Function overloading for calculating area
float calculateArea(float radius) {
    return 3.14159f * radius * radius;
}

float calculateArea(float length, float breadth) {
    return length * breadth;
}

float calculateArea(float base, float height, bool isTriangle) {
    return 0.5f * base * height;
}

int main() {
    int choice;
    cout << "Select shape to calculate area:\n";
    cout << "1. Circle\n2. Rectangle\n3. Triangle\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        float radius;
        cout << "Enter radius of the circle: ";
        cin >> radius;

        if (radius <= 0) {
            cout << "Invalid input. Radius must be positive." << endl;
        } else {
            cout << "Area of Circle: " << calculateArea(radius) << endl;
        }
        break;
    }
    case 2: {
        float length, breadth;
        cout << "Enter length and breadth of the rectangle: ";
        cin >> length >> breadth;

        if (length <= 0 || breadth <= 0) {
            cout << "Invalid input. Dimensions must be positive." << endl;
        } else {
            cout << "Area of Rectangle: " << calculateArea(length, breadth) << endl;
        }
        break;
    }
    case 3: {
        float base, height;
        cout << "Enter base and height of the triangle: ";
        cin >> base >> height;

        if (base <= 0 || height <= 0) {
            cout << "Invalid input. Dimensions must be positive." << endl;
        } else {
            cout << "Area of Triangle: " << calculateArea(base, height, true) << endl;
        }
        break;
    }
    default:
        cout << "Invalid choice. Please select a valid shape type." << endl;
    }

    return 0;
}
