#include <bits/stdc++.h>
#define vi vector<int>
#define go(i,from,to) for (int i= from; i<to; i++)
using namespace std;

class UnionFind{
public:
    vi p,rankk, sizee;
    int n, numDS;
    UnionFind(int n) {
        this -> n = n ;
        numDS = n;
        p.assign(n,0); rankk.assign(n,0); sizee.assign(n, 1);
        go(i,0,n) p[i] = i;
    }

    int findSet(int i){
        if (p[i] == i) return i; else return p[i] = findSet(p[i]);
    }

    //bool isSameSet(int i, int j) {return findSet(i) == findSet(j);    }

    void unionSet(int i, int j){
        int x = findSet(i); int y = findSet(j);
        if (x != y) {
            if (rankk[x] <= rankk[y]) {p[x] = y; sizee[y]+=sizee[x];}
            else {p[y] = x; sizee[x]+= sizee[y];}
            if (rankk[x] == rankk[y]) rankk[y]++;
            numDS--;
        }
    }

    int numDisjointSets() {return numDS;}

    int sizeOfSet(int i) {return sizee[findSet(i)]; }
};

void print(UnionFind ds) {
    cout << "The number of disjoint sets: " << ds.numDisjointSets()<< endl;
    go(i,0,ds.n) cout << ds.p[i] << ' '; cout << endl;
    go(i,0,ds.n) cout << ds.rankk[i] << ' '; cout << endl;
    go(i,0,ds.n) cout << ds.sizee[i] << ' '; cout << endl;
}

int main()
{
    UnionFind fr(10);
    fr.unionSet(3,5);
    fr.unionSet(5,6);
    fr.unionSet(2,4);
    fr.unionSet(2,3);
    fr.unionSet(2,6);
    print(fr);
    return 0;
}
