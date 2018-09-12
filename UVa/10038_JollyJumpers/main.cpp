#include <bits/stdc++.h>

using namespace std;

void doo(int n){
    int a,b;
    vector<bool> v(n,false);
    cin >> a;
    for (int i =1; i< n; i++) {
        cin >> b;
        int temp = (int)abs(a-b);
        if (temp >0 && temp <n) v[temp] = true;
        a = b;
    }
    sort(v.begin()+1, v.end());
    //cout << v.size() << endl;
    //for(int i =0; i< v.size() ; i++) cout << v[i] << ' ';
    //cout << endl;
    if (binary_search(v.begin()+1, v.end(), false)) cout << "Not jolly" << endl;
        else cout <<"Jolly" << endl;
    return;
}
int main()
{
    int n;
    while (cin >> n) {
        doo(n);
    }
    return 0;
}

/* test
4 1 4 2 3
5 1 4 2 -1 6
*/

