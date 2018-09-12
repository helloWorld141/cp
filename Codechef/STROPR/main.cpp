#include <iostream>
#include <cstdio>

#define mod 1000000007
using namespace std;

unsigned long a[100001];
int t;
long n;
long x;
unsigned long m;

unsigned long cal(long x, unsigned long m){
    for (long i =1; i<=x; i++){
        a[i] =( a[i]*(1+ ((m-1)%mod)*(n-i) ))%mod;
        a[i] = (a[i] + a[i-1])%mod;
    }
    return a[x];
}

int main()
{
    scanf("%d", &t);
    for (int i =1; i<=t; i++){
        scanf("%ld %ld %ld", &n, &x, &m);
        a[0] = 0;
        for (int i=1; i<=n; i++) scanf("%ld", &a[i]);
        printf("%ld\n", cal(x,m));
    }
    return 0;
}
