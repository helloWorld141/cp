#include <bits/stdc++.h>

using namespace std;

string det(int x, int y) {
    if (x*y == 0) return "divisa";
    if (x*y > 0)
        if (x > 0) return "NE";
        else return "SO";
    else
        if (x>0) return "SE";
        else return "NO";
}

int main()
{
    int k;
    while (scanf("%d", &k), (k||0)) {
        int n,m;
        cin>>n>>m;
        while (k--) {
            int x,y;
            cin>>x>>y;
            x-=n;y-=m;
            cout<<det(x,y)<<endl;
        }
    }
    return 0;
}
