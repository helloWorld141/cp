#include <iostream>

using namespace std;


int main()
{
    int n, cnt = 0, t=-1;
    int a[100]={};

    unsigned long long int res = 1;
// yet unsuccessful approach
   cin >> n;
   for (int i = 0; i <n; i++) {
        cin >> t;
        if (t==1){
            a[++cnt] = i;
            res = 1;
        }
   }

   for (int i = 1; i < cnt ; i++){
        res *= (a[i+1]- a[i]);
   }
   if (cnt ==0) res = 0;

    //ANOTHER APPROACH (successful)
  /*  cnt = 1;
    for (int i = 0 ; i< n; i++){
        cin >> a[i];
    }
    for (int i =0; i <= n; i++)
        if (a[i] == 1){
            t = i;
            break;
    }
    if (t == -1) res =0;
    else {
        for (int i = t; i<n; i++){
            if (a[i] == 0 )
                ++cnt;
            else {
                res *= cnt;
                cnt = 1;
            }
        }
    }*/
   cout << res;
   return 0;
}
