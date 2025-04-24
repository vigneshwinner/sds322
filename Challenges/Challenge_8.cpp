#include <iostream>
#include <random>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	srand(time(NULL));
	vector<int> arr;
	int num = 0;

	while (num != 42)
	{
		num = (rand() % 100) + 1;
		arr.push_back(num);
	}

	cout << "Array size: " << arr.size() << endl;

	return 0;
}
