#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printVec(vector<char> arrParam) {
    cout << "[";
    for (auto i : arrParam) {
        cout << i;
    }
    cout << "]" << endl;
}
bool isLetter(char character) {
    if ((character >= 65 && character <= 90) || (character >= 97 && character <= 122)) {
        return true;
    }
    
    return false;
}

char toLower(char character) {
    if (character >= 97 && character <= 122) {
        return (character - 32); // return upper
    }
    return character;
}

string removeSpecialToLower(string message) {
    string newMSG = "";
    for (auto i : message) {
        if (isLetter(i)) {
            newMSG += towlower(i);
        }
    }

    return newMSG;
}
vector<char> encrypt(string keys, string message) {
    // Remove all non-alphabetical characters, concert to lower.
    message = removeSpecialToLower(message);
    int vecSize = message.size();
    int numPlaced = 0;
    int letterPlacement;
    vector<char> ans(vecSize, '0'); // answer

    for (int i = 0; i < keys.size(); i++) { // for each key
        letterPlacement = (keys[i] - 96);
        cout << "letter placement of " << keys[i] << " is: " << (int) keys[i] << ", modified is: " << letterPlacement << endl;
        if (i % 2 == 0) { // going left (first) to right, alternating
           for (int j = 0; j < vecSize; j++) { // loop through current 'available' vector size
                if ((j+1) % letterPlacement == 0) { 
                    ans[j + letterPlacement] = message[numPlaced];
                    numPlaced++;
                }
                printVec(ans);
            }     
        }       
        
    }
    
    return ans;


}
int main(void) {
    string cryptionType, cryptionKey;
    string cryptionMSG;
    cin >> cryptionType >> cryptionKey >> cryptionMSG;

    vector<char> newMSG;
    if (cryptionType == "E") {
        newMSG = encrypt(cryptionKey, cryptionMSG);
    }


    cout << "New message: " << endl;
    for (auto i : newMSG) {
        cout << i;
    }
    cout << endl;

    return 0;
}