#include <bits/stdc++.h>
using namespace std;

int calAng(int h, int m) {
    //cout << h << ' ' << m << endl;
    double ha, ma;
    ma = (double)m/60;
    ha = (double)(h%12)/12 + ma/12;
    double ans = fabs(ma-ha) * 360;
    if (ans > 180) ans = 360 - ans;
    printf("%.3lf\n", ans);
    return ans;
}

int main()
{
    while(1) {
        int h = 0;
        int m = 0;
        char c;
        while(1) {
            c = getchar();
            //cout << c << endl;
            if (c <= '9' && c >= '0') h = h*10+(c-48);
            else break;
        }

        while(1) {
            c = getchar();
            //cout << c << endl;
            if (c <= '9' && c >= '0') m = m*10+(c-48);
            else break;
        }
        if (h != 0 || m != 0) calAng(h,m);
        else break;
    }
    return 0;
}
