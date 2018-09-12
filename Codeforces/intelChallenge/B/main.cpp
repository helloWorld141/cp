#include <iostream>
#include <set>
#include <string>
#include <cstdlib>
using namespace std;

set<char> vowels;
int check (string s, int a) {
    int len = s.length();
    int cnt= 0;
    for ( int i = 0; i< len; i++) {
        if (vowels.find(s[i]) != vowels.end()) cnt++;
    }
    return (cnt == a);
}
int main()
{
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
    vowels.insert('y');

    int n;
    int a[100];
    for (int i =0; i<100; i++) a[i] =0;
    string s;
    getline(cin, s);
    n = atoi(s.c_str());
    getline(cin, s);
    int cnt = 0;
    int dig;
    for (int i = 0; i<s.length(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            dig = (char)s[i] - 48;
            a[cnt] = a[cnt]*10 + dig;
        }
        if (s[i] == ' ') {
            cnt++;
        }
    }
    for (int i =0; i< n; i++) {
        getline(cin, s);
        if (!check(s, a[i])) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}
