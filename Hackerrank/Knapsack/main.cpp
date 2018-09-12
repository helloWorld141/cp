#include <iostream>

using namespace std;
int a[2001];
int dp[2001][2001];
const int oo = 1000000;
int knapsack(int k, int q){
    if (dp[k][q] != oo) return dp[k][q];
    else {
        if (a[k-1] > q)
            return dp[k][q] = knapsack(k-1,q);
        else {
            int temp = max(knapsack(k-1, q), knapsack(k-1, q-a[k-1])+a[k-1]);
            int j=2;
            while (j*a[k-1] <= q){
                temp= max(temp, knapsack(k-1, q-j*a[k-1])+j*a[k-1]);
                j++;
            }
            return temp;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n;
        cin >> m;
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        for (int i=1;i<n+1;i++){
            fill_n(dp[i], m+1, oo);
        }
        fill_n(dp[0], m+1, 0);
        cout << knapsack(n,m) << endl;
    }



    return 0;
}
