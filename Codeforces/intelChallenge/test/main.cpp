#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int a = stoi(s);
    string b = to_string(a);
    cout << b;
    return 0;
}
