#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>

#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int N = 1002;

bool cmp1 (pii x, pii y) {
	if (x.fi == y.fi) return x.se < y.se;
	return x.fi > y.fi;
}

pair <int, int> p[N];
pii dp[N][N];

int n;
char s[10];
pii f (int x, int y) {
	if (x == n) return y == (n >> 1) + (s[0] == 'J' && n % 2 == 1) ? mp(0, 0) : mp(-1000000000, 0);
	if (dp[x][y] != mp(-1, -1)) return dp[x][y];
	
	pii ret = f(x + 1, y);
	if (s[0] == 'P') {
		if (y < x - y) {
			pii tmp = f(x + 1, y + 1);
			tmp.fi += p[x].se;
			tmp.se -= p[x].fi;
			
			ret = max (ret, tmp);
		}
	} else {
		if (y <= x - y) {
			pii tmp = f(x + 1, y + 1);
			tmp.fi += p[x].se;
			tmp.se -= p[x].fi;
			
			ret = max (ret, tmp);
		}
	}
	
	return dp[x][y] = ret;
}

int Main () {	
	scanf ("%d", &n);
	
	gets(s); gets(s);


	for (int i=0; i<n; i++) {
		scanf ("%d %d", &p[i].fi, &p[i].se);
	}
	
	// Sort according Petra's	
	sort (p, p + n, cmp1);
	
	// Initialize all array
	for (int i=0; i<n; i++) for (int j=0; j<=n; j++) dp[i][j] = mp(-1, -1);
	
	// Find Jan's optimal
	pii ans = f(0, 0);
	
	for (int i=0; i<n; i++) ans.se += p[i].fi;
	
	printf ("%d %d\n", ans.se, ans.fi);
	
	return 0;
}

int main () {
	int t;
	scanf ("%d", &t);
	while (t--) Main ();
	return 0;
}