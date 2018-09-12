#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ;
    scanf("%d\n\n", &n);
    //ofstream f;
    //f.open("output.txt");
    while (n--) {
        char name[33];
        map<string, int> a;
        int total = 0;
        while (gets(name)) {
            if (strlen(name) == 0) break;
            if (a.find(string(name)) == a.end()) a[string(name)]=1;
            else a[string(name)]+=1;
            total++;
        }

        map<string,int>::iterator it;
        for (it=a.begin(); it != a.end(); it++) {
            double ans = ((double)(it->second)/total*100.0);
            cout.precision(4);
            cout << fixed;
            cout << (it -> first) << ' ' << ans << endl;
        }
        if (n!=0) cout << endl;
    }
    //f.close();
    return 0;
}
/*
2

Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow

Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow
*/
