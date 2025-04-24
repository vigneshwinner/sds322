#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class Triangle {
private:
    float sideA, sideB, sideC;
    float angA, angB, angC;

public:
    Triangle(float sideA, float sideB) {
        this->sideA = sideA;
        this->sideB = sideB;
        angC = 90;
    }

    float get_sideA() {
        return sideA;
    }

    float get_sideB() {
        return sideB;
    }

    float get_sideC() {
        return sideC;
    }

    float get_angA() {
        return angA;
    }

    float get_angB() {
        return angB;
    }

    float get_angC() {
        return angC;
    }

    void set_sideC(float hyp) {
        sideC = hyp;
    }

    void set_angA(float ang) {
        angA = ang;
    }

    void set_angB(float ang) {
        angB = ang;
    }

    float hyp(float sideA, float sideB) {
        return sqrt(pow(sideA, 2) + pow(sideB, 2));
    }

    float find_angA(float sideA, float sideC) {
        return asin(sideA / sideC) * 180 / M_PI;
    }

    float find_angB(float angA, float angC) {
        return 180. - angA - angC;
    }
};

int main() {
    Triangle triangle1(3, 4);
    Triangle triangle2(5, 12);

    triangle1.set_sideC(triangle1.hyp(triangle1.get_sideA(), triangle1.get_sideB()));
    triangle1.set_angA(triangle1.find_angA(triangle1.get_sideA(), triangle1.get_sideC()));
    triangle1.set_angB(triangle1.find_angB(triangle1.get_angA(), triangle1.get_angC()));

    cout << "Triangle 1:" << endl;
    cout << "\nHypotenuse: " << triangle1.get_sideC() << endl;
    cout << "90-degree angle: " << triangle1.get_angC() << " degrees" << endl;
    cout << "Theta 1 angle: " << triangle1.get_angA() << " degrees" << endl;
    cout << "Theta 2 angle: " << triangle1.get_angB() << " degrees" << endl;

    triangle2.set_sideC(triangle2.hyp(triangle2.get_sideA(), triangle2.get_sideB()));
    triangle2.set_angA(triangle2.find_angA(triangle2.get_sideA(), triangle2.get_sideC()));
    triangle2.set_angB(triangle2.find_angB(triangle2.get_angA(), triangle2.get_angC()));

    cout << "\n\nTriangle 2:" << endl;
    cout << "\nHypotenuse: " << triangle2.get_sideC() << endl;
    cout << "90-degree angle: " << triangle2.get_angC() << " degrees" << endl;
    cout << "Theta 1 angle: " << triangle2.get_angA() << " degrees" << endl;
    cout << "Theta 2 angle: " << triangle2.get_angB() << " degrees" << endl;

    return 0;
}
