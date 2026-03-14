#include <bits/stdc++.h>
using namespace std;

void f(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

int main(void) {
    f();    
    long long t, a, b, da, db;
    cin >> t >> a >> b >> da >> db;
    a = max(0LL, a-(t*da));
    b = max(0LL, b-(t*db));
    double per = (double) a /(a+b);
    cout << std::fixed << std::setprecision(15) << per*100 << endl;
    return 0;
}