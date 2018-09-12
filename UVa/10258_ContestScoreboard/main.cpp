#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    scanf("\n");
    while (n--) {
        int p[10][101];
        for (int i =0 ; i<10; i++) for (int j =0; j<101; j++) p[i][j] = 0;
        map<int,pair<int,int>> r;
        char aa;
        int a,b,c;
        string s;
        scanf("%c", &aa);
        while (aa != '\n') {
            a= aa-48;
            cin >> b >> c >> s;
            if (r.find(a) == r.end()) r[a] = make_pair(0,0);
            if (s.compare("I") == 0) {
                p[a][b] += 20;
            }
            else if (s.compare("C") == 0) {
                p[a][b] += c;
                r[a].first+=1; r[a].second = p[a][b];
            }
            scanf("\n%c", &aa);
        }

        map<int,pair<int,int>>::iterator it = r.begin();
        while (it != r.end()) {
            cout << it->first << ' ' << (it->second).first << ' ' << (it->second).second << endl;
            it++;
        }

    }
    return 0;
}

/* test
1
1 2 10 I
3 1 11 C
1 2 19 R
1 2 21 C
1 1 25 C
*/
