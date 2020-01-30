#include <iostream>
#include <vector>
using namespace std;

void write(const vector<int>& v, int n)
{
    bool first = true;
    for (int x : v) {
        if (first) {
            first = false;
        } else {
            cout << ' ';
        }
        cout << x;
    }
    cout << endl;
}

void rec(vector<int>& v, int n, int i)
{
    if (i == n) {
        write(v, n);
    } else {
        v[i] = 0;
        rec(v, n, i + 1);
        v[i] = 1;
        rec(v, n, i + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    rec(v, n, 0);
}
