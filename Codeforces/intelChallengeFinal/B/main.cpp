#include <iostream>

using namespace std;

int countWrong(int a[], int m) {
    int ans =0;
    for (int i = 1; i<=m; i++) {
        if (a[i] != i) ans++;
    }
    return ans;
}

int main()
{
    int a[21][21];
    bool flag;
    int cnt=0;
    int n, m;
    cin >> n >> m;
    for (int i =1; i<=n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];

    for (int u=1; u<=m; u++)
    for (int v=u; v<=m; v++) {
        flag = true;
        cnt = 0;
        for (int i=1; i<=n ; i++) {
            swap(a[i][u], a[i][v]);
            cnt = countWrong(a[i], m);
            swap(a[i][u], a[i][v]);
            if (cnt > 2){
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" <<endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
