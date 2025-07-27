#include <bits/stdc++.h>
using namespace std;

// Problem 22 of Leetcode, difficulty : Medium

void printVector(const vector<string>& myVec) {
    cout << "[";
    for (size_t i = 0; i < myVec.size(); i++) {
        cout << myVec[i];  
        if (i < myVec.size() - 1) {
            cout << ", ";  
        }
    }
    cout << "]" << endl;  
}

int main(void) {
    int n = 3;
    vector<string> ans(n); 
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (i+1); j++){
            ans[i] += "(";
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (i+1); j++){
            ans[i] += ")";
        }
    }

    // answer
    printVector(ans);
    return 0;
}