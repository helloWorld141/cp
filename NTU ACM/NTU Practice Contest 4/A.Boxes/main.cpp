#include <iostream>
#include <cstdio>

using namespace std;
int m;
int n;
int a[1000][1000];

void read(){
    scanf("%d %d", &m, &n);
    for (int i=0; i<m; i++)
    for (int j=0; j<n; j++){
        scanf("%d", &a[i][j]);
    }
}

long dem(int x){
    long ans =0;
    long cnt =0;
    for (int i=m-1; i>=0; i--){
        if (a[i][x] == 0) cnt++;
        else if (a[i][x] == 1) ans += cnt;
    }
    return ans;
}

void solve(){
    long res =0;
    for (int i =0; i<n; i++) res += dem(i);
    printf("%ld\n", res);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i =0; i<t; i++){
        read();
        solve();
    }
    return 0;
}
