#include <bits/stdc++.h>

using namespace std;
// xai thu next_permutation in <algorithm>
int main()
{
    string s;
    getline(cin,s);
    while (s.compare("#") != 0) {
        if (next_permutation(s.begin(), s.end())) cout << s << endl;
        else cout << "No Successor" << endl;
        getline(cin,s);
    }
    return 0;
}

/* test
abaacb
cbbaa
#
*/
