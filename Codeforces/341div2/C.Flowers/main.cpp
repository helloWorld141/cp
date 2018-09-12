#include <iostream>
#include <cstdio>

#define ff first
#define ss second
using namespace std;

long n ,p;
pair<long, long> a[100000];

void read(){
    freopen("test.txt","r",stdin);
    long x,y;
    cin >>n >>p;
    for (long i = 0 ; i<n; i++){
        cin >> x >>y;
        a[i] = make_pair(x,y);
    }
    fclose(stdin);
}

double prop(long i){
    long x = a[i].ss -a[i].ff +1;
    long y = a[(i+1)%n].ss - a[(i+1)%n].ff +1;
    long d1 = a[i].ss/p - (a[i].ff-1)/p;
    long d2 = a[(i+1)%n].ss/p - (a[(i+1)%n].ff-1)/p;
    long long b = d1*y + d2*x - d1*d2;
    long long c = x*y;
    double res = (double)b/c;
    return(res);
}
int main()
{
    read();
    double ans = 0.0;
    for (long i = 0; i<n; i++){
        ans += prop(i);
    }
    //ans *= 2000;
    //printf("%lf", ans);
    cout << ans*2000 << endl;
    printf("%lf", 1.2345678901);
    return 0;
}
