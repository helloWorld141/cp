#include <iostream>
#include <vector>
#include <fstream>

#define pb push_back;
using namespace std;
int arrX[51][51];
//vector<int> arrY[51];
int countX[51];

int modeX(int t, int order){
    int appear[51];
    int pos[51];
    for (int i=0; i<51; i++) appear[i] =0;
    for (int i =1; i<=countX[t]; i++){
        appear[arrX[t][i]]++;
    }
    for (int i=0; i<51; i++) pos[i] = i;
    int imax = 0;
    for (int i =0; i<50; i++)
    for (int j = i+1; j<51; j++){
        if (appear[i]<appear[j]){
            appear[i] += appear[j];
            appear[j] = appear[i] - appear[j];
            appear[i] -= appear[j];

            pos[i] += pos[j];
            pos[j] = pos[i] - pos[j];
            pos[i] -= pos[j];
        }
    }
    return pos[order-1];
}


int main()
{
    int n;
    //int a[51][5];
    int b[51];
    int t;
    //int flag;
    for (int i =0; i<51; i++) b[i] =0;
    //for (int i = 0; i < 51; i++)
    //    for (int j =0; i < 5; j++)
    //    a[i][j] = 0;

    //ifstream f;
    //f.open("input.txt");



    cin >> n;
    if (n==2) {cout << 1 << ' '<< 2; return 0;}
    else {
    for (int i = 1; i<= n; i++)
    for (int j = 1; j <= n; j++){
        cin >> t;
        if (t != 0) {
            countX[t]++;
            arrX[t][countX[t]] = i;
        }
    }

    for (int i =1 ; i<n; i++){
        t = 1;
    while (b[modeX(i,t)] != 0) t++;
    b[modeX(i,t)]=i;
    }

    for (int i=1; i <= n; i++){
        if (b[i] != 0 ) cout << b[i]<<' ';
        else cout<< n << ' ';
    }
    //f.close();
    return 0;}
}
