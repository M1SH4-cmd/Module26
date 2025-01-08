#include <iostream>
using namespace std;

struct Robot {
    int health;
    int damage;
    int speed;

    void take_damage() {
        cout << "Damaged: " << health << endl;
    }

    void move() {
        cout << "Moving: " << speed << endl;
    }

    void attack() {
        cout << "Dealed damage: " << damage << endl;
    }
};


int main() {

    Robot* r2d2 = new Robot {100, 50, 10};

    r2d2->move();
    delete r2d2;

    return 0;
}