#include <iostream>

using namespace std;

int main()
{
    long n;
    long a[100001];
    long long s = 0;
    long odd_min = 1000000000;
    cin >> n;
    for (long i =0; i<n; i++){
        cin >>a[i];
        s = s+a[i];
        if (a[i] < odd_min && a[i]%2==1) odd_min = a[i];
    }
    if (s%2 == 0 ) cout << s;
    else cout << s-odd_min;
    return 0;
}
