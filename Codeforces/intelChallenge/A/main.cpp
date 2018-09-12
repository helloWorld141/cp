#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    int format;
    cin >> format;
    string time;
    cin >> time;
    string hh = time.substr(0, 2);
    string mm = time.substr(3 ,4);
    int h = atoi(hh.c_str());
    int m = atoi(mm.c_str());

    if (m > 59) {
        m = 30 + m%10;
    }
    if (format == 12) {
        if (h == 0) {
            h = 10;
        }
        if (h > 12) {
            if (h % 10 != 0)
                h = h % 10;
            else h = 10;
        }


    }
    else {
        if (h > 23) {
            if (h % 10 != 0)
                h = h % 10;
            else h = 10;
        }
    }

    char buffer1[33];
    char buffer2[33];
    char *strh = itoa(h, buffer1, 10);
    char *strm = itoa(m, buffer2, 10);
    string newh;
    string newm;
    if (h < 10) {
        newh = '0' + string(strh);
    }
    else newh = string(strh);

    if (m < 10) {
        newm = '0' + string(strm);
    }
    else newm = string(strm);

    cout << newh << ':' << newm << endl;
    return 0;
}
