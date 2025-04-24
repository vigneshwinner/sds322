#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

double hypotenuse(int a, int b);
double angA(int a, double hyp);
double angB(int a, double hyp);

int main()
{
	int a = 3;
	int b = 4;
	int hyp = hypotenuse(a, b);
	cout << "Hypotenuse is: " << hyp << endl;
	cout << "Angle A is: " << angA(a, hyp) << " degrees" << endl;
	cout << "Angle B is: " << angB(a, hyp) << " degrees" << endl;

	return 0;
}

double hypotenuse(int a, int b)
{
	return sqrt(pow(a, 2) + pow(b, 2));
}

double angA(int a, double hyp)
{
	double angA = asin(a/hyp);
	return angA * 180 / M_PI;
}

double angB(int a, double hyp)
{
        double angA = acos(a/hyp);
        return angA * 180 / M_PI;
}
