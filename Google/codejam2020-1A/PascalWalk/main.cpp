//
//  main.cpp
//  PascalWalk
//
//  Created by Kyle Nguyen on 11/4/20.
//  Copyright © 2020 Kyle Nguyen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long mul(int start, int end) {
    long res = 1;
    while (start <= end){
        res *= start;
        start++;
    }
    return res;
}
long p (int r, int k) {
    k = (k>r/2) ? r-k: k;
    return mul(r-k+1, r)/mul(1, k);
}

vector<pair<int, int>> neighbors(int r, int k){
    vector<pair<int, int>> res;
    int offsetx[] = {-1, -1, 0, 0, 1, 1};
    int offsety[] = {-1, 0, -1, 1, 0, 1};
    for (int i=0; i<6; i++) {
        pair<int, int> candidate = make_pair(r+offsetx[i], k+offsety[i]);
        if (candidate.first >= 0 && candidate.second <= candidate.first && candidate.second >= 0)
            res.push_back(candidate);
    }
    sort(res.begin(), res.end(), [](pair<int,int> a, pair<int,int> b) {
        return p(a.first, a.second) > p(b.first, b.second);
    });
    return res;
}

bool backtrack(int r, int k, long sum, vector<pair<int, int>>& steps, long target) {
    sum += p(r, k);
    if (sum > target) {
        return false;
    }
    steps.push_back(make_pair(r+1, k+1));
    if (sum == target) return true;
    for (auto p: neighbors(r, k)) {
        if (find_if(steps.begin(), steps.end(), [=](pair<int, int> e){ return p.first+1==e.first && p.second+1==e.second;} ) == steps.end())
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
