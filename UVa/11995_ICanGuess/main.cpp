#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        bitset<3> what = 7;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        int a,b;
        while (n--){
            cin >> a >> b;
            if (a == 1 ) {
                s.push(b); q.push(b); pq.push(b);
            } else if (a ==2){
                if (s.empty() || b != s.top()) what.reset(0); else s.pop();
                if (q.empty() || b != q.front()) what.reset(1); else q.pop();
                if (pq.empty() || b != pq.top()) what.reset(2); else pq.pop();
            }
        }
        if (what.count() > 1) cout << "not sure" << endl;
        else if (what.count() == 0) cout << "impossible" << endl;
        else {
            for (int i=0; i<3; i++) if (what.test(i)) {
                switch (i){
                    case 0: cout << "stack"; break;
                    case 1: cout << "queue"; break;
                    case 2: cout << "priority queue"; break;
                }
                cout << endl;
                break;
            }
        }
    }
    return 0;
}
/*
6
1 1
1 2
1 3
2 1
2 2
2 3
6
1 1
1 2
1 3
2 3
2 2
2 1
2
1 1
2 2
4
1 2
1 1
2 1
2 2
7
1 2
1 5
1 1
1 3
2 5
1 4
2 4
*/
