#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(void) {
    int numWardrobe, numDays;
    vector<string> ans; 
    set<string> wardrobe; 

    cin >> numWardrobe;
    for (int i = 0; i < numWardrobe; i++) {
        string cloth;
        cin >> cloth;
        wardrobe.insert(cloth);
    }

    cin >> numDays;
    for (int i = 0; i < numDays; i++) {
        string constraint;

        cin >> constraint; // Yes or NO

        if (constraint == "Yes") {
            string temp;
            cin >> temp;

            auto val = wardrobe.insert(temp);
            if (val.second) { // Success (No cloth)
                cout << "No" << endl;
                return 0;
            } else {
                ans.push_back(temp);
            }
        } else if (constraint == "No") {
            set<string> canWear = wardrobe;
            int numConstraints;

            cin >> numConstraints;
            for (int j = 0; j < numConstraints; j++) {
                string rmv;
                cin >> rmv;
                canWear.erase(rmv);
            }

            if (canWear.empty()) {
                cout << "No" << endl;
                return 0;
            } else {   
                auto a = canWear.begin();
                ans.push_back(*a);
            }
        }
    }

    for (auto i : ans) {
        cout << i << endl;
    }
}