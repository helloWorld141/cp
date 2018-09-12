#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>

#define pb push_back
using namespace std;
long n;

void read(long n){
    string temp;
    vector<string> d,k;
    map<string , long> dmap, kmap;
    long dcount[200001];
    long kcount[200001];
    for (long i =0; i<n; i++){
        cin >> temp;
        d.pb(temp);
        dmap[temp] = 0;
        kmap[temp] = 0;
    }

    for (long i =0; i<n; i++){
        cin >> temp;
        k.pb(temp);
        kmap[temp] = 0;
        dmap[temp] = 0;
    }

    for (long i =0; i<n; i++){
        dmap[d[i]]++;
        kmap[k[i]]++;
    }
    long ans = 0, cnt=0;
    for (map<string, long>::iterator i=dmap.begin(); i!=dmap.end(); ++i){
        cnt++;
        dcount[cnt] = i->second;
    }
    cnt=0;
    for (map<string, long>::iterator i=kmap.begin(); i!=kmap.end(); ++i){
        cnt++;
        kcount[cnt] = i->second;
    }
    for (long i =1; i<= cnt; i++){
        ans += min(dcount[i], kcount[i]);
    }
    cout << ans <<endl;
}
int main()
{
    while ( scanf("%ld\n", &n) == 1 ) read(n);
    return 0;
}
