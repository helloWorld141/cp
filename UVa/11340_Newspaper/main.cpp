#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i =0; i<n ;i++) {
        int k;
        char c;
        map<char, int> p;
        cin >> k;
        while (k--) {
            cin >>c;
            cin >> p[c];
        }
        int m;
        cin >> m;
        int ans =0;
        map<char,int>::iterator it = p.begin();
        string s;
        getline(cin,s);
        while(m--) {
            getline(cin, s);
            for (unsigned int j=0; j<s.size(); j++){
                if (p.find(s[j]) != p.end()){
                    //cout << s[j] << ' '<<p[s[j]] << endl;
                    ans+=p[s[j]];
                }
            }
        }
        string ass = to_string(ans/100);
        ass.insert(ass.end(), '.');
        if (ans%100 <10) ass.insert(ass.end(), '0');
        cout << ass+to_string(ans%100)+"$" << endl;
    }

    return 0;
}

/* test
1
7
a 3
W 10
A 100
, 10
k 7
. 3
I 13
7
ACM International Collegiate Programming Contest (abbreviated
as ACM-ICPC or just ICPC) is an annual multi-tiered competition
among the universities of the world. The ICPC challenges students
to set ever higher standards of excellence for themselves
through competition that rewards team work, problem analysis,
and rapid software development.
From Wikipedia.
*/
