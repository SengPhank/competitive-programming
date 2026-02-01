#include <bits/stdc++.h>
using namespace std;

void op(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
}

int main(void) {
    op();
    int n;
    cin >> n;
    if (n < 5) {
        cout << "No" << endl;
        return 0;
    }
    
    for (int i = 0; i < 10; i++) {
        int t;
        cin >> t;
        if (t < 5) {
            cout << "No" << endl;
            return false;
        }
    }
    cout << "Yes" << endl;
    return 0;
}