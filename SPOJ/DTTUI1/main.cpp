#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <math.h>

#define pb push_back
#define N 1100000
#define sog sizeof(gold)
using namespace std;

struct gold{
    long long v;
    long long w;

    gold(long long x, long long y){
        v = x; w = y;
    }

    gold(){
        v =0; w=0;
    }
};

int n;
gold a[40];
long cnt ;
long long m;

long binarySearch(gold * a, long long x, long l, long r){
    if (x < a[l].w) return -1;
    if (x >= a[r].w) return r;
    if (x == a[l].w) return l;
    if (l+1 == r) return l;
    long mid = (l+r)/2;
    if (a[mid].w == x) return mid;
    if (a[mid].w > x) return binarySearch(a,x,l,mid);
    else return binarySearch(a,x,mid,r);
}

void tong(gold * ai, long l, long r, long long val, long long weight){
    if (weight > m) return;
    if (l > r) {
        (ai+cnt) ->v = val;
        (ai+cnt) ->w = weight;
        //cout << ai+cnt << ' '<< ai[cnt].v << ' '<< ai[cnt].w << endl;
        cnt++;
        return;
    }

    tong(ai, l+1, r,val, weight);
    tong(ai, l+1, r, val+a[l].v, weight+a[l].w);

}

bool cmp(const gold &x, const gold &y){
    return (x.w<=y.w);
}

void duyetBangCachChiaDoiTapHop(){
    long n2 = pow(2,n/2);
    long n1 = n2;
    gold * a2 = new gold[n2];
    if (n%2 != 0) n1 = n2*2;
    gold * a1 = new gold[n1];
    vector<long long> f;

    long long ans = 0;
    long j;
    //cout << "tap 1" << endl;
    cnt = 0;
    tong(a1, 0, n/2, 0, 0);
    n1 = cnt;
    //cout << "tap 2" << endl;
    cnt = 0;
    tong(a2, n/2+1, n-1, 0, 0);
    n2 = cnt;

    sort(a2, a2+n2, cmp);

    f.pb(a2[0].v);
    long long maxx = a2[0].v;
    for (long i =1; i< n2; i++){
        if (a2[i].v > maxx) maxx = a2[i].v;
        f.pb(maxx);
    }

    for (long i = 0; i < n1; i++){
        j = binarySearch(a2, m-a1[i].w, 0, n2-1);
        if (j != -1) {
            maxx = a1[i].v + f[j];
            if (maxx > ans) ans = maxx;
        }
    }

    printf("%I64d", ans);
}

int main()
{
    scanf("%d %I64d", &n, &m);
    for (int i =0; i<n; i++){
        scanf("%I64d %I64d ", &a[i].w, &a[i].v);
    }
    duyetBangCachChiaDoiTapHop();
    return 0;
}
