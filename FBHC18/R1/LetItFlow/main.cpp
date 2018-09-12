#include <iostream>
#include <fstream>
using namespace std;

const int64_t p = (1e+9)+7;

int64_t countPipe(int n, char m[][1000]){
    if (n%2 == 1) return 0;
    if (m[0][0] == '#' || m[1][0] == '#' || m[1][n-1] == '#' || m[1][n-1] == '#') return 0;
    int64_t res = 1;
    for (int i = 1; i<n-1; i+=2){
        if (m[1][i] == '#' || m[1][i+1] == '#') return 0;
        if (m[0][i] =='.' && m[0][i+1] == '.') {
            if (m[2][i] =='.' && m[2][i+1] == '.') {
                res = (res * 2) % p;
            }
        } else {
            if (m[2][i] =='#' || m[2][i+1] == '#') return 0;
        }
    }
    return res;
}

int main()
{
    ifstream in;
    in.open("let_it_flow.txt");
    ofstream out;
    out.open("let_it_flow_output.txt");
    int t;
    cout << p;
    in >> t;
    for (int i=0; i<t; i++){
        int n;
        in >> n;
        char m[3][1000];
        for (int i=0; i<3; i++){
            for (int j=0; j<n; j++){
                in >> m[i][j];
            }
        }
        out << "Case #" << i+1 << ": " << countPipe(n, m);
        if (i!=t-1) out << endl;
    }
    return 0;
}
