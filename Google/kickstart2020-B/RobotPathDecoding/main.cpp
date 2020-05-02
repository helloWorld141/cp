//
//  main.cpp
//  RobotPathDecoding
//
//  Created by Kyle Nguyen on 19/4/20.
//  Copyright © 2020 Kyle Nguyen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MOD = 1e9;
int mod(long x) {
    return (x < 0) ? (x+MOD) % MOD: x%MOD;
}
pair<int, int> solve(string& s) {
    int x = 0, y =0;
    stack<long> st;
    st.push(1);
    for (char c :s) {
        if ('1' < c && c <= '9') {
            st.push(mod((c - '0')*st.top()));
        }
        else if (c == ')') {
            st.pop();
        }
        else if (c == '(') continue;
        else {
            switch (c) {
                case 'N': y = mod(y - st.top()); break;
                case 'S': y = mod(y + st.top()); break;
                case 'E': x = mod(x + st.top()); break;
                case 'W': x = mod(x - st.top()); break;
                default: break;
            }
        }
    }
    return make_pair(x+1, y+1);
}

int main(int argc, const char * argv[]) {
//    int size = 10;
//    string input = "";
//    for (int i=0; i<size; i++) input += "9(";
//    for (int i=0; i<size; i++) input += "E)";
//    pair<int, int> res = solve(input);
//    cout << res.first << ' ' << res.second << endl;
    int T;
    cin >> T;
    for (int test=1; test<=T; test++) {
        string s;
        cin >> s;
        pair<int, int> res = solve(s);
        printf("Case #%d: %d %d\n", test, res.first, res.second);
    }
}
/*
9
SSSEEE
N
N3(S)N2(E)N
2(3(NW)2(W2(EE)W))
9(9(9(9(9(9(9(9(9(9(9(E)))))))))))
9(9(9(9(9(9(9(9(9(9(9(9(E))))))))))))
9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(E)))))))))))))))))))
9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(E))))))))))))))))))))))))))))))))))))))
9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(9(E))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
 */
