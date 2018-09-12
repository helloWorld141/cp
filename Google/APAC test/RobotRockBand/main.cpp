#include <iostream>
#include <cstdio>
using namespace std;

void do_test_case(int c, int n, long k){
    long a[4][1000];
    for (int i =0; i<4; i++)
        for (int j =0; j< n; j++) a[i][j] = 0;
    long cnt = 0;
    for (int i = 0 ; i<4; i++)
    for (int j = 0; j<n; j++){
        scanf("%ld", &a[i][j]);
    }
    for (int i = 0 ; i<n; i++)
    for (int j = 0; j<n; j++)
    for (int k = 0; k<n; k++)
    for (int l = 0; l<n; l++)
        if ((a[0][i] xor a[1][j] xor a[2][k] xor a[3][l]) == k) cnt++;
    printf("Case #%d: %ld\n", c, cnt);
}

int main()
{
    int n,t;
    long k;
    scanf("%d", &t);
    for (int i =0; i<t; i++){
        scanf("%d %ld", &n, &k);
        do_test_case(i+1,n,k);
    }
    return 0;
}
