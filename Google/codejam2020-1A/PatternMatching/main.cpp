//
//  main.cpp
//  PatternMatching
//
//  Created by Kyle Nguyen on 11/4/20.
//  Copyright © 2020 Kyle Nguyen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string solve(vector<string>& ps){
    string res = "";
    int maxLeftMargin = 0, maxRightMargin = 0;
    for (int i=0; i<ps.size(); i++) {
        int leftMargin = (int)ps[i].find("*");
        int rightMargin = (int)ps[i].size() - leftMargin - 1;
        
        if (leftMargin > maxLeftMargin) {
            maxLeftMargin = leftMargin;
        }
        if (rightMargin > maxRightMargin) {
            maxRightMargin = rightMargin;
        }
    }
    for (int i=0; i<ps.size(); i++) {
        int leftMargin = (int)ps[i].find("*");
        int rightMargin = (int)ps[i].size() - leftMargin - 1;
        
        for (int j=leftMargin; j < maxLeftMargin; j++) {
            ps[i].insert(leftMargin, "_");
        }
        for (int j=rightMargin; j < maxRightMargin; j++) {
            ps[i].insert(leftMargin+1, "_");
        }
        ps[i].replace(leftMargin, 1, "");
    }
    
    for (int col=0; col<ps[0].size(); col++){
        char s = ps[0][col];
        for (int row=1; row<ps.size(); row++) {
            if (ps[row][col] != '_') {
                if (s == '_') s = ps[row][col];
                if (s != ps[row][col]) return "*";
            }
        }
        res += s;
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for (int test=1; test <= T; test++) {
        int n;
        cin >> n;
        vector<string> ps (n);
        for (int i=0; i<n; i++) {
            cin >> ps[i];
        }
        string res = solve(ps);
        printf("Case #%d: %s\n", test, res.c_str());
    }
    return 0;
}

// test
/*
2
5
*CONUTS
*COCONUTS
*OCONUTS
*CONUTS
*S
2
*XZ
*XYZ
 */
