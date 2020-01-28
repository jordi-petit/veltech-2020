#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // read
    vector<int> v;
    int x;
    while (cin >> x) {
        v.push_back(x);
    }

    // sort
    sort(v.begin(), v.end());

    // write
    int n = v.size();
    bool first = true;
    for (int i = 0; i < n; ++i) {
        if (first) {
            first = false;
        } else {
            cout << ' ';
        }
        cout << v[i];
    }
    cout << endl;
}
