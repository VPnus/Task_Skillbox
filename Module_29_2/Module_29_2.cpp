#include <iostream>
#include <cmath>
#include <string>

struct bounding_box_dimensions {
    double width;
    double height;
};

class Shape {
public:
    virtual double square() = 0;
    virtual bounding_box_dimensions dimensions() = 0;
    virtual std::string type() = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double square() override {
        return M_PI * radius * radius;
    }

    bounding_box_dimensions dimensions() override {
        return {2 * radius, 2 * radius};
    }

    std::string type() override {
        return "Circle";
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double square() override {
        return length * width;
    }

    bounding_box_dimensions dimensions() override {
        return {length, width};
    }

    std::string type() override {
        return "Rectangle";
    }
};

class Triangle : public Shape {
private:
    double a;
    double b;
    double c;
public:
    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {}

    double square() override {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    bounding_box_dimensions dimensions() override {
        double p = (a + b + c) / 2;
        double radius = a * b * c / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
        return {2 * radius, 2 * radius};
    }

    std::string type() override {
        return "Triangle";
    }
};

void print_params(Shape *shape) {
    std::cout << "Type: " << shape->type() << std::endl;
    std::cout << "Square: " << shape->square() << std::endl;
    bounding_box_dimensions dimensions = shape->dimensions();
    std::cout << "Width: " << dimensions.width << std::endl;
    std::cout << "Height: " << dimensions.height << std::endl;
}

int main() {
    Circle c(5);
    print_params(&c);
    std::cout << std::endl;

    Rectangle r(3, 4);
    print_params(&r);
    std::cout << std::endl;

    Triangle t(3, 4, 5);
    print_params(&t);

    return 0;
}