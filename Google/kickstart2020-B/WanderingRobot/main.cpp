//
//  main.cpp
//  WanderingRobot
//
//  Created by Kyle Nguyen on 19/4/20.
//  Copyright © 2020 Kyle Nguyen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

long solve(vector<long>& a, long d) {
    long res = d;
    for (int i=a.size()-1; i>=0; i--) {
        res = res/a[i] * a[i];
    }
    return res;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for (int test=1; test<=T; test++) {
        int n;
        long d;
        cin >> n >> d;
        vector<long> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        printf("Case #%d: %ld\n", test, solve(a, d));
    }
}
/*
4
3 3 2 2 2 2
5 3 1 2 4 2
1 10 1 3 1 5
6 4 1 3 3 4
*/
