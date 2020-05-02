//
//  main.cpp
//  OverexcitedFan
//
//  Created by Kyle Nguyen on 2/5/20.
//  Copyright © 2020 Kyle Nguyen. All rights reserved.
//

#include <iostream>

using namespace std;

void solve(int x, int y, string& m) {
    int n = (int)m.size();
    int res = 0;
    pair<int, int> b = {x, y};
    for (int i=0;i <n; i++) {
        if (m[i] == 'N') b.second += 1;
        else if  (m[i] == 'S') b.second -= 1;
        else if (m[i] == 'E') b.first += 1;
        else b.first -= 1;
        res++;
        if (abs(b.first) + abs(b.second) <= i+1) {
            printf("%d\n", res);
            return;
        }
    }
    printf("IMPOSSIBLE\n");
}
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        int x, y;
        string m;
        cin >> x >> y >> m;
        printf("Case #%d: ", t);
        solve(x, y, m);
    }
}
/* test case
 8
 4 4 SSS
 4 4 SSSS
 3 0 SNSS
 2 10 NSNNSN
 0 1 S
 2 7 SSSSSSSS
 3 2 SSSW
 4 0 NESW
 */
