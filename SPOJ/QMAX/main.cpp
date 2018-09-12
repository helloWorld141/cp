// ung dung partial sum va SQRT


#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>

#define SET_ANS if (b[j] > ans) ans = b[j]
using namespace std;

long n,m,q;
vector<long> a,b;
int _sqrt;

void my_partial_sum(){
    scanf("%ld %ld", &n, &m );
    long u,v,k;
    for (long i = 0; i< n; i++) a.push_back(0);
    for (long i = 0; i < m ; i++){
        scanf("%ld %ld %ld", &u, &v, &k );
        a[u-1] += k;
        if (v != n)
            a[v] -= k;
    }
    for (long i= 1; i<n; i++){
        a[i] = a[i-1] + a[i];
    }
}

void init(){
    _sqrt = (int)sqrt(n); // length of each bucket
    int size_b = (int)ceil((double)n/_sqrt);
    for (int j = 0; j < size_b; j++){
        b.push_back(a[j*(_sqrt)]);
    }
    for (long i = 0 ; i<n; i++){
        if (a[i] > b[i/_sqrt]) b[i/_sqrt] = a[i];
    }

}
void SQRT(){
    long u,v,p;
    long ans = 0;
    scanf("%ld", &p);
    for (long i = 0; i<p; i++){
        scanf("%ld %ld\n ", &u, &v);
        u--; v--;
        for (int j= u/_sqrt+1; j < v/_sqrt; j++){
            SET_ANS;
        }
        for (int j = u; j < (u/_sqrt+1)*_sqrt; j++){
            SET_ANS;
        }
        for (int j = (v/_sqrt)*_sqrt; j <=v; j++){
            SET_ANS;
        }
        printf("%ld\n", ans);
        ans = 0;
    }
}

int main()
{
    my_partial_sum();
    init();
    SQRT();

    return 0;
}
