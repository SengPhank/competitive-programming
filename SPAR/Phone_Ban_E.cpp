#include <bits/stdc++.h>
using namespace std;

int main(void) {
    unordered_map<string, int> codePen = {
        {"GDX", 5},
        {"SNK", 15},
        {"PRV", 25},
        {"TWO", 20},
        {"LNO", 15}, 
        {"LRB", 10}
    };

    int week;
    cin >> week;

    string name, code;
    unordered_map<string, int> studentPoints;
    vector<string> nameOrder;
    set<string> track;
    while (1) {
        cin >> name;
        if (name == "END") { break; }
        cin >> code;
        
        studentPoints[name] += (codePen.count(code)) ? codePen[code] : 0;
        if (!track.count(name)) {
            track.insert(name);
            nameOrder.push_back(name);
        }
    }

    bool numB1 = true, numB2 = true;
    cout << "Week " << week << endl;
    cout << "Students for detention:" << endl;

    vector<string> extraBaddies;
    for (string i : nameOrder) {
        if (!track.count(i)) { continue; }
        if (studentPoints[i] > 50) {
            extraBaddies.push_back(i);
        } else if (studentPoints[i] > 30) {
            cout << i << " "; 
            numB1 = false;
        }
        track.erase(i);
    }
    if (numB1) {
        cout << "None";
    }
    cout << endl; 

    cout << "Parental meeting for:" << endl;
    for (string i : extraBaddies) {
        cout << i << " "; 
        numB2 = false;
    }
    if (numB2) {
        cout << "None";
    }
    cout << endl; 

    return 0;

}