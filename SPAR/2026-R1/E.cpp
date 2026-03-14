#include <bits/stdc++.h>
using namespace std;

void f(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

int main(void) {
    f();    
    int n;
    cin >> n;
    cout << "1 " << n << endl;
    int perc = 0, rem = 125;
    vector<int> v(n);
    while (perc < 70 && rem--) {
        int ones = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] == 1) ones++;
        }
        if (((double)ones/n) * 100 >= 70) break;
        cin >> perc;

        // find longest contig
        int sz = (v[0] == 0);
        int maxSz = 0, cl = (v[0] != 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (v[i] != 0) {
                if (sz > maxSz) {
                    maxSz = sz;
                    l = cl;
                    r = i-1;
                }
                cl = i+1;
                sz = 0;
            } else {
                sz++;
            }
        }
        if (sz > maxSz) {
            l = cl;
            r = n-1;
        }
        cout << l+1 << " " << r+1 << endl;
    }
    return 0;
}