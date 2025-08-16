#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int printJobs;
    cin >> printJobs;

    // only if b.second is greater than a.second do we switch
    auto cmp = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        if (get<1>(a) == get<1>(b)) {
            // only switch a and b if b has  a lower time
            return get<2>(a) > get<2>(b);
        }
        return get<1>(a) < get<1>(b); 
    };

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> pq(cmp); // {ID, PRIORITY, TIME}
    string sTemp;
    int tempID, tempPri, time;

    for (int i = 0; i < printJobs; i++) {
        cin >> sTemp;
        if (sTemp == "print") {
            if (pq.empty()) {
                cout << "ERROR" << endl;
            } else {
                cout << get<0>(pq.top()) << endl;
                pq.pop();
            }
        } else {
            tempID = stoi(sTemp);
            cin >> tempPri;
            pq.push({tempID, tempPri, time++});
        }
    }

    return 0;
}