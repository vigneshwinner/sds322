#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	double a = 3;
	double b = 4;
	//cout << "Enter side a: " << endl;
	//cin >> a;
	//cout << "Enter side b: " << endl;
	//cin >> b;

	double hyp = sqrt(pow(a, 2) + pow(b, 2));
	double angA = acos(b / hyp) * 180 / M_PI;
	double angB = asin(b / hyp) * 180 / M_PI;

	cout << "The hypotenuse is: " << hyp << endl;
	cout << "Angle A is: " << angA << " degrees" << endl;
	cout << "Angle B is: " << angB << " degrees" << endl; 	
}
