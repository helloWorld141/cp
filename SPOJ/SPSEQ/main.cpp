#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>

#define pb push_back
using namespace std;

int binarySearch(vector<long> a, vector<long> h, long x, long l, long r){
    if (l+1 == r) return l;
    long mid = (l+r)/2;

    if (a[h[mid]] == x) return mid;
    if (a[h[mid]] >x ) return binarySearch(a,h,x,l,mid);
    else return binarySearch(a,h,x,mid,r);
}

vector<long> LIS(vector<long> a,long n){

    vector<long> h(n+1);
    vector<long> f(n+1);

    ///initialize
    f[0] = 0; f[1] = 1;
    for (long i = 2; i<=n; i++){
        h[i] = n+1;
        f[i] = 0;
    }
    h[0] = 0; h[1] = 1;
    long res = 1;
    long j =0;
    long d = 0;
    ///
    for (long i =2; i<=n; i++){
        d = binarySearch(a,h,a[i],0,res+1);
        j = h[d];
        if (j == 0) {
            f[i] = 1;
            h[1] = i;
        }
        else if (h[d+1] == n+1) {
            res++;
            f[i] = d + 1 ;// = f[j] +1
            h[res] = i;
        }
        else if (a[j] == a[i]){
            f[i] =f[j];
        }
        else {
            f[i] = d + 1;
            if (a[i] < a[h[d+1]]) h[d+1] = i;
        }
    }
    return f;
}

int main()
{
    long n;
    scanf("%ld", &n);
    vector<long> a(n+2);
    vector<long> b(n+2);
    for (int i = 1; i<=n; i++){
        scanf("%ld", &a[i]);
        b[n-i+1] = a[i];
    }
    a[0] = LONG_MIN; a[n+1] = LONG_MAX;
    b[0] = LONG_MIN; b[n+1] = LONG_MAX;

    vector<long> fa(n+1); vector<long> fb(n+1);
    fa = LIS(a, n);
    fb = LIS(b, n);

    long maxx = 0;
    long l = 0;
    for (long i=1; i<=n; i++){
        //cout << fa[i]<< ' '<< fb[i]<< endl;
        l = 2*min(fa[i], fb[n-i+1]) -1;
        if (l>maxx) maxx = l;
    }

    printf("%ld", maxx);
    return 0;
}
