#include <iostream>
#include <cstdio>
#include <string>
#include <array>
#include <fstream>


#define MOD 1000000007
using namespace std;
ifstream f;
ofstream g;
int t;
void read(){

    string s;
    int n =0;
    long long ans = 1;
    array<int,1000> a;
    a.fill(1);

        getline(f, s);
        n = s.length();
        if (s[0] != s[1]) a[0] = 2;
        if (s[n-1] != s[n-2]) a[n-1] = 2;
        for (int i =1; i<n-1 ; i++){
            if (s[i-1]!= s[i]) a[i]++;
            if (s[i+1]!=s[i] && s[i+1]!=s[i-1]) a[i]++;
        }
        for (int i =0; i<n; i++) ans*=a[i]%MOD;
    g << ans<< endl;
}
int main()
{
    int t;

    f.open("A-small-practice.in");

    g.open("out.txt");
    t = f.get();
    if (t==1) g<<1;
    else
    for (int i =0; i<t; i++) read();
    f.close();
    g.close();
    return 0;
}
