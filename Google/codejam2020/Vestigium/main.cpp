//
//  main.cpp
//  Vestigium
//
//  Created by Kyle Nguyen on 5/4/20.
//  Copyright © 2020 Kyle Nguyen. All rights reserved.
//

#include <iostream>
#include <vector>

#define vvi vector<vector<int>>

using namespace std;

bool hasDuplicate(vector<int> a) { // a only contains numbers from 1 to n
    int n = (int)a.size();
    for (int i=0; i<n; i++) {
        int next = abs(a[i])-1;
        if (a[next] > 0) { // havent met
            a[next] = -a[next];
        } else { // meet again !!!
            return true;
        }
    }
    return false;
}

vector<int> solve(vvi& m) {
    vector<int> res = {0, 0, 0};
    int n = (int) m.size();
    for (int i=0; i<n; i++) res[0] += m[i][i];
    
    for (auto& row: m) if (hasDuplicate(row)) res[1]++;
    
    for (int col=0; col<n; col++) {
        vector<int> temp(n);
        for (int row=0; row<n; row++) temp[row] = m[row][col];
        if (hasDuplicate(temp)) res[2]++;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for (int test=0; test < T; test++) {
        int n;
        cin >> n;
        vvi m(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) cin >> m[i][j];
        }
        
        vector<int> res = solve(m);
        
        printf("Case #%d: %d %d %d\n", test+1, res[0], res[1], res[2]);
    }
    return 0;
}
// test cases
/*
3
4
1 2 3 4
2 1 4 3
3 4 1 2
4 3 2 1
4
2 2 2 2
2 3 2 3
2 2 2 3
2 2 2 2
3
2 1 3
1 3 2
1 2 3
 */
