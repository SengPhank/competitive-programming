#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(void) {
    int numStudents;
    int k;
    int ans = 0;
    map<int, int> record;
    cin >> numStudents >> k;

    for (int i = 0; i < numStudents; i++) {
        int score;
        cin >> score;
        record[score] += 1;
    }

    int index1 = 0, index2 = 0;
    for (auto i : record) {
        for (auto j : record) {
            if (index1 == index2) {
                continue;
            }
            if (abs(i.first - j.first) == k) {
                if (i.first > j.first) {
                    ans++;
                }
            }
            index2++;
        }
        index1++;
        index2 = 0;
    }

    if (k == 0) {
        for (auto i : record) {
            if (i.second > 1) {
                if (i.second == 2) {
                    ans += 1;
                } else {
                    ans += i.second;
                }
            }
        }
    }
    

    cout << ans << endl;
    return 0;
}