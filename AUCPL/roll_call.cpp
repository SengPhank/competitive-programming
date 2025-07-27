#include <bits/stdc++.h>
using namespace std;

void printRev(string s) {
    stringstream ss(s);
    vector<string> temp;

    while (getline(ss, s, ' ')){ // Put string into vector split by space
        temp.push_back(s);
    }

    for (int i = temp.size() - 1; i >= 0; i--) {
        if (!(i == 0)) {
            cout << temp[i] << ' ';
        } else {
            cout << temp[i];
        }
    }
    cout << endl;
}
int main(void) {
    int numStudents;
    vector<string> studentName;

    cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        string fName, lName;

        cin >> fName >> lName;

        string z = lName + " " + fName;
        studentName.push_back(z);
    }

    sort(studentName.begin(), studentName.end(), [](auto a, auto b){
        if (a < b) {
            return false;
        }
        return true;
    });
    
    for (auto  i : studentName) {
        printRev(i);
    }

    return 0;
    
}

