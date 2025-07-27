#include <bits/stdc++.h>
#include <cmath>
using namespace std;

long double findRoot(long long balls) {
    long long a = 1, b = 3, c = 2, d = -6 * balls;

    long double p = (3*a*c - b*b) / (3*a*a);
    long double q = (2*b*b*b - 9*a*b*c + 27*a*a*d) / (27*a*a*a);

    // Discriminant
    long double discriminant = (q*q / 4) + (p*p*p / 27);

    if (discriminant >= 0) {
        long double u = cbrt(-q/2 + std::sqrt(discriminant));
        long double v = cbrt(-q/2 - std::sqrt(discriminant));
        return u + v - (b / (3 * a));

    } else {
        return NAN;
    }
}

int main(void) {
    long long numCustomers;
    cin >> numCustomers;

    for (long long i = 0; i < numCustomers; i++) {
        long long numBalls; 
        cin >> numBalls;
        long double res = findRoot(numBalls);
        cout << floor(lround(res* 1000000) / 1000000) << endl;
    }
    

    return 0;
}