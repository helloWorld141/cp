#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;
int c,n,m;
double aa,bb;
struct p {
    double x,y, v;
    string c;
};
struct p a[100];
double dis2(double x1, double y1, double x2, double y2) {
    return ((double)(x2-x1)*(double)(x2-x1) + (double)(y2-y1)*(double)(y2-y1));
}

int compare(double a, double b) {
    if (fabs(a-b) < 0.0001) return -1;
    if (a-b > 0) return 1;
    return -1;
}

int main()
{
    cin >> c;
    for (int i=0; i<c; i++) {
        cin >> n;
        for (int j=0; j<n; j++) {
            cin >> a[j].x >> a[j].y >> a[j].v >> a[j].c;
        }

        cin >> m;

        for (int i=0; i<m; i++) {
            cin >> aa >> bb;
            int k;
            for (k=n-1; k>=0; k--) {
                double dis = dis2(a[k].x, a[k].y, aa, bb);
                //cout << (double)dis << endl;
                //printf("%.6f\n", a[k].v/PI);
                if (compare(dis*PI, (a[k].v)) == -1) {
                    cout << a[k].c << endl;
                    break;
                }
            }

            if(k==-1) cout << "white" << endl;
        }
    }

    return 0;
}
