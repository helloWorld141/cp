#include <bits/stdc++.h>

using namespace std;

void BFS(vector<vector<int>> g, int s){
    queue<int> q;
    vector<int> d(g.size(), -1);
    d[s] = 0;
    vector<bool> passed(g.size(), false);
    q.push(s);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i=0; i<g[cur].size(); i++){
            int v = g[cur][i];
            if (!passed[v]){
                q.push(v);
                passed[v] = true;
                d[v] = d[cur] + 6;
            }
        }
    }

    for (int i = 1; i<d.size(); i++) {
        if (i!=s) cout << d[i] << ' ';
    }
    cout << endl;
}
int main()
{
    int q;
    cin >> q;
    for (int i =0; i<q;i++) {
        int n,m;
        cin >>n>>m;
        vector<vector<int>> g(n+1, vector<int>());
        for (int j=0; j<m; j++){
            int u; int v;
            cin >>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int s;
        cin >>s;

        BFS(g, s);
    }
    return 0;
}
