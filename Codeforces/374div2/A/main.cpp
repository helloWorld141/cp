#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int socum = 0;
    int a[100];
    int flag = 0;
    fill(a, a+100, 0);
    for (int i =0; i<n; i++) {
        if (s[i] == 'B' && flag == 0) {
            flag = 1;
            socum++;
        }
        else if (s[i] == 'W' && flag == 1){
            flag = 0;
        }
        if (flag) {
            a[socum]++;
        }
    }
    cout << socum << endl;
    for (int i =1; i<=socum; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
