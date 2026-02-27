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
        string s;
        cin >> n;
        cin >> s;
        stack<char> prev;
        for (int i = 0; i < n; i++) {
            if (!prev.empty() && s[i] == prev.top()) {
                prev.pop();
            } else {
                prev.push(s[i]);
            }
        }
        if (prev.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0; 
}
