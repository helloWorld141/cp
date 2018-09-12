#include <iostream>

using namespace std;
long a[1000000];
int main()
{
    long n;
    long t;
    cin >> n;
    for (long i =1; i<=n;i++){
        cin >>t;
        a[t] =1;
    }
    for (long i =1; i<=n; i++)
        if (a[i] == 0) cout << i<< ' ';
    return 0;
}
