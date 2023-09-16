#include <iostream>
#include <cmath>

enum Color {
    None,
    Red,
    Green,
    Blue,
    Pink,
};

class Shape
{
public:
    double x,y;
    Color color;

    Shape(double x, double y, Color color) : x(x), y(y), color(color) {}


    void getBoundingBox(double& x1, double& y1, double& x2, double& y2) {
        x1 = x - 0.5;
        y1 = y - 0.5;
        x2 = x + 0.5;
        y2 = y + 0.5;
    }


    Color getColor(int c) {
        return color;
    }


};

class Circle : public Shape
{
public:
    double radius;

    Circle(double x, double y, Color color, double radius) : Shape(x, y, color), radius(radius) {}

    double area() {
        return atan(1) * 4 * radius;
    }

    void getBoundingBox(double& x1, double& y1, double& x2, double& y2) {
        x1 = x - radius;
        y1 = y - radius;
        x2 = x + radius;
        y2 = y + radius;
    }


};

class Square : public Shape
{
public:
    double length;

    Square(double x, double y, Color color, double length) : Shape(x, y, color), length(length) {}

    double area()  {
        return length * length;
    }

    void getBoundingBox(double& x1, double& y1, double& x2, double& y2) {
        x1 = x - length / 2;
        y1 = y - length / 2;
        x2 = x + length / 2;
        y2 = y + length / 2;
    }
};

class Triangle : public Shape
{
public:
    double length;

    Triangle(double x, double y, Color color, double length) : Shape(x, y, color), length(length) {}

    double area() {
        return length * length * std::sqrt(3) / 4;
    }

    void getBoundingBox(double& x1, double& y1, double& x2, double& y2) {
        x1 = x - length / 2;
        y1 = y - length * std::sqrt(3) / 6;
        x2 = x + length / 2;
        y2 = y + length * std::sqrt(3) / 6;
    }
};

class Rectangle : public Shape
{
public:
    double width;
    double height;

    Rectangle(double x, double y, Color color, double width, double height) : Shape(x, y, color), width(width), height(height) {}

    double area()  {
        return width * height;
    }

    void getBoundingBox(double& x1, double& y1, double& x2, double& y2)  {
        x1 = x - width / 2;
        y1 = y - height / 2;
        x2 = x + width / 2;
        y2 = y + height / 2;
    }
};

int main() {
    std::string command;
    static double x,y;
    int colorCode;
    std::cout << "Enter command: circle, square, triangle, rectangle. \n" << std::endl;
    std::cin >> command;
    std::cout << "Enter x, y coordinates: ";
    std::cin >> x >> y;
    std::cout << "Enter color (0 - red, 1 - green, 2 - blue, 3 - Pink, 4 - none): ";
    std::cin >> colorCode;

        if(command == "circle")
        {
            double radius;
            std::cout << "Enter radius: ";
            std::cin >> radius;
            Circle circle(x, y, static_cast<Color>(colorCode), radius);
            std::cout << "Area: " << circle.area() << std::endl;
            double x1, y1, x2, y2;
            circle.getBoundingBox(x1, y1, x2, y2);
            std::cout << "BoundingBox: (" << x1 << ", " << y1 << ") - (" << x2 << ", " << y2 << ")" << std::endl;
            switch (circle.getColor(colorCode)) {
                case 0:
                    std::cout << "Color: Red";
                    break;
                case 1:
                    std::cout << "Color: Green";
                    break;
                case 2:
                    std::cout << "Color: Blue";
                    break;
                case 3:
                    std::cout << "Color: Pink";
                    break;
                default:
                    std::cout << "Color: None";
                    break;

            }

        }else if(command == "square")
        {
            double length;
            std::cout << "Enter length: ";
            std::cin >> length;
            Square square(x, y, static_cast<Color>(colorCode), length);
            std::cout << "Area: " << square.area() << std::endl;
            double x1, y1, x2, y2;
            square.getBoundingBox(x1, y1, x2, y2);
            std::cout << "BoundingBox: (" << x1 << ", " << y1 << ") - (" << x2 << ", " << y2 << ")" << std::endl;

            switch (square.getColor(colorCode)) {
                case 0:
                    std::cout << "Color: Red";
                    break;
                case 1:
                    std::cout << "Color: Green";
                    break;
                case 2:
                    std::cout << "Color: Blue";
                    break;
                case 3:
                    std::cout << "Color: Pink";
                    break;
                default:
                    std::cout << "Color: None";
                    break;

            }

        }else if(command == "triangle")
        {
            double sideLength;
            std::cout << "Enter side length: ";
            std::cin >> sideLength;
            Triangle triangle(x, y, static_cast<Color>(colorCode), sideLength);
            std::cout << "Area: " << triangle.area() << std::endl;
            double x1, y1, x2, y2;
            triangle.getBoundingBox(x1, y1, x2, y2);
            std::cout << "BoundingBox: (" << x1 << ", " << y1 << ") - (" << x2 << ", " << y2 << ")" << std::endl;
            switch (triangle.getColor(colorCode)) {
                case 0:
                    std::cout << "Color: Red";
                    break;
                case 1:
                    std::cout << "Color: Green";
                    break;
                case 2:
                    std::cout << "Color: Blue";
                    break;
                case 3:
                    std::cout << "Color: Pink";
                    break;
                default:
                    std::cout << "Color: None";
                    break;

            }

        }else if(command == "rectangle")
        {
            double width, height;
            std::cout << "Enter width: ";
            std::cin >> width;
            std::cout << "Enter height: ";
            std::cin >> height;
            Rectangle rectangle(x, y, static_cast<Color>(colorCode), width, height);
            std::cout << "Area: " << rectangle.area() << std::endl;
            double x1, y1, x2, y2;
            rectangle.getBoundingBox(x1, y1, x2, y2);
            std::cout << "BoundingBox: (" << x1 << ", " << y1 << ") - (" << x2 << ", " << y2 << ")" << std::endl;

            switch (rectangle.getColor(colorCode)) {
                case 0:
                    std::cout << "Color: Red";
                    break;
                case 1:
                    std::cout << "Color: Green";
                    break;
                case 2:
                    std::cout << "Color: Blue";
                    break;
                case 3:
                    std::cout << "Color: Pink";
                    break;
                default:
                    std::cout << "Color: None";
                    break;

            }

        }else {
            std::cerr << "Unknown figure type" << std::endl;
        }


    return 0;
}
