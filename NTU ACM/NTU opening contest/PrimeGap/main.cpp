// prime gap
#include <iostream>
#include <vector>
#include <math.h>
#define MAX 1300000
bool prime[MAX];

using namespace std;

void Era(){
    prime[1] = false;
    for (long int i = 2; i <= MAX; i++)
        prime[i] = true;
    for (long int i = 2; i <= (int)floor(sqrt((double)MAX)); i++){
        if (prime[i])
            for (long int j = i*i; j <= MAX; j+= i)
                prime[j] = false;
    }
}

int gap(int x){
    long int i = x;
    while (prime[i] == false) i--;
    long int head = i;

    i = x;
    while (prime[i] == false) i++;
    long int tail = i;
    return (tail - head);
}

int main()
{
    Era();
    vector<long int> a;
    int n = 0, t = 0;
    do {
        cin >>t;
        a.push_back(t);
        n++;
    } while (t != 0);
    /*for (long int i = 1; i <= MAX; i ++)
        if (prime[i])
            cout<<i<<' ';*/
    for (long int i = 0; i < n-1 ; i++)
        cout<< gap(a[i]) <<' ';
    return 0;
}
