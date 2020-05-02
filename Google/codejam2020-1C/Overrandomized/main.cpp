//
//  main.cpp
//  Overrandomized
//
//  Created by Kyle Nguyen on 2/5/20.
//  Copyright © 2020 Kyle Nguyen. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int U){
    unordered_map<char, int> lim;
    string m;
    string r;
    unordered_set<char> no;
    for (int i=0; i<10000; i++) {
        cin >> m >> r;
        if (u) {
            if (m.size() == r.size()) {
                for (int j=0; j<r.size(); j++) {
                    if (lim.find(r[j]) == lim.end()) lim[r[j]] = 9;
                    if (j==0) {
                        lim[r[j]] = min(lim[r[j]], (m[j] - '0'));
                        no.insert(r[j]);
                    }
                }
                
            }
        }
    }
    vector<pair<int, char>> a;
    for (auto& p: lim){
        a.push_back(make_pair(p.second, p.first));
    }
    sort(a.begin(), a.end());
    char res[10];
    // for (auto& p: a) {
    //     cout << p.first << ' ' << p.second << endl;
    // }
    for (int i=0; i<a.size(); i++) {
        int second = a[i].second;
        if (no.find(second) == no.end()) {
            res[0] = second;
            a.erase(a.begin() + i);
            break;
        }
    }
    for (int i=1; i<10; i++) {
        res[i] = a[i-1].second;
    }
    printf("%s\n", res);
}
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        int U;
        cin >> U;
        printf("Case #%d: ", t);
        solve(U);
    }
}
