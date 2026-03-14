#include <bits/stdc++.h>
using namespace std;

void f(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

int main(void) {
    f();    
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << a;
    } else if (a > b) {
        cout << 0;
    } else {
        cout << a+1;
    }
    return 0;
}