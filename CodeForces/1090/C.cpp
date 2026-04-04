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
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cout << i << " " << i + (n+i-1) << " " << i + (n+i-1) + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}