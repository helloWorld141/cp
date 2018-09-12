#include <iostream>
#define MAX 1000001
using namespace std;

long n,m,k;
long a[MAX], s[MAX];

void read(){
    a[0] = 0;
    s[0] = 0 ;
    cin >> n >> m >> k;
    for (int i=1; i <= n; i++){
        cin >>a[i];
        s[i] = s[i-1] xor a[i];
    }
}

//--------------------- APPROACH 1: O(mn log n)
int main()
{




}
