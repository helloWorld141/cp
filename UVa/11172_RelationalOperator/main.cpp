#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        long long a, b;
        cin >> a >> b;
        char ans = (a==b)? '=' : (a>b)? '>':'<';
        cout << ans << endl;
    }
    return 0;
}
