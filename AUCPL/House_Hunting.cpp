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
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    cout << h[(n-1)/2] << endl;

    return 0;
}