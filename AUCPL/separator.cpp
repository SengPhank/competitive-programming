#include <bits/stdc++.h>
using namespace std;

int manhattanDistance(vector<int> param1, vector<int> param2);

struct treeNode {
    int distanceToLast;
    string name;

    vector<treeNode*> child; // multiple pointers to multple child

    treeNode(int numWords) {
        child.resize(numWords, nullptr);
    }
};

int main(void) {
    int numWords, numDimensions, minThreshold;
    cin >> numWords >> numDimensions >> minThreshold;
    map<string, vector<int>> wordMap; // {word : <feature>};

    for (int i = 0; i < numWords; i++) {
        string tempName;
        cin >> tempName;

        for (int j = 0; j < numDimensions; j++) {
            int tempDim;
            cin >> tempDim;
            wordMap[tempName].push_back(tempDim);
        }

    }

    pair<string, string> fromToWord; // <From> get to <To>
    cin >> fromToWord.first >> fromToWord.second;
    cout << fromToWord.first << " " << fromToWord.second << endl;

    treeNode* root = new treeNode(numWords); // create numWords null pointers
    root->name = fromToWord.first;
    root->distanceToLast = 2147483647;
    
    for (auto i : wordMap) {
        root >- 
    }

    int test = manhattanDistance(wordMap["Blargh"], wordMap["Plomp"]);
    cout << test << endl;
}

int manhattanDistance(vector<int> param1, vector<int> param2) {
    int dis = 0;
    for (int i = 0; i < param1.size(); i++) {
        dis += abs((param1[i] - param2[i]));
    }
    return dis;
}
