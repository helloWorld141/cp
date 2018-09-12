#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long k = floor((sqrt(1+8*n)-1)/2);
    long long ans = n - (k+1)*k/2;
    if (ans != 0) cout << ans;
    else cout <<k;
    return 0;
}
