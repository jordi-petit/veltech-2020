#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> amounts;

    // first phase
    string name, action;
    while (cin >> name >> action) {
        if (action == "enters") {
            if (amounts.count(name)) {
                cout << name << " is already in the casino" << endl;
            } else {
                amounts[name] = 0;
            }
        } else if (action == "leaves") {
            if (not amounts.count(name)) {
                cout << name << " is not in the casino" << endl;
            } else {
                cout << name << " has won " << amounts[name] << endl;
                amounts.erase(name);
            }
        } else if (action == "wins") {
            int money;
            cin >> money;
            if (not amounts.count(name)) {
                cout << name << " is not in the casino" << endl;
            } else {
                amounts[name] += money;
            }
        } else {
            cerr << "ERROR!" << endl;
        }
    }

    // second phase
    cout << "----------" << endl;
    for (auto pair : amounts) {
        cout << pair.first << " is winning " << pair.second << endl;
    }
}
