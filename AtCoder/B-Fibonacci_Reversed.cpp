#include <bits/stdc++.h>
using namespace std;

long long rev(long long a) {
    string s = to_string(a);
    reverse(s.begin(), s.end());
    return stoll(s);
}
long long fib(int index, unordered_map<long long, long long>& memo) {
    if (memo.count(index)) return memo[index];
    memo[index] = rev(fib(index-1, memo) + fib(index-2, memo));
    return memo[index];
}
int main(void) {
    long long x, y;
    cin >> x >> y;
    unordered_map<long long, long long> memo;
    memo[0] = x;
    memo[1] = y;  
    cout << fib(9, memo) << endl;
    return 0;
}