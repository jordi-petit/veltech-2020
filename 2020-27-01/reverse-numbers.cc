#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int x;
    while (cin >> x) {
        v.push_back(x);
    }
    int n = v.size();
    for (int i = n - 1; i >= 0; --i) {
        cout << v[i] << endl;
    }
    v.pop_back();
}
