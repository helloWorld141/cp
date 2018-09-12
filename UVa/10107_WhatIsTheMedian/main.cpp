#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a;
    unsigned int n;
    while (cin >> n) {
        a.push_back(n);
        nth_element(a.begin(), a.begin()+a.size()/2, a.end());
        int x = a[a.size()/2];
        if (a.size() % 2 == 0) {
            nth_element(a.begin(), a.begin()+a.size()/2-1, a.end());
            x = (x+a[a.size()/2-1])/2;
        }
        cout << x << endl;
    }
    return 0;
}
/* test
1
3
4
60
70
50
2
*/
