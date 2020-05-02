//
//  main.cpp
//  PascalWalkOptimized
//
//  Created by Kyle Nguyen on 11/4/20.
//  Copyright © 2020 Kyle Nguyen. All rights reserved.
//

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

unsigned long mul(int start, int end) {
    unsigned long res = 1;
    while (start <= end){
        res *= start;
        start++;
    }
    return res;
}
unsigned long p (int r, int k) {
    k = (k>r/2) ? r-k: k;
    unsigned long res = 1;
    for (int i=0;i<k;i+=10) {
        res = res*mul(r-k+1 + i, min(r, r-k+1 + i+9)) / mul(1+i, min(k, 1+i+9));
    }
    return res;
}

vector<pair<int, int>> neighbors(int r, int k){
    vector<pair<int, int>> res;
    res.push_back(make_pair(r+1, k+r%2));
    if (k-1 >= 0) res.push_back(make_pair(r, k-1));
    else res.push_back(make_pair(r+1, k)); // only plus 1 to sum
    return res;
}

bool backtrack(int r, int k, unsigned long sum, vector<pair<int, int>>& steps, unsigned long target) {
    sum += p(r, k);
    if (sum > target) {
        return false;
    }
    steps.push_back(make_pair(r+1, k+1));
    if (sum == target) return true;
    for (auto p: neighbors(r, k)) {
        if (backtrack(p.first, p.second, sum, steps, target)) return true;
    }
    steps.pop_back();
    return false;
}
vector<pair<int, int>> solve(int n) {
    vector<pair<int, int>> res;
    backtrack(0, 0, 0, res, n);
    return res;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for (int test=1; test <= T; test++) {
        int n;
        cin >> n;
        vector<pair<int, int>> res = solve(n);
        printf("Case #%d:\n", test);
        for (pair<int, int> p: res){
            printf("%d %d\n", p.first, p.second);
        }
    }
    return 0;
}
// test
/*
3
1
4
19
 */
