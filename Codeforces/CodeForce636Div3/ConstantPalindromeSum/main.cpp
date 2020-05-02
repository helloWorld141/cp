//
//  main.cpp
//  ConstantPalindromeSum
//
//  Created by Kyle Nguyen on 21/4/20.
//  Copyright © 2020 Kyle Nguyen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void solve (vector<int>& a, int n, int k) {
    int m[400001];
    fill(m, m+2*k+1, 0);
    for (int i=0; i<n/2; i++) {
        m[a[i] + a[n-i-1]]++;
    }
    int maxx = 0;
    vector<int> xs;
    for (int i=0; i<2*k; i++) {
        if (m[i] > maxx){
            maxx =m[i];
        }
    }
    for (int i=0; i<2*k; i++) {
        if (m[i] == maxx){
            xs.push_back(i);
        }
    }
    int res_final = 200001;
    for (int x: xs){
        int res = 0;
        for (int i=0; i<n/2; i++) {
            int s = a[i] + a[n-i-1];
            if (s < x){
                int togrow = x - a[i] - a[n-i-1];
                if (togrow > k - min(a[i], a[n-i-1])) res+=2;
                else res++;
            } else if (s > x) {
                if (min(a[i], a[n-i-1]) < x) res++;
                else res += 2;
            }
        }
        res_final = min(res_final, res);
    }
    cout << res_final << endl;
}
int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        solve(a, n, k);
    }
}
