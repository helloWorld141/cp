//
//  main.cpp
//  AlternatingSubsequence
//
//  Created by Kyle Nguyen on 22/4/20.
//  Copyright © 2020 Kyle Nguyen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve (vector<int64_t>& a, int n) {
    int64_t cur_sign = a[0];
    vector<int> mark;
    for (int i=1; i<n; i++) {
        if (cur_sign * a[i] < 0) {
            mark.push_back(i);
            cur_sign = a[i];
        }
    }
    mark.push_back(n);
    int64_t res = 0;
    int l = 0;
    for (int r: mark){
        res += *max_element(a.begin()+l, a.begin()+r);
        l = r;
    }
    cout << res << endl;
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        solve(a, n);
    }
}
