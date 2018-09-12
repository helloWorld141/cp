// y tuong giong mergesort va inversions
#include <iostream>
#include <vector>
#include <cstdio>


#define pb push_back

using namespace std;

long a[30001];
long q;
int n;

int merge_d(int l, int r, int mid){
    int lhs = l, rhs = mid;
    int cnt = 0;
    vector<long> temp;
    for (int i = l; i<r; i++){
        while (a[lhs] == 0){
            temp.pb(0);
            lhs++;
            i++;
        }
        while (a[rhs] == 0){
            temp.pb(0);
            rhs++;
            i++;
        }
        if (a[lhs] < a[rhs]){
            temp.pb(a[lhs]);
            cnt++;
            lhs++;
        }
        else if (a[lhs]>a[rhs]){
            temp.pb(a[rhs]);
            cnt++;
            rhs++;
        }
        else {
            temp.pb(a[lhs]);
            temp.pb(0);
            lhs++;
            rhs++;
            cnt++;
        }

        if (lhs == mid){
            while (rhs < r){
                temp.pb(a[rhs]);
                if (a[rhs] != 0) cnt++;
                rhs++;
            }
            i = r;
        }
        else if (rhs == r){
            while (lhs < mid){
                temp.pb(a[lhs]);
                if (a[lhs] != 0) cnt++;
                lhs++;
            }
            i = r;
        }
    }

    for (int i = 0; i < r-l; i++){
        a[l+i] = temp[i];
    }
    return(cnt);
}

int dquery(int l, int r){
    int mid = (l+r)/2;
    int x = 0, y = 0, z = 0;
    if (l<mid-1) x = dquery(l,mid);
    if (mid < r-1) y = dquery(mid,r);
    z = merge_d(l,r,mid);

    return (x+y+z);
}
int main()
{

    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        scanf("%ld", &a[i]);
    }
    scanf("&ld", &q);
    for (long i = 0; i<q; i++){
        scanf("%d %d", &l, &r);


    }
    return 0;
}
