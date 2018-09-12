// test for fast I/O
// http://www.spoj.com/problems/INTEST/

#include <iostream>
#include <cstdio>

#define MAX 65536
#define N 10000001
using namespace std;

long a[N];
long n,k;

void fastIn() {
    char b[MAX]; // mang luu buffer
    int c;
    long t = 0, cnt = -1;
    scanf("%ld %ld\n", &n, &k);
    while ( (c = fread(b,1,MAX,stdin)) > 0 ){ // c : number of objects read successfully
        for (long i = 0; i < c; i++){
            if (b[i] == '\n'){
                a[++cnt] = t;
                t = 0;
                //if (cnt == n-1) break;
            }
            else {
                t = t*10 + (b[i] - '0');
            }
        }
    }

}

int main()
{
    fastIn();
    long cnt=0;
    for (long i = 0; i <n; i++){
        if (a[i] % k ==0) ++cnt;
    }

    printf("%ld", cnt);
    return 0;
}
