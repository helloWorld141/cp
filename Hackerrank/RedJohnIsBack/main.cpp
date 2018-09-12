#include <iostream>
#include <math.h>
using namespace std;
int a[1000000]; // erathosten sieve
long long factorial(int n){
    if (n==1 || n==0) return 1;
    return factorial(n-1)*n;
}

long long  count(int n, int k){
    long long ans = 1;
    for (int i = n-k+1; i<=n-k+k/4; i++){
        ans *= i;
    }
    ans /= factorial(k/4);
    return ans;
}



int main()
{
    fill_n(a, 1000000, 1);
        a[0]= 0;
        a[1]=0;
        for (long i=2;i<=(long)sqrt(1000000);i++){
            if (a[i] == 1){
                long j =2;
                while (i*j < 1000000){
                    a[i*j] = 0;
                    j++;
                }
            }
        }
    int n,t;
    cin >> t;
    while (t--){
        cin >> n;
        int k =0;
        long cnt = 0;
        long cntP = 0;
        while (k<=n){
            cnt += count(n, k);
            k+=4;
        }
        //cout << cnt << endl;
        for (long i=cnt; i>0; i--){
            if (a[i] == 1){
                cntP++;
            }
        }
        cout << cntP << endl;
    }
    return 0;
}
