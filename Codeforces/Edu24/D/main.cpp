#include <iostream>
#include <map>
using namespace std;

bool flag = false;

int main()
{
    map<long, long> c;
    long n,a,t,cnta=0;
    cin >> n >> a;
    for (long i=0; i<n; i++) {
        cin >> t;
        if (t == a) {
            cnta++;
            flag = true;
        }
        else if (flag){
//            map<int,int>::iterator iter = c.find(t);
//            if (iter == c.end()){
//                c.insert(t, 1);
//            } else {
//                iter->second++;
//            }
            if (c[t]<cnta) c.erase(t);
            else c[t]++;
        } else {
            c[t]++;
        }
    }
    map<long,long>::iterator iter;
    for (iter = c.begin(); iter != c.end(); iter++){
        if (iter->second >= cnta) {
            cout << iter->first;
            return 0;
        }
    }
    cout << -1;

    return 0;
}
