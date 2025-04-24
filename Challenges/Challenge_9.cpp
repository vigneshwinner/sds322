#include <iostream> 
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<int> combineV(vector<int> &a, vector<int> &b)
{
	vector<int> c = a;
	for (int i: b)
	{
		c.push_back(i);
		a.pop_back();
		b.pop_back();
	}

	return c;
} 

void printVector(vector<int> a)
{
	for (int i: a)
	{
		cout << i << " ";
	}
}

int main()
{
	vector<int> a, b;

	for (int i = 1; i <= 25; i++)
	{
		a.push_back(i);
		b.push_back(i * 2);
	}

	vector<int> c = combineV(a, b);
	cout << "Combined Vector: " << endl;
	printVector(c);
}
