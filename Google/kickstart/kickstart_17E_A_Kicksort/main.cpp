#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
int n;
int a[10010];

bool solve(){
    priority_queue<int> qmin;
    priority_queue<int> qmax;
    for (int i = 0; i<n; i++) {
        qmin.push(-a[i]);
        qmax.push(a[i]);
    }
    vector<int> aa(begin(a), end(a));
    int nn = n;
    while (nn > 0){
        int p = aa[(nn-1)/2];
        if (qmin.top() != -p && qmax.top()!=p)
            return false;
        if (qmin.top() == -p) qmin.pop();
        if (qmax.top() == p) qmax.pop();
        aa.erase(aa.begin()+(nn-1)/2);
        nn--;
    }
    return true;
}
int main()
{
    int t;
    ifstream in;
    ofstream out;
    //in.open("A-small-attempt0.in");
    //out.open("A-small-attempt0.out");
    in.open("A-large.in");
    out.open("A-large.out");
    in >> t;
    for (int c =0; c<t; c++){
        in >> n;
        for (int i=0; i<n; i++){
            in >> a[i];
        }
        bool res = solve();
        string s = (res)? "YES" : "NO";
        cout << "Case #" << c+1 << ": " << s << endl;
        out << "Case #" << c+1 << ": " << s << endl;
    }
}
