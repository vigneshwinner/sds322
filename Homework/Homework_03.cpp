#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

double hypotenuse(int &a, int &b);
double angA(int &a, double &hyp);
double angB(int &a, double &hyp);
void values(int a, int b, double hyp);

int main()
{
        int a = 3;
        int b = 4;
        int hyp = hypotenuse(a, b);
        values(a, b, hyp);

        return 0;
}

void values(int a, int b, double hyp)
{
        cout << "Hypotenuse: " << hypotenuse(a, b) << endl;
       cout <<  "Angle A: " << angA(a, hyp) << " degrees" << endl;
       cout << "Angle B: " << angB(a, hyp) << " degrees" << endl;
}

double hypotenuse(int &a, int &b)
{
        return sqrt(pow(a, 2) + pow(b, 2));
}

double angA(int &a, double &hyp)
{
        double angA = asin(a/hyp);
        return angA * 180 / M_PI;
}

double angB(int &a, double &hyp)
{
        double angA = acos(a/hyp);
        return angA * 180 / M_PI;
}
