#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T> string print_vector(long n, vector<T> a){
    string s = "";
    for (long i=0; i<n; i++){
        s+=to_string(a[i]);
        if (i!=n - 1) s+= " ";
    }
    return s;
}
long min_vector(vector<long> &a){
    long res = a[0];
    for (long i=1;i<a.size(); i++){
        if (a[i] < res) res = a[i];
    }
    return res;
}
int main()
{
    ifstream in;
    in.open("platform_parkour_sample_input2.txt");
    ofstream out;
    out.open("platform_parkour_sample_output.txt");
    long t;
    in >> t;
    for (long i=0; i<t; i++){
        long n, m, h1, h2, w, x, y, z, a[20], b[20], u[20], d[20];
        in >> n >> m >> h1 >> h2 >> w >> x >> y >> z;
        // generate heights
        vector<long> h(n);
        h[0] = h1;
        h[1] = h2;
        int64_t temp_hii;
        int64_t temp_hi;
        int64_t temp_w;
        int64_t temp_x;
        int64_t temp_y;
        for (long i=2; i<n; i++){
            temp_hii = h[i-2];
            temp_hi = h[i-1];
            temp_w = w;
            temp_x = x;
            temp_y = y;
            h[i] = ((temp_w*temp_hii)%z + (temp_x*temp_hi)%z + y)%z;
        }
        // read parkourers
        for (long i =0; i<m; i++){
            in >> a[i] >> b[i] >> u[i] >> d[i];
            a[i]--; b[i]--;
        }
        //
        //cout << print_vector(n, h) << endl;

        vector<long> Uxy(n-1);
        vector<long> Dxy(n-1);
        vector<vector<long>> U, D;
        for (long i=0; i<n; i++){
            U.push_back(vector<long>(0));
            D.push_back(vector<long>(0));
        }

        for (long i=0; i<m; i++){
            if (a[i] < b[i]){
                for (long j=a[i]; j<b[i]; j++){
                    U[j].push_back(u[i]);
                    D[j].push_back(d[i]);
                }
            }
            else {
                for (long j=a[i]-1; j>=b[i]; j--){
                    U[j].push_back(d[i]);
                    D[j].push_back(u[i]);
                }
            }
        }
        for (long i=0; i<n-1; i++){
            cout << U[i].size() << endl;
            Uxy[i] = *min_element(U[i].begin(), U[i].end());
            Dxy[i] = *min_element(D[i].begin(), D[i].end());
        }
        //cout << print_vector(n-1, Uxy) << endl;
        //cout << print_vector(n-1, Dxy) << endl;
        //
        for (long i=0; i<n-1; i++){
            if ((h[i+1] - h[i] < Uxy[i] && h[i+1] >= h[i]) || (h[i] - h[i+1] < Dxy[i] && h[i] >= h[i+1])){
                if (i+2 != n-1) {
                    if (h[i+2] >= h[i+1]) // increase
                        h[i+1] = h[i]+Uxy[i];
                    if (h[i+2] < h[i+1])
                        h[i+1] = h[i]-Dxy[i];
                }
            }
        }
        vector<double> dd(n-1);
        for (long i=0; i<n-1; i++){
            if (h[i+1] > h[i]){
                if (h[i+1] - h[i] > Uxy[i])
                    dd[i] = (h[i+1] - h[i] - Uxy[i])/2.0;
            } else {
                if (h[i] - h[i+1] > Dxy[i])
                    dd[i] = (h[i+1] - h[i] + Dxy[i])/2.0;
            }
        }
        //cout << print_vector(n-1, dd) << endl;
        // calculate delta h
        vector<double> dh(n, 0);
        for (long i=0; i<n-1; i++) dh[0]+=dd[i];
        for (long i=1; i<n; i++){
            dh[i] = dh[i-1] - 2*dd[i-1];
        }
        //cout << print_vector(n, dh) << endl;
        double res = (*max_element(dh.begin(), dh.end()) - *min_element(dh.begin(), dh.end()))/2.0;
        out << "Case #" << i+1 << ": " << res;
        if (i!=t-1) out << endl;
    }
    return 0;
}
