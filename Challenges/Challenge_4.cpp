#include <iostream>
using std::cout;
using std::endl;

void addone(int &p1, int &p2, int &p3);

int main()
{
	int p1 = 1;
	int p2 = 2;
	int p3 = 3;

	addone(p1, p2, p3);

	return 0;
}

void addone(int &p1, int &p2, int &p3)
{
	p1++;
	p2++;
	p3++;
	
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;
	cout << "p3 = " << p3 << endl;
}
