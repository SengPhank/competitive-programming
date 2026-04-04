#include <bits/stdc++.h>
using namespace std;

void f(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

vector<long long> getPrimes(int m) {
    int n = 10e5 + 5000;
    vector<bool> primes(n, true);
    primes[0] = false, primes[1] = false;
    
    for (int p = 2; p*p <= n; p++) {
        if (primes[p]) {
            for (int i = p*p; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }
    vector<long long> res;
    for (int i = 0; i < n; i++) {
        if (res.size() > m) break;
        if (primes[i]) {
            res.push_back(i);
        }
    }
    return res;
}
int main(void) {
    f();
    int t;
    cin >> t;
    // let a, b, c, d, ... be primes
    // gcd(ab, bc) = b (common factor)
    // hence, return a, ab, bc, cd, de, ...
    int maxQ = 0;
    vector<int> queries(t);
    for (int i = 0; i < t; i++) {
        cin >> queries[i]; 
        maxQ = max(maxQ, queries[i]);        
    }

    vector<long long> primes = getPrimes(maxQ);
    // out
    for (int i : queries) {
        for (int j = 0; j < i; j++) {
            cout << primes[j]*primes[j+1] << " ";
        }
        cout << "\n";
    }
    return 0;
}