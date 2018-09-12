#include <bits/stdc++.h>
#define vii vector<pair<int,int>>
#define mp make_pair
#define pb push_back
#define MAX 1000000001
#define ff first
#define ss second
using namespace std;

void dijkstra_heap(vector<vii> g, int s){
    priority_queue<pair<int,int>> q; //ff is length, ss is vertex
    vector<int> d(g.size(), MAX);
    d[s] = 0;
    bool mark[3001];
    fill_n(mark, 3001, false);

    q.push(mp(-d[s], s));
    while (!q.empty()){
        pair<int,int> current = q.top(); q.pop();
        int cur = current.ss;
        if (!mark[cur]){
            for (int i =0; i<g[cur].size(); i++) {
                int v = g[cur][i].ff;
                int l = g[cur][i].ss;
                if (d[v] > d[cur] + l) {
                    d[v] = d[cur] + l;
                    q.push(mp(-d[v], v));
                }
            }
            mark[cur] = true;
        }
    }

    for (int i = 1; i<d.size(); i++) {
        if (i!=s)
            if (d[i] == MAX) cout << -1 << ' ';
            else cout << d[i] << ' ';
    }
    cout << endl;
}
int minn(vector<int> &d, bool mark[]){
    int m =1;
    while (mark[m]) m++;
    for (int i=m+1; i<d.size(); i++) if (!mark[i]) {
        if (d[m] > d[i]) m=i;
    }
    return m;
}

void dijkstra(vector<vii> g, int s){
    int n = g.size() -1;
    vector<int> d(g.size(), MAX);
    bool mark[3001];
    fill_n(mark, 3001, false);
    d[s] = 0;
    for (int i=0; i<n; i++) {
        int cur = minn  (d, mark);
        mark[cur] = true;
        //cout << g[cur].size() << endl;
        for (int j = 0; j<g[cur].size(); j++) {
            int v = g[cur][j].ff;
            int l = g[cur][j].ss;
            if (d[cur] + l < d[v])
                d[v] = d[cur] + l;
        }
    }

    for (int i = 1; i<d.size(); i++) {
        if (i!=s)
            if (d[i] == MAX) //cout << -1 << ' ';
                printf("%d ", -1);
            else //cout << d[i] << ' ';
                printf("%d ", d[i]);
    }
    //cout << endl;
    printf("\n");
}
void dijkstra(vector<vector<int>> &g, int s){
    int n = g.size() -1;
    vector<int> d(g.size(), MAX);
    bool mark[3001];
    fill_n(mark, 3001, false);
    d[s] = 0;
    for (int i=0; i<n; i++) {
        int cur = minn(d, mark);
        mark[cur] = true;
        for (int j = 1; j<=n; j++)
            if (!mark[j]) {
            if (d[cur] + g[cur][j] < d[j])
                d[j] = d[cur] + g[cur][j];
        }
    }

     for (int i = 1; i<d.size(); i++) {
        if (i!=s)
            if (d[i] == MAX) //cout << -1 << ' ';
                printf("%d ", -1);
            else //cout << d[i] << ' ';
                printf("%d ", d[i]);
    }
    //cout << endl;
    printf("\n");
}

int main()
{
    ifstream f;
    f.open("input07.txt");
    int q;
    //f>>q;
    //cin >> q;
    scanf("%d", &q);
    for (int i =0; i<q;i++) {
        int n,m;
        //f >> n>>m;
        //cin >>n>>m;
        scanf("%d %d", &n, &m);
        vector<vector<int>> ma(n+1, vector<int>(n+1, MAX));
        vector<vii> g(n+1, vii());
        for (int j=0; j<m; j++){
            int u; int v; int r;
            //f >>u>>v>>r;
            //cin >>u>>v>>r;
            scanf("%d%d%d", &u, &v, &r);
            if (ma[u][v] > r) {
                ma[u][v] = r; ma[v][u] = r;
            }
        }

        for (int u=1; u<=n; u++)
        for (int v=1; v<=n; v++) {
            if (ma[u][v] != MAX) {
                g[u].pb(mp(v,ma[u][v]));
            }
        }


        int s;
        //f >>s;
        //cin >>s;
        scanf("%d", &s);
        f.close();
        //dijkstra_heap(g, s);
        dijkstra(g, s);
    }
    return 0;
}
