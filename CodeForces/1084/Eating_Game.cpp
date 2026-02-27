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
        int highest = INT_MIN;
        int sol = 1;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            if (temp > highest) {
                highest = temp;
                sol = 1;
            } else if (temp == highest) {
                sol++;
            }
        }
        cout << sol << endl;
    }
    return 0;
}