#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        if (n == 0) break;
        priority_queue<int> q;
        int a,b,cost=0;
        while(n--) {
            cin >>a;
            q.push(-a);
        }
        while (q.size() > 1) {
            a=abs(q.top()); q.pop();
            b=abs(q.top()); q.pop();
            cost+=(a+b);
            q.push(-a-b);
        }
    cout<<cost<<endl;
    }
    return 0;
}
/*test
3
1 2 3
4
1 2 3 4
0
*/
