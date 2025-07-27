#include <bits/stdc++.h>
#include <set>
using namespace std;

string backTracking(int numDays, int curDay, set<string> fullDrobe) {
    string rule;
    set<string> curDayDrobe = fullDrobe;

    cin >> rule;
    if (rule == "No") {
        int constraint;
        cin >> constraint;

        // Remove from today's drobe
        for (int i = 0; i < constraint; i++) {
            string temp;
            cin >> temp;
            curDayDrobe.erase(temp);
        }
        
        // Forward to tomorrow
        string wearingTomorrow = backTracking(numDays, curDay + 1, fullDrobe);
        curDayDrobe.erase(wearingTomorrow);
        
        return *curDayDrobe.begin(); // Return what you're wearing today
    } else {
        // Start backtracking
        string requiredColor;
        cin >> requiredColor;
        
        if (curDayDrobe.find(requiredColor) != curDayDrobe.end()){ // If required color exists
            return requiredColor;

        } else { // No color exists
            cout << "No" << endl;
            return "No";
        }
    }
}
// Can not wear the same color 2 days in a row
int main(void) {
    int numWardrobe, numDays;
    set<string> wardrobe; 

    cin >> numWardrobe;
    for (int i = 0; i < numWardrobe; i++) {
        string cloth;
        cin >> cloth;
        wardrobe.insert(cloth);
    }


    cin >> numDays;

    if (!(backTracking(numDays, 1, wardrobe, ""))) { // start day 1
        cout << "No" << endl;
    } else {
        cout << "Yees!!@!@!#!@#" << endl;
    }
}