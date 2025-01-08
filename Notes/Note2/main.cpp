#include <iostream>
using namespace std;

class PlaneControl { //bool imba = C < C++;
    double leftAileron = 0;
    double rightAileron = 0;
    double elevator = 0;

    public:
        void turnLeft() {
            leftAileron -= 30;
            rightAileron += 30;
        }

        void turnRight() {
            leftAileron += 30;
            rightAileron -= 30;
        }

        void setElevator(double value) {
            if (value < -30) value = -30;
            if (value > 30) value = 30;
            if (value == elevator) return;
            elevator = value;
        }

        double getLeftAileron() {
            return leftAileron;
        }

        double getRightAileron() {
            return rightAileron;
        }

        double getElevator()  {
            return elevator;
        }

        static void showInfo(PlaneControl* planeControl) {
            cout << "Left Aileron: " << planeControl->leftAileron << endl;
            cout << "Right Aileron: " << planeControl->rightAileron << endl;
            cout << "Elevator: " << planeControl->elevator << endl;
        }

};

int main() {
    PlaneControl* planeControl = new PlaneControl();
    planeControl->turnLeft();
    planeControl->setElevator(10);
    PlaneControl::showInfo(planeControl);
    delete planeControl; // Never forget to delete all the obj's from memory
    planeControl = nullptr; // Also don't forget to "null" all the obj's
    return 0;
}