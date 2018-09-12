#include <iostream>

using namespace std;

int day(string a) {
    if (a.compare("monday") == 0)
        return 0;
    if (a.compare("tuesday") == 0)
        return 1;
    if (a.compare("wednesday") == 0)
        return 2;
    if (a.compare("thursday") == 0)
        return 3;
    if (a.compare("friday") == 0)
        return 4;
    if (a.compare("saturday") == 0)
        return 5;
    if (a.compare("sunday") == 0)
        return 6;


}
int main()
{
    string a,b;
    cin >> a >> b;
    int aa = day(a);
    int bb = day(b);

    int mod = (bb - aa)%7;
    if (mod < 0) mod += 7;
    if ((mod == 0) || (mod == 2) || (mod == 3))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
