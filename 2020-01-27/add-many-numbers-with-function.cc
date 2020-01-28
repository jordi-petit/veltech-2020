#include <iostream>
#include <vector>
using namespace std;

int sum(const vector<int>& v)
{
    v[0] = 99;
    int s = 0;
    for (int x : v) {
        s += x;
    }
    return s;
}

int main()
{
    vector<int> v;
    int x;
    while (cin >> x) {
        v.push_back(x);
    }

    int s = sum(v);

    cout << s << endl;
}
