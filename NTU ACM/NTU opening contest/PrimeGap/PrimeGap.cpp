// prime gap
#include <iostream>
#include <vector>
#define MAX 13000
bool prime[MAX];

using namespace std;

void Era(){
    prime[1] = false;
    for (int i = 2; i <= MAX; i++)
        prime[i] = true;
    for (int i = 2; i <= MAX; i++){
        if (prime[i])
            for (int j = i*i; j <= MAX; j+= i)
                prime[j] = false;
    }
}

int gap(int x){
    int i = x;
    while (prime[i] == false) i--;
    int head = i;

    i = x;
    while (prime[i] == false) i++;
    int tail = i;
    return (tail - head);
}

int main()
{
    Era();
    vector<int> a;
    int n = 0, t = 0;
    do {
        cin >>t;
        a.push_back(t);
        n++;
    } while (t != 0);
    for (int i = 1; i <= n ; i++)
        cout<< a[i] <<' ';
    return 0;
}
