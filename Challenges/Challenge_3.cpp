#include <iostream>
#include <time.h>
using std::cout;
using std::endl;
int main () {
        srand (time(NULL));
        int heads, tails = 0;
       	while (tails < 1000) {
                int random_number = rand();
                if (random_number%2 == 0) {
                        heads++;
                }
                else {
                        tails++;
                }
        }
        cout << "Number of heads: " << heads << endl;

        cout << "Number of tails: " << tails << endl;
}
