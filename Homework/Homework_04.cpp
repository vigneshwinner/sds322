#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

struct Triangle
{
	float sideA, sideB, sideC;
	float angleA, angleB, angleC;
};

void values(Triangle& triangle) 
{
	triangle.sideC = sqrt(pow(triangle.sideA, 2) + pow(triangle.sideB, 2));
	triangle.angleC = 90;
	triangle.angleA = asin(triangle.sideA / triangle.sideC) * 180.0 / M_PI;
	triangle.angleB = 180.0 - triangle.angleA - triangle.angleC;
}

int main() 
{
    Triangle triangle1, triangle2;

    triangle1.sideA = 3;
    triangle1.sideB = 4;
    values(triangle1);

    triangle2.sideA = 5;
    triangle2.sideB = 12;
    values(triangle2);

    cout << "Triangle 1:" << endl;
    cout << "\nHypotenuse: " << triangle1.sideC << endl;
    cout << "90-degree angle: " << triangle1.angleC << " degrees" << endl;
    cout << "Theta 1 angle: " << triangle1.angleA << " degrees" << endl;
    cout << "Theta 2 angle: " << triangle1.angleB << " degrees" << endl;

    
    cout << "\n\nTriangle 2:" << endl;
    cout << "\nHypotenuse: " << triangle2.sideC << endl;
    cout << "90-degree angle: " << triangle2.angleC << " degrees" << endl;
    cout << "Theta 1 angle: " << triangle2.angleA << " degrees" << endl;
    cout << "Theta 2 angle: " << triangle2.angleB << " degrees" << endl;

    return 0;
}
