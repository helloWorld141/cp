#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >>t;
    for (int j =1; j <= t; j++){
        int a[3];
        int i=3;
        while (i--) cin>>a[i];
        sort(a,a+3);
        cout << "Case " << j << ": " << a[1] << endl;
    }
    return 0;
}
