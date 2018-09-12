#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long e, a[2000];
int n, h[2000];
vector<long> rem;
int solve (long e, int H){
    long ee = e;
    int HH = H;
    priority_queue<long> minq;
    for (int i=0; i<rem.size(); i++){
        minq.push(-rem[i]);
    }
    while (!minq.empty()){
        if (ee > -minq.top()){
            ee += minq.top();
            HH++;
            rem.erase(remove(rem.begin(), rem.end(), -minq.top()), rem.end());
            minq.pop();
        }
        else break;
    }
    h[HH] = HH;
    if (HH == 0) return 0;
    long maxx = 0;
    for (int i=0; i<rem.size(); i++){
        if (rem[i] > maxx) maxx = rem[i];
    }
    ee+=maxx;
    rem.erase(remove(rem.begin(), rem.end(), maxx), rem.end());
    if (rem.size() == 0) return HH;
    int res = max(solve(ee, HH-1), HH);
    return res;
}

int main()
{
    int t;
    ifstream in;
    ofstream out;
    in.open("B-small-attempt3.in");
    out.open("B-small-attempt3.out");
    in >> t;
    for (int c=0; c<t; c++){
        in >> e >> n;
        for (int i = 0; i<n; i++) in >> a[i];
        memset(h, -1, sizeof(h));
        rem = vector<long>(begin(a), begin(a)+n);
        solve(e, 0);
        int res =0;
        for (int i =n; i>=0; i--)
            if (h[i] != -1) {
                res = i;
                break;
            }
        cout << "Case #" << c+1 << ": " << res <<endl;
        out << "Case #" << c+1 << ": " << res <<endl;
    }
}
