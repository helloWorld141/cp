// basics of dynamic programming
//tim con tang dai nhat
// ELIS spoj, LIQ vn.spoj thay doi gioi han bien
// LIS vn.spoj

#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>

#define pb push_back

using namespace std;

vector<long> h; // luu vi tri cuoi cung cua day con tang co do dai i, sao cho a[h[i]] be nhat
vector<long> a;
vector<long> f; // do dai day con tang dai nhat ket thuc o i
long res; // so phan tu hien tai co trong h
long n;

void read(){
    long t;
    scanf("%ld", &n);
    a.pb(LONG_MIN);
    h.pb(0);
    f.pb(0);
    res = 0;

    for (int i =1; i<=n; i++){
        scanf("%ld", &t);
        a.pb(t);
        h.pb(n+1);
        f.pb(0);
    }
    a.pb(LONG_MAX);
}

int binarySearch(long x, long left, long right){
    if (left+1 == right) return left;
    long mid = (left + right)/2;
    if (x == a[h[mid]]) return mid;
    if (x > a[h[mid]]) return binarySearch(x, mid, right);
    else return binarySearch(x, left, mid);
}

int main()
{
    long d=0;
    long j=0;
    read();
    h[1] = 1;
    f[1] =1 ;
    res = 1;

    for (long i = 2; i<=n; i++){
        d = binarySearch(a[i],0,res+1);
        if (h[d] == 0) {
            h[1] = i;
            f[i] = 1;
        }
        else {
            j=h[d];
            if (a[i] > a[j]){
                f[i] = d+1;
                if (h[d+1]==n+1) res++;
                if (a[h[d+1]] > a[i])
                    h[d+1] = i;
            }
            else f[i] = f[j];
        }
    }
    printf("%ld", res);
    return 0;
}
