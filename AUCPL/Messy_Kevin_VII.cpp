#include <bits/stdc++.h>
using namespace std;

int main(void) {
    auto custom = [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) return a.second > b.second; // priority
        return a.first > b.first; // total duration
    };

    // {study duration (if same, which task has a longer duration), priority (higher)}
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(custom)> study(custom); 
    priority_queue<int, vector<int>, greater<int>> breaks; // shortest break first

    int s, b;
    cin >> s >> b;

    for (int i = 0; i < s; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        study.push({t1, t2});
    }

    for (int i = 0; i < b; i++) {
        int t1;
        cin >> t1;
        breaks.push(t1);
    }

    // You may have two consecutive study tasks if there are
    // no more breaks remaining. However, you cannot have two consecutive breaks.
    int totalStudy = 0;
    int totalBreaks = 0;
    bool lastBreak = false;
    int numStudied = 0;
    int timeLeft = 720; // 9am-9pm, in minutes
    bool swi = true;
    while (swi) {
        swi = false;
        // Find most doable study in time frame
        while (!study.empty() && study.top().first > timeLeft) {
            study.pop();
        }

        // attempt to study
        if (!study.empty() && numStudied < 2) {
            timeLeft -= study.top().first;
            totalStudy = study.top().first;
            study.pop();
            lastBreak = false;
            numStudied++;
            swi = true;
        }
        
        while (!breaks.empty() && breaks.top() > timeLeft) {
            breaks.pop();
        }
        // Attemp to have a break
        if (!lastBreak && !breaks.empty()) {
            timeLeft -= breaks.top();
            totalBreaks = breaks.top();
            breaks.pop();
            numStudied = 0;
            lastBreak = true;
            swi = false;
        }
    }

    cout << totalStudy << " " << totalBreaks << endl;
    return 0;
}