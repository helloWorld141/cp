#include <iostream>

using namespace std;

long n;
short grid[1002][1002];

void read(){
    int x,y;



    cin >> n;
    for (int i =0; i<1002; i++)
        for (int j =0; j< 1002; j++)
            grid[i][j] = 0;
    for (long i =1 ; i<= n; i++){
        cin >> x >>y;
        grid[x][y] = 1;
    }
}
int main()
{
    read();
    long long ans = 0;
    int x1,x2,y1,y2,dem;
    for (int j = 1; j<= 999; j++){
        x1=1; x2 =1000; y1 =j; y2 =j;
        dem= 0;
        do {
            if (grid[x1][y1]==1) dem++;
            x1++;
            y1--;
        } while (y1>0);
        ans += dem*(dem-1)/2;

        dem= 0;
        do {
            if (grid[x2][y2]==1) dem++;
            x2--;
            y2++;
        } while (y2<1001);
        ans += dem*(dem-1)/2;

        x1=1; x2 =1000; y1 =j; y2 =j;
        dem = 0;
        do {
            if (grid[x1][y1]==1) dem++;
            x1++;
            y1++;
        } while (y1<1001);
        ans += dem*(dem-1)/2;

        dem= 0;
        do {
            if (grid[x2][y2]==1) dem++;
            x2--;
            y2--;
        } while (y2>0);
        ans += dem*(dem-1)/2;

    }

    cout <<ans;
    return 0;
}
