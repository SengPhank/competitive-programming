#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int numChanges;
    cin >> numChanges;
    
    double price = 0, paid, temp;
    for (int i = 0; i < numChanges; i++) {
        cin >> temp;
        price += temp;
    }
    cin >> paid;
    std::cout << std::fixed << std::setprecision(2);
    cout << "Total price: $" << price << endl;
    if (fmod(price, 0.1) != 0) {
        if (fmod(price, 0.1) * 100 <= 4) {
            price -= fmod(price, 0.1);
        } else {
            price = ceil(price);
        }
    }
    cout << "Rounded price: $" << price << endl;
    paid -= price;
    cout << "Change: $" << paid << endl;

    return 0;
}