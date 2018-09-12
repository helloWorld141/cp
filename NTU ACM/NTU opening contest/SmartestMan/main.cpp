#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n, IP;
    int opponent[500];
    while (scanf("%d", &n) != EOF){
        scanf("%d", &IP);
        for (int i = 0; i< n; i ++){
            scanf("%d", &opponent[i]);
        }
        sort(opponent, opponent+n);
        int remain = 0;
        for (int i=0; i < n; i++){
            if (IP >= opponent[i]) remain++;
            if (IP < opponent[i]) IP+=2;
        }
        cout << IP+remain << endl;
    }
    return 0;
}
