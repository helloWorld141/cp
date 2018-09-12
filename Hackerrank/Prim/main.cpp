#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<int, ii>
#define vii vector<ii>
#define ff first
#define ss second
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vii> g = vector<vii>(n+1, vii()); //from, to, weight
    for (int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b>>c;
        g[a].push_back(ii(b,c));
        g[b].push_back(ii(a,c));
    }
    int s;
    cin >> s;
    bool inTree[3000];
    fill_n(inTree, 3000, false);
    priority_queue<iii> cut; //weight, from, to

    int w = 0;
    inTree[s] = true;
    for (int i =0; i<g[s].size(); i++) {
        cut.push(iii(g[s][i].ss, ii(s, g[s][i].ff)));
    }
    for (int i =0; i<n-1; i++){
        iii chosen = cut.top();
        cut.pop();
        w += chosen.ff;
        int s = chosen.ss.ss;
        inTree[s]= true;
        for (int j=0; j<g[s].size(); j++){
            cut.push(iii(g[s][i].ss, ii(s, g[s][i].ff)));
        }
    }
    cout << w;

    return 0;
}
