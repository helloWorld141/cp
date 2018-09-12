#include <iostream>
using namespace std;

void test(int i) {
    while (1) {
        cout << i++ << endl;
        if (i == 1000 ) exit(0);
    }
}

int main() {
    int i =0;
    test(i);
    return 0;
}
