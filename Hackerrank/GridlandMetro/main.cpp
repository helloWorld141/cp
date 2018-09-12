#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define MAX 1000000001

using namespace std;
class train {
public:
    ll row, l, r;
    train(){};
    train(ll a, ll b, ll c){row = a; l = b; r=c;}
};

int cal(train t[], int n){
    if (n==0) return 0;
    pair<ll,int> a[2000];
    int b[2000];
    int pos[2000];
    int m =0;
    fill_n(b,2000,0);
    for (int i=0; i<n; i++) {
        a[2*i].ff = t[i].l; a[2*i].ss = 0;
        a[2*i+1].ff = t[i].r+1; a[2*i+1].ss = 1;
    }
    n*=2;
    sort(a, a+n);
    b[0]=1; pos[0]=0;
    int flag = 1;
    for (int i=1; i<n; i++){
        if (a[i].ss == 0) b[i] = b[i-1]+1;
        else b[i]=b[i-1]-1;

        if (flag && b[i]==0) {pos[++m]=i; flag = 1-flag;}
        else if (!flag && b[i]==1) {pos[++m] = i; flag = 1-flag;}
    }
    ll ans=0;
    for (int i =0; i<=m/2; i++) {
        int r = pos[2*i+1];
        int l = pos[2*i];
        ans+=(a[r].ff - a[l].ff);
    }
    return ans;
}

bool compareTrain(train a, train b) {
    return a.row < b.row;
}
int main()
{
    ll n,m;
    int k;
    train a[1000];
    cin >> n>> m>>k;
    for (int i=0;i<k;i++) {
        ll x,y,z;
        cin>>x>>y>>z;
        a[i]=train(x,y,z);
    }
    sort(a, a+k, compareTrain);
    ll ans =0;
    ll curRow = 1;
    ll l=0; ll r =-1;
    a[k].row = MAX;
    for (int i=0; i<=k; i++) {
        if (curRow != a[i].row) {ans+=cal(a+l, r-l+1); l=i; r=i; curRow = a[i].row;}
        else {r = i;}
    }

    cout << n*m-ans;
    return 0;
}
