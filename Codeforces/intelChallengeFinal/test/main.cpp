#include <iostream>
#define for(i,from, to) for (int i =from; i<to; i++)
using namespace std;



int main()
{
    int a[5] = {1,2,3,4,5};
    for(i, 0, 5) cout << a[i] << ' ';
    int b[5];
    copy(a, a+5, b);
    b[1] = 10000;
    for(i, 0, 5) cout << b[i] << ' ';
    return 0;
}
