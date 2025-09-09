#include <bits/stdc++.h>
using namespace std;

int main(void) {
    unordered_map<string, int> mapping = {
        //GFEDCBA
        {"0111111", 0},
        {"0000110", 1},
        {"1011011", 2},
        {"1001111", 3},
        {"1100110", 4},
        {"1101101", 5},
        {"1111101", 6},
        {"0000111", 7},
        {"1111111", 8},
        {"1101111", 9}
    };

    string a, b;
    cin >> a >> b;
    string res = "";
    for (int i = 0; i < 7; i++) {
        if (a[i] == '1' || b[i] == '1') {res += "1";
        } else {
            res += "0";
        }
    }

    if (mapping.count(res) || res == "0111111") {
        cout << mapping[res] << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}