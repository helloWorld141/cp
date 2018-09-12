#include <iostream>
#include <math.h>
#include <vector>

struct point {
    long int x;
    long int y;
};

int n;
point arr[2000];
short included[2000];
long int sumDis[2000];
point f1,f2;
using namespace std;

long long int  square_distance(point A, point B){
    return((long long)( pow((double)(A.x-B.x), 2) + pow((double)(A.y-B.y), 2) ));
}
void read(){
    cin >> n >> f1.x >> f1.y >> f2.x >> f2.y;
    for (int i = 0; i< n; i++){
        cin >>arr[i].x >> arr[i].y;
        sumDis[i] = square_distance(arr[i], f1) + square_distance(arr[i], f2);
    }
}

void Swap_point(point *A, point *B){
    int temp;
    temp = (*A).x;
    (*A).x = (*B).x;
    (*B).x = temp;

    temp = (*A).y;
    (*A).y = (*B).y;
    (*B).y = temp;

}

void Swap(long int *A, long int *B){
    int temp;
    temp = (*A);
    (*A) = (*B);
    (*B) = temp;
}
void BubbleSort(){
    for (int i = 0; i <n-1 ; i++){
        for (int j = i+1; j<n ; j++){
            if (sumDis[i] < sumDis[j]){
                Swap_point(&arr[i], &arr[j]);
                Swap(&sumDis[i], &sumDis[j]);
            }
        }
    }
}


int main()
{
    read();
    // UNSUCCESSFUL APPROACH
    /*BubbleSort();
    long int r1 = 0, r2 = 0 ;
    for (int i = 0 ; i < n; i++){
        int dis1 = square_distance(arr[i], f1);
        int dis2 = square_distance(arr[i], f2);
        if (dis1 <= r1) included[i] = 1;
        else if (dis2 <= r2) included [i] = 2;
        if (included[i] == 0){
            if (dis1 > dis2){
                r2 = dis2;
                included[i] = 2;
            }
            else {
                r1 = dis1;
                included[i] = 1;
            }
        }

    }
    cout << r1+r2;
    */

    // ANOTHER APPROACH (SUCCESSFUL)
    vector<pair< unsigned long long , unsigned long long >> disToF;
    disToF.push_back(make_pair(0,0));
    unsigned long long r1,r2,ans;

    for (int i =1; i<= n ; i++){
        r1 = square_distance(arr[i-1], f1);
        r2 = square_distance(arr[i-1], f2);
        disToF.push_back(make_pair(r1,r2));
    }

    for (int i = 0 ; i <= n; i++){
        r1 = disToF[i].first;
        r2 = 0 ;
        for (int j = 1; j<=n; j++){
            if (disToF[j].first > r1){
                r2 = max(r2, disToF[j].second);
            }
        }
    ans = min(ans, r2+r1);
    }
    cout << ans;

    return 0;
}
