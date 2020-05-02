//
//  main.cpp
//  BalancedArray
//
//  Created by Kyle Nguyen on 21/4/20.
//  Copyright © 2020 Kyle Nguyen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void solve(int n){
    if (n % 4 != 0) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        vector<int> a;
        for (int i=2; i<=n; i+=2) a.push_back(i);
        for (int i=1; i<=n-3; i+=2) a.push_back(i);
        a.push_back(n + n/2 - 1);
        string res = "";
        for (int i=0; i<a.size()-1; i++) res += (to_string(a[i]) + ' ') ;
        res += to_string(a.back());
        cout << res << endl;
    }
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    for (int test=1; test <= t; test++) {
        int n;
        cin >> n;
        solve(n);
    }
}
