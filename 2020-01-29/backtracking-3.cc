#include <iostream>
#include <vector>
using namespace std;

void write(const vector<int>& v, int n)
{
    cout << '(';
    bool first = true;
    for (int x : v) {
        if (first) {
            first = false;
        } else {
            cout << ',';
        }
        cout << x + 1;
    }
    cout << ')' << endl;
}

void rec(vector<int>& v, int n, int i, vector<int>& used)
{
    if (i == n) {
        write(v, n);
    } else {
        for (int j = 0; j < n; ++j) {
            if (not used[j]) {
                v[i] = j;
                used[j] = 1;
                rec(v, n, i + 1, used);
                used[j] = 0;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> used(n, 0);
    rec(v, n, 0, used);
}
