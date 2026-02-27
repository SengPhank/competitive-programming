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
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int prev = INT_MIN;
        bool notdec = false;
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if (tmp < prev) notdec = true;
            prev = tmp;
        }
        if (notdec) {
            cout << 1 << endl; 
        } else {
            cout << n << endl;
        }
    }
    return 0;
}


// 1 2 7 6