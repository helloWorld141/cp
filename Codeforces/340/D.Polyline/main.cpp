#include <iostream>
#include <cstdio>
#include <algorithm>
#define f first
#define s second
using namespace std;

 pair<long , long> a[3];

void read(){
    int x,y;
    for (int i = 0 ; i < 3; i++){
        cin >> x >> y;
        a[i] = make_pair(x,y);
    }
}
bool threePointsInLine(){
    bool ans= true;
    for (short i =0; i <3 ; i++){
        if (a[i].f != a[(i+1)%3].f){
            ans = false;
            break;
        }
    }
    if (!ans)
    for (short i =0; i <3 ; i++){
        if (a[i].s == a[(i+1)%3].s)
            ans = true;
        else{
            ans = false;
            break;
        }
    }

    return ans;
}

bool noPointsInLine(){
    bool ans= true;
    for (short i =0; i <3 ; i++){
        if ((a[i].f == a[(i+1)%3].f)||(a[i].s == a[(i+1)%3].s)){
            ans = false;
            break;
        }
    }
    return ans;
}

bool sortByX(const pair<long, long> &lhs, const pair<long, long> &rhs ){
    return (lhs.f < rhs.f);
}

bool sortByY(const pair<long, long> &lhs, const pair<long, long> &rhs ){
    return (lhs.s < rhs.s);
}

bool twoPointsInT() {
    bool ans = false;
    sort(a, a+3, sortByX);
    if (a[0].s == a[2].s)
        if ((a[1].s != a[0].s)&&(a[1].f != a[0].f)&&(a[1].f != a[2].f)) ans = true;

    sort(a, a+3, sortByY);
    if (a[0].f == a[2].f)
        if ((a[1].f != a[0].f)&&(a[1].s != a[0].s)&&(a[1].s != a[2].s)) ans = true;

    return ans;
}


int main()
{
    read();
    short ans;
    if (threePointsInLine()) ans = 1;
    else if (noPointsInLine()||twoPointsInT()) ans = 3;
    else ans = 2;

    cout << ans;
    return 0;
}
