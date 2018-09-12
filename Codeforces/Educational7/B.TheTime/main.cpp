#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int h,m,add;
    char c;
    scanf("%d %c %d\n", &h, &c, &m);
    scanf("%d", &add);
    h = (h+(m+add)/60)%24;
    m = (m+add)%60;

    if (h<10) printf("0%d:", h);
    else printf("%d:", h);
    if (m<10) printf("0%d", m);
    else printf("%d", m);
    return 0;
}
