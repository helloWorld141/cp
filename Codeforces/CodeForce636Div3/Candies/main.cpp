//
//  main.cpp
//  Candies
//
//  Created by Kyle Nguyen on 21/4/20.
//  Copyright © 2020 Kyle Nguyen. All rights reserved.
//

#include <iostream>
using namespace std;

long solve(long n) {
    int k=2;
    while ((1 << k) < n) {
        if (n % ((1 << k)-1) == 0) return n/((1 << k)-1);
        k++;
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    for (int test = 1; test<=t; test++) {
        long n;
        cin >> n;
        cout << solve(n) << endl;
    }
}
