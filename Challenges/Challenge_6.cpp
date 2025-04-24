#include <iostream>
using namespace std;

int fibNonRec(int n) 
{
    if (n <= 1)
    {
        return n;
    }

    int first = 0;
    int second = 1;
    int fib = 0;
    for (int i = 2; i <= n; i++) 
    {
        fib = first + second;
        first = second;
        second = fib;
    }

    return fib;
}

int fibRec(int n) 
{
    if (n <= 1)
    {
        return n;
    }

    return fibRec(n - 1) + fibRec(n - 2);
}

int main() 
{
    int n;
    cout << "Enter value n: " << endl;
    cin >> n;
    cout << "Result for non-recursive: " << fibNonRec(n) << endl;
    cout << "Result for recursive: " << fibRec(n) << endl;

    return 0;
}
