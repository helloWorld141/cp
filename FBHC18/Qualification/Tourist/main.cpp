// Qualification round. score: 25
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
#include <fstream>
using namespace std;

int main()
{
    ifstream in;
    in.open("tourist.txt");
    ofstream out;
    out.open("tourist_output.txt");
    int t;
    in >> t;
    for (int i=0; i<t; i++){
        int n,k;
        int64_t v;
        vector<string> s;
        in >> n >> k >> v;
        for (int j =0; j<n; j++){
            string temp;
            in >> temp;
            s.push_back(temp);
        }
        int start = (k*(v-1))%n;
        vector<int> index;
        for (int j=0; j<k; j++){
            index.push_back((start+j)%n);
        }
        sort(index.begin(), index.end());
        string names = "";
        for (int j=0; j<k; j++){
            names += s[index[j]];
            if (j!=k-1) names+=" ";
        }
        out << "Case #" << i+1 << ": " << names;
        if (i!=t-1) out << endl;
    }
    return 0;
}

//6
//4 1 3
//LikeSign
//Arcade
//SweetStop
//SwagStore
//4 4 100
//FoxGazebo
//MPK20Roof
//WoodenSculpture
//Biryani
//4 3 1
//LikeSign
//Arcade
//SweetStop
//SwagStore
//4 3 3
//LikeSign
//Arcade
//SweetStop
//SwagStore
//4 3 10
//LikeSign
//Arcade
//SweetStop
//SwagStore
//2 1 1000000000000
//RainbowStairs
//WallOfPhones
