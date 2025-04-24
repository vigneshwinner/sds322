#include <iostream>
using std::cout;
using std::endl;

int swapper(int &i, int &j);

int main()
{
	int i = 5;
	int j = 3;
	cout << "i:" << i << " j:" << j << endl;
	swapper(i, j);
	cout << "i:" << i << " j:" << j << endl;

	return 0;
}

int swapper(int &i, int &j)
{
	int temp = i;
	i = j;
	j = temp;

	return 0;
}
