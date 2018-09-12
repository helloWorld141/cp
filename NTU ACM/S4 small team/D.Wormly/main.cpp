#include <iostream>

using namespace std;

int brdge[1000000];
int b;
int n;
int L;
int Move(int tail, int head, int leg[], int next_tail){
    int ans =0;
    int cnt =0;

    for (int i = head; i>= tail; i--){
        if (bridge[i] == 1 && cnt < L){
            cnt++;
            leg[i] = 1;
            if (cnt == L) max_tail = i;
        }
        if (cnt >= L){
            leg[L] = 0;
        }
     }
     ans = cnt;
     next_tail = min(next_tail, n-b);

     if (next_tail == tail) {
        flag = 1;
        return -1;
     }
     else if (leg[n] == 1 && head == n) return ans;
     else ans += Move(next_tail, next_tail+b, leg, next_tail);
}

int main()
{
    int leg[1000000];
    scanf("%d", &t);
    for (int i =0; i< t; i++){
        scanf("%d %d %d", &L, &b, &n);
        for (int i=0; i<n; i++){
            scanf("%d", &bridge[i]);
            if (i<L) leg[i] =1;
            else leg[i] =0;
        }

    }

    return 0;
}
