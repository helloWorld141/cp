//
//  main.cpp
//  NestingDepth
//
//  Created by Kyle Nguyen on 4/4/20.
//  Copyright © 2020 Kyle Nguyen. All rights reserved.
//

#include <iostream>

using namespace std;

string solve(string& s){
    string t = "";
    int count = 0;
    int i = 0;
    while (i<s.size()) {
        int d = s[i] - '0';
        if (count == d) {
            t += s[i++];
        } else if (count < d) {
            while (count < d) {
                t += '(';
                count++;
            }
        } else {
            while (count > d) {
                t += ')';
                count--;
            }
        }
    }
    while (count > 0) {
        t += ')';
        count--;
    }
    return t;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for (int i=0; i<T; i++){
        string s;
        cin >> s;
        //printf("Solving case %d\n", i+1);
        string t = solve(s);
        printf("Case #%d: %s\n", i+1, t.c_str());
    }
    cin.get();
    return 0;
}

// test cases
/*
8
0000
101
111000
1
021
312
4
221
 */
