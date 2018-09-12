// divide and conquer
#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
#define ui long int
#define pb push_back
using namespace std;

ui a[60001];

void sinhtest(){
    ofstream f;
    f.open("input.txt");
    f << 60000 << endl;
    for (int i=0; i < 60000; i++){
		f<< 60000- i << ' ';
	}
	f.close();
}

ui merge_inv(ui l, ui r, ui mid){
    ui lhs = l;
    ui rhs = mid;
    ui cnt = 0;
    vector<ui> temp;
    for (ui i = l; i< r; i++){
        if (a[lhs] <= a[rhs]){
            temp.pb(a[lhs]);
            lhs++;
        }
        else {
            temp.pb(a[rhs]);
            cnt += (mid - lhs);
            rhs++;
        }
        if (lhs==mid) {
            while (rhs < r){
                temp.pb(a[rhs]);
                rhs++;
            }
            i = r;
        }
        else if (rhs==r){
            while (lhs< mid){
                temp.pb(a[lhs]);
                lhs++;
            }
            i = r;
        }
    }
    for (ui i = 0; i < r-l; i++ ){
        a[l+i] = temp[i];
    }
    return cnt;
}

ui inv_cnt(ui l, ui r){
    ui mid = (l+r)/2;
    ui x = 0, y = 0;
    if (l<mid-1) x = inv_cnt(l, mid);
    if (mid < r-1) y = inv_cnt(mid, r);
    ui z = merge_inv(l,r, mid);

    return (x+y+z);
}

int main()
{

    ui n;

    scanf("%ld", &n);
    for (ui i = 0 ; i < n ; i++){
        scanf("%ld", (a+i));
    }
    printf("%ld", inv_cnt(0,n));

////////
/*
    sinhtest();
    ifstream g;
    g.open("input.txt");
    g >> n;
    for (ui i =0 ; i <n ; i++){
        g >> a[i];
    }
    g.close();

    cout << inv_cnt(0, n) << endl;
    long long test = 0;
    for (int i = 0; i< 60000; i++){
        test += i;
    }
    cout << test;
*/
    return 0;
}
