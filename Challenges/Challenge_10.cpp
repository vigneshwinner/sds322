#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using std::cout;
using std::endl;
using std::vector;
using std::sort;

vector<int> random_vector(int len)
{
	srand(time(NULL));
	int num = 0;
	vector<int> arr;
	for (int i = 0; i < len; i++)
	{
		num = (rand() % 100) + 1;
		arr.push_back(num);
	}
	
	return arr; 
}

void sort_it(vector<int> &arr)
{	
	sort(arr.begin(), arr.end());
}

void display_vector(vector<int> arr)
{
	for (int i: arr)
	{
		cout << i << " ";
	}
}

int main()
{
	int length = 10;
	vector<int> values = random_vector(length);
	sort_it(values);
	display_vector(values);
}
