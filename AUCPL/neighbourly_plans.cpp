#include <bits/stdc++.h>
#include <math.h>
using namespace std;

long double euclidian(long long x1, long long y1, long long x2, long long y2) {
    long long x = (x1 - x2) * (x1 - x2);
    long long y = (y1 - y2) * (y1 - y2);
    return sqrt(x + y);
}
int main(void) {
    long long tomLoc, patLoc;
    vector<pair<long long, long long>> tomPos, patPos;

    cin >> tomLoc;
    for (long long i = 0; i < tomLoc; i++) {
        long long x, y;
        cin >> x >> y;

        tomPos.push_back({x, y});
    }

    cin >> patLoc;
    for (long long i = 0; i < patLoc; i++) {
        long long x, y;
        cin >> x >> y;

        patPos.push_back({x, y});
    }

    long double minDis = INFINITY;
    pair<long long, long long> tomFinal, patFinal;

    for (long long i = 0; i < tomLoc; i++) {
        for (long long j = 0; j < patLoc; j++) {
            if (tomPos[i] == patPos[j]) {
                continue;
            }
            long double dis = euclidian(tomPos[i].first, tomPos[i].second, patPos[j].first, patPos[j].second);
            if (dis < minDis) {
                minDis = dis;
                tomFinal = tomPos[i];
                patFinal = patPos[j];
            }
        }
    }

    cout << tomFinal.first << " " << tomFinal.second << endl;
    cout << patFinal.first << " " << patFinal.second << endl;

    return 0;
}