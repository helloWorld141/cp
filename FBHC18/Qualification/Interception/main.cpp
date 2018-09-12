#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in;
    in.open("interception.txt");
    ofstream out;
    out.open("interception_output.txt");
    int t;
    in >> t;
    for (int i=0; i<t; i++){
        int n;
        int p;
        in >> n;
        for (int j=0; j<=n; j++) in >> p;
        int nx = 0;
        if (n%2 == 1) nx = 1;
        out << "Case #" << i+1 <<": " << nx;
        if (nx > 0) out << endl << "0.0";
        if (i != t-1) out << endl;
    }
}
