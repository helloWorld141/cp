#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int a[101];
    string pass;
    for (int i = 0; i< n; i++) {
        cin >> pass;
        a[i] = pass.length();
    }
    a[n] = 101;
    cin >> pass;
    int len = pass.length();

    sort(a, a+n);
    int first = 0;
    int last = 0;
    for (int i =0; i<n; i++) {
        if (a[i] == len) {
            first = i+1;
            break;
        }
    }

    for (int i =0; i<=n; i++) {
        if (a[i] > len) {
            last = i;
            break;
        }
    }

    int best = first + 5*((first-1)/k);
    int worst = last + 5*((last-1)/k);

    cout << best << ' ' << worst;
    return 0;
}
