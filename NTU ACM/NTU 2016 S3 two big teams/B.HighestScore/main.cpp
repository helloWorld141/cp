#include <iostream>
#include <priority_queue>

using namespace std;
struct goodie{
    long Pet;
    long Jan;
};

priority_queue<goodie, cmp> p;
priority_queue<goodie, cmp> j;

void
int main()
{
    scanf("%d", &n);
    goodie temp;
    for (int i =0; i<n; i++){
        scanf("%d %d", &temp.Pet, &temp.Jan);
        p.push(temp);
        j.push(temp);

    }

    return 0;
}
