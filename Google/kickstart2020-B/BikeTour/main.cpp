//
//  main.cpp
//  BikeTour
//
//  Created by Kyle Nguyen on 19/4/20.
//  Copyright © 2020 Kyle Nguyen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& a) {
    int res = 0;
    int i=1;
    while (i<a.size()-1) {
        if (a[i] > a[i-1] && a[i] > a[i+1]) {
            res++;
            i+=2;
        } else i++;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for (int test=1; test<=T; test++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        printf("Case #%d: %d\n", test, solve(a));
    }
}
/*
4
3
10 20 14
4
7 7 7 7
5
10 90 20 90 10
3
10 3 10
 */
