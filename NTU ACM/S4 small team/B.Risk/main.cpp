#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;

int mine[100];
int n;
int a[100];
char s[100][100];
void read(){
    scanf("%d", &n);
    for (int i =0; i<n; i++){
        scanf("%d", &a[i]);
    }
    //scanf("\n");
    scanf("\n");
    for (int i = 0; i<n; i++) gets(s[i]);
}
    //for (int j = 0; j<n; j++) scanf("%c", &s[i][j]);

bool Find(int a[], int Size, int x){
    for (int i =0; i<Size; i++ ){
        if (a[i] == x) return true;
    }
    return false;
}
void idk(){
    int m =-1;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (s[i][j] == 'Y'){
                if (a[i] >0 && a[j] ==0){
                    if(!Find(mine, m+1 , i)){
                        m++;
                        mine[m] = i;
                    }
                }
                if (a[j] >0 && a[i] ==0){
                    if(!Find(mine, m+1, j)){
                        m++;
                        mine[m] =j;
                    }
                }
            }
        }
    }
    int weak = 0;
    for (int i = 0; i<m ;i++) if (a[mine[weak]] > a[mine[i]]) weak = i;
    int ans = 0;
    //a[mine[weak]];
    for (int i=0; i<n; i++){
        if (s[mine[weak]][i] == 'Y' and a[i] >1) ans+= a[i]-1;
    }
    printf("%d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i =0; i<t; i++){
        read();
        idk();
    }
    return 0;
}
