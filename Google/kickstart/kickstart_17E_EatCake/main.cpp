#include <iostream>
#include <climits>
#include <cstring>
#include <fstream>
using namespace std;


int n;

long dp[10010];

long solve(int n){
    if (n <= 0) return 0;
    if (dp[n] != -1) return dp[n];
    long res = 1000000;
    for (int i= 1; i*i<=n; i++){
        res = min(res, 1+solve(n-i*i));
    }
    return dp[n] = res;
}

int main()
{
    int t;
    ifstream in;
    ofstream out;
    //in.open("D-small-attempt0.in");
    //out.open("D-small-attempt0.out");
    in.open("D-large.in");
    out.open("D-large.out");
    in >> t;
    for (int i =0; i<t; i++){
        in >> n;
        memset(dp, -1, sizeof(dp));
        long long res = solve(n);
        cout << "Case #" << i+1 << ": " << res << endl;
        out << "Case #" << i+1 << ": " << res << endl;

    }
    in.close();
    out.close();
    return 0;
}
