#include <bits/stdc++.h>
#include <map>
#include <set>
using namespace std;

// Problem 20 of leetCode, Difficulty : Easy
int main(void) {
    string s =  "()[]{}";
    unordered_map<char, char> brackets = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}
    };

    unordered_map<char, char> bracketsReverse = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    map<char,  int> holder;

    for (char i : s) {
        holder[i] += 1;holder[i] += 1;
    }

    for (auto i : holder) {
        cout << i.first << " : " << i.second << endl;
    }
    set<char> checkOpenClose; 
    for (auto i : holder) {
        cout << "Current: " << i.first << endl;
        if (brackets.find(i.first) != brackets.end()) { // If an opening bracket in 'brackets'
            checkOpenClose.insert(i.first); // insert an OPENING bracket to the set (to show it's used)

            // Check Count
            if (holder[brackets[i.first]] != i.second) {
                cout << "false1" << endl;
                return 1;
            }
        } else { // If a closing bracket
            if (checkOpenClose.find(bracketsReverse[i.first]) == checkOpenClose.end()){ // If closing bracket without opening bracket
                cout << "false2" << endl;
                return 1;
            }
        }
    }

    cout << "true" << endl;
    return 0;
};