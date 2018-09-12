#include <iostream>
#include <stdlib.h>
#define for(i,from, to) for (int i = from; i< to; i++)
using namespace std;
int a[21];
int l,n;
int order[101];
int freee[21];
void print(int order[], int start, int ends) {
    ends = (n < ends) ? (ends - 1): ends;
    for (i, start, ends+1) {
        if (order[i] != 0) for(j,0,a[order[i]])
            cout << order[i] << ' ';
        else cout << 0 << ' ';
    }
    cout << endl;
}

void arrange(int i, int times, int start) {
    if (times == 1000) exit(0);
    if (i == l) {
        //print(order, start, ends);
        cout << endl;
        times++;
        return;
    } else {
        for (j,start,n+1) if (!(i == 0 && j == 0)) {
            if (freee[j] == 1) {
                //order[i] = j;
                //chọn j
                if (j == 0) {
                    cout << 0 << ' ';
                    a[j]--;
                    if (a[j] == 0)
                        freee[j] = 0;
                } else {
                    for (k, 0 , a[j]) {
                        cout << j << ' ';
                    }
                    freee[j] = 0;
                }
                int step = (j != 0) ? a[j]: 1;
                arrange(i+step, times, start);
                if (j == 0) {
                    a[j]++;
                }
                freee[j] = 1;
            }
        }
    }
}

int main()
{
    int sum = 0;
    cin >> l >> n;
    for (i, 1, n+1) {
        cin >> a[i];
        sum += a[i];
    }
    a[0] = l - sum;
    int start = (a[0] == 0) ? 1 : 0;
    for (i, 0, n+1) freee[i] = 1;
    arrange(0,1, start);
    return 0;
}
