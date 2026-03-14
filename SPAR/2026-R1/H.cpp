#include <bits/stdc++.h>
using namespace std;

void f(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

int main(void) {
    f();    
    string a, b, c;
    cin >> a >> b >> c;
    int an = a.size(), bn = b.size(), cn = c.size();
    int ai = 0, bi = 0, ci = 0;
    string sol = string();
    while (ai < an || bi < bn || ci < cn) {
        if (ai < an && bi < bn && a[ai] == b[bi]) {
            sol += a[ai];
            ai++;
            bi++;
        } else if (ai < an && ci < cn && a[ai] == c[ci]) {
            sol += a[ai];
            ai++;
            ci++;
        } else if (bi < bn && ci < cn && b[bi] == c[ci]) {
            sol += b[bi];
            bi++;
            ci++;
        }
    }
    cout << sol << endl;
    
    return 0;
}