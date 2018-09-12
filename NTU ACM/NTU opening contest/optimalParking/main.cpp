#include <iostream>

using namespace std;

int main()
{
    int t, n, temp;
    cin>> t;
    for (int i =1 ; i <= t; i++ ){
        cin >> n;
        int Max = 0, Min = 100;
        for (int j = 1; j <= n; j++){
            cin >> temp;
            if (Min > temp) Min = temp;
            if (Max < temp) Max = temp;
        }
        cout<< 2*(Max - Min)
         << endl;
    }
}
