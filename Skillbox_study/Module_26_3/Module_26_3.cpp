#include <iostream>
#include <vector>

class Window {
private:
    int x, y, width, height;

public:
    Window(int x, int y, int width, int height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    void move(std::vector<int> vector) { //Перемещение окна
        x += vector[0];
        y += vector[1];

        if (y < 1 || y > 49 || x < 1 || x > 79) //Условие контроля границы
        {
            std::cerr << "The Y and X coordinate has gone beyond the boundary, the return to the original position.\n";
            vector.clear();
            x = 1;
            y = 1;
        }
        std::cout << "Window moved to (" << x << ", " << y << ")" << std::endl;
    }

    void resize(int width, int height) { //Значения размера окна
        this->width = width;
        this->height = height;
        std::cout << "Window resized to " << width << "x" << height << std::endl;
    }

    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    int getWidth(){
        return width;
    }
    int getHeight(){
        return height;
    }

};

class Screen
{
private:
    int x = 0, y = 0, width = 0, height = 0;

public:

    Screen(Window &window) {
        this -> x = window.getX();
        this -> y = window.getY();
        this -> width = window.getWidth();
        this -> height = window.getHeight();
    }

    void display() { //Визуализация рабочего стола
        std::cout << "Window Display:" << std::endl;
        for (int i = 0; i < 80; i++) {
            for (int j = 0; j < 50; j++) {
                if (i >= x && i < x + width && j >= y && j < y + height) {
                    std::cout << " ";
                } else {
                    std::cout << "-";
                }
            }
            std::cout << std::endl;
        }
    }

    void close() {
        std::cout << "Window closed" << std::endl;
        exit(0);
    }

};


int main() {

    Window window(10, 10, 20, 20);

    std::string command;
    while (true) {
        std::cout << "> ";
        std::cin >> command;

        if (command == "move") {
            int x, y;
            std::cin >> x >> y;
            std::vector<int> vector = {x, y};
            window.move(vector);
        } else if (command == "resize") {
            int width, height;
            std::cin >> width >> height;
            if(width < 0 || height < 0){ // Условие отрицательного ввода
                std::cerr << "Negative input\n";
                break;
            }
            window.resize(width, height);
        } else if (command == "display") {
            Screen screen(window);
            screen.display();
        } else if (command == "close") {
            Screen screen(window);
            screen.close();
        }
    }


    return 0;
}