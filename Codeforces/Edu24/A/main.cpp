#include <iostream>

using namespace std;

int main()
{
    long long n,k;
    cin >> n >> k;
    long long a = (long long)n/(2*(k+1));
    if (a == 0) {
        cout << 0 << ' ' << 0 << ' ' << n;
    } else {
        cout << a << ' ' << k*a << ' ' << n-a-a*k;
    }
    return 0;
}
