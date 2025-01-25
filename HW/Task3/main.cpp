#include <iostream>
#include <vector>


struct Point { // Незнаю почему, но так удобнее
    int x;
    int y;
};


class Window {
private:
    Point p; // Координаты верхнего левого угла
    int width, height; // Ширина и высота окна

public:
    Window(Point p, int width, int height){
        this->width = width;
        this->height = height;
        this->p = p;
        std::cout << "Window created at (" << p.x << ", " << p.y << "), width: " << width << ", height: " << height << std::endl;

        if (width < 0 || height < 0) {
            std::cerr << "Width and height must be non-negative." << std::endl;
        }
    }

    void move(Point moved) {
        p = moved;

        if (p.x < 0) p.x = 0;
        if (p.y < 0) p.y = 0;
        if (p.x + width > 80) p.x = 80 - width;
        if (p.y + height > 50) p.y = 50 - height;
    }

    void resize(int newWidth, int newHeight) {
        if (newWidth < 0 || newHeight < 0) {
            std::cerr << "Width and height must be non-negative.";
        }
        width = newWidth;
        height = newHeight;

        if (p.x + width > 80) width = 80 - p.x;
        if (p.y + height > 50) height = 50 - p.y;
    }


    int getX() {
        return p.x;
    }
    int getY() {
        return p.y;
    }
    int getWidth() {
        return width;
    }
    int getHeight() {
        return height;
    }
};

class Screen {
private:
    int width, height;
    Window* window;

public:
    Screen(int width, int height) : width(width), height(height), window(nullptr) {}

    void setWindow(Window* w) {
        window = w;
    }

    void display(){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (window && j >= window->getX() && j < window->getX() + window->getWidth() &&
                    i >= window->getY() && i < window->getY() + window->getHeight()) {
                    std::cout << "1";
                } else {
                    std::cout << "0";
                }
            }
            std::cout << "\n";
        }
    }
};

int main() {
    Screen screen(80, 50);

    Point point1(10, 10);

    Window window(point1, 20, 15);
    screen.setWindow(&window);

    std::string command;
    while (true) {
        std::cout << "Enter command (move, resize, display, close): ";
        std::cin >> command;

        if (command == "move") {
            Point point2;
            std::cout << "Enter dx and dy: ";
            std::cin >> point2.x >> point2.y;
            window.move(point2);

        } else if (command == "resize") {
            int newWidth, newHeight;
            std::cout << "Enter new width and height: ";
            std::cin >> newWidth >> newHeight;
            window.resize(newWidth, newHeight);

        } else if (command == "display") {
            screen.display();

        } else if (command == "close") {
            break;

        } else {
            std::cout << "Unknown command.\n";
        }
    }

    return 0;
}