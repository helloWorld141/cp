#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int k,g,b;
        int gi, bi;
        multiset<int> gg;
        multiset<int> bb;
        cin >> k >> g >> b;
        while (g--) {
            cin >> gi;
            gg.insert(gi);
        }
        while (b--) {
            cin >> bi;
            bb.insert(bi);
        }

        while (!gg.empty() && !bb.empty()) {
            int kk = k;
            if (gg.size() < k || bb.size() < k) kk = min(gg.size(), bb.size());
            vector<int> gv;
            vector<int> bv;
            for (int i =0; i<kk; i++) {
                if (*gg.rbegin() > *bb.rbegin()) {
                    gv.push_back(*gg.rbegin()-*bb.rbegin());
                } else
                if (*gg.rbegin() < *bb.rbegin()) {
                    bv.push_back(*bb.rbegin()-*gg.rbegin());
                }
                bb.erase(prev(bb.end()));
                gg.erase(prev(gg.end()));
            }
            bb.insert(bv.begin(), bv.end());
            gg.insert(gv.begin(), gv.end());
        }
        if (gg.empty() && bb.empty()) cout << "green and blue died" << endl;
        else if (gg.empty()) {
            cout << "blue wins" << endl;
            for (auto i=bb.rbegin(); i!= bb.rend(); i++)
                cout << *i << endl;
        }
        else if (bb.empty()) {
            cout << "green wins" << endl;
            for (auto i=gg.rbegin(); i!=gg.rend(); i++)
                cout << *i << endl;
        }
        if (n) cout << endl;
    }
    return 0;
}
/* test
3
5 1 1
10
10
2 2 3
20
10
10
10
15
3 5 5
50
40
30
40
50
50
30
30
20
60
*/
