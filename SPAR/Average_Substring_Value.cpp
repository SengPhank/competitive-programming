#include <bits/stdc++.h>
#include <string>
using namespace std;

int max(vector<int> myArr) {
    int maxNum = myArr[0];

    for (int i = 1; i < myArr.size()-1; i++) {
        if (myArr[i] > maxNum) {
            maxNum = myArr[i];
        }
    }

    return maxNum;
}
int main(void) {
    string s;
    cin >> s;
    int sLen = s.size();

    int lPtr = 0;
    int rPtr = lPtr + 1;
    for (int i = 0; i < sLen; i++) {
        if (rPtr > sLen) {
            lPtr++;
            int rPtr = lPtr + 1;
        }

        for (int j = lPtr; j < rPtr; j++){
            sum += max(std::stoi(s[i]), std::stoi(s[j]));
            attempts++;
        }
        
    }

    cout << sum/attempts << endl;
    return 0;   
}