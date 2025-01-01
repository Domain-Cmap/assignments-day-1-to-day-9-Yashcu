#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual void calculateArea() = 0; // Pure virtual function
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    float length;
    float width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}

    void calculateArea() override {
        cout << "Shape: Rectangle\n";
        cout << "Area: " << length * width << "\n";
    }
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : radius(r) {}

    void calculateArea() override {
        cout << "Shape: Circle\n";
        cout << "Area: " << M_PI * radius * radius << "\n";
    }
};

class Triangle : public Shape {
private:
    float base;
    float height;

public:
    Triangle(float b, float h) : base(b), height(h) {}

    void calculateArea() override {
        cout << "Shape: Triangle\n";
        cout << "Area: " << 0.5 * base * height << "\n";
    }
};

int main() {
    int shapeType;
    cout << "Enter shape type (1 for Rectangle, 2 for Circle, 3 for Triangle): ";
    cin >> shapeType;

    if (shapeType == 1) {
        float length, width;
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter width: ";
        cin >> width;

        if (length <= 0 || width <= 0) {
            cout << "Invalid dimensions.\n";
            return 1;
        }

        Rectangle rectangle(length, width);
        rectangle.calculateArea();
    } else if (shapeType == 2) {
        float radius;
        cout << "Enter radius: ";
        cin >> radius;

        if (radius <= 0) {
            cout << "Invalid radius.\n";
            return 1;
        }

        Circle circle(radius);
        circle.calculateArea();
    } else if (shapeType == 3) {
        float base, height;
        cout << "Enter base: ";
        cin >> base;
        cout << "Enter height: ";
        cin >> height;

        if (base <= 0 || height <= 0) {
            cout << "Invalid dimensions.\n";
            return 1;
        }

        Triangle triangle(base, height);
        triangle.calculateArea();
    } else {
        cout << "Invalid shape type.\n";
    }

    return 0;
}
