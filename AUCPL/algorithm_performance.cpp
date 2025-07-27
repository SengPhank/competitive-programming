    #include <bits/stdc++.h>
    using namespace std;

    int main(void) {
        int n;
        vector<int> time;

        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            time.push_back(x);
        }

        sort(time.begin(), time.end());

        cout << time[3] << endl;
        
        return 0;
    }