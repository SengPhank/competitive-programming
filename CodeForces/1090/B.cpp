#include <bits/stdc++.h>
using namespace std;

void f(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

int main(void) {
    f();
    int t;
    cin >> t;
    while (t--) {
        int n, sums = 0, m = INT_MIN;
        for (int i = 0; i < 7; i++) {
            cin >> n;
            sums -= n;
            m = max(m, n);
        }
        cout << sums + m + m << endl;
    }
}