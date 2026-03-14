#include <bits/stdc++.h>
using namespace std;

void f(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

int main(void) {
    f();
    string s;
    cin >> s;
    
    vector<int> freq(26, 0);
    for (char i : s) {
        freq[i-'a']++;
    }

    bool odd = false, ans = true;
    for (int i = 0; i < 26; i++) {
        if (freq[i]%2 == 0) continue;
        if (odd) ans = false;
        odd = true;
    }

    if (ans) {
        cout << "yes\n";
    } else { 
        cout << "no\n";
    }
    return 0;

}