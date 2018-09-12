#include <iostream>
#include <fstream>

using namespace std;

bool isSubstr(string a, string b){
    int i=1, j=1;
    do {
        if (i > a.length()) return true;
        if (j > b.length()) return false;
        if (a[i-1] == b[j-1]) {
            i++; j++;
        }
        else {
            if (i==1)
                j++;
            else i=1;
        }
    } while (1);
}
int main()
{
    ifstream in;
    in.open("ethan_searches_for_a_string.txt");
    ofstream out;
    out.open("ethan_searches_for_a_string_output.txt");
    int t;
    in >> t;
    for (int i=0; i<t; i++){
        string s;
        string r = "";
        int index = 0;
        in >> s;
        for (int j=1; j<s.length(); j++){
            if (s[j] == s[0]) {
                index = j;
                break;
            }
        }
        if (index > 0) r = s.substr(0, index) + s;
        if (r == "") r = "Impossible";
        else {
            if (isSubstr(s, r)) r = "Impossible";
        }
        out << "Case #" << i+1 << ": " << r;
        if (i!=t-1) out << endl;
    }
}
