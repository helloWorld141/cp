#include <iostream>
#include <string>
#include <math.h>

#define pb push_back
using namespace std;
    long n;
void slime(long i){
    if (i==1) {cout << 1; return;}
    if (i==2) {cout << 2; return;}
    long x = (long)log2(i);
    long y = (long)pow(2,(double)x);
    cout << x+1 << ' ';
    if (i%y != 0) slime(i%y);
}

int main()
{

    cin >> n;
    slime(n);
    return 0;
}
