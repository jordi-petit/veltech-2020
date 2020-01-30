#include <iostream>
#include <vector>
using namespace std;

void write(const vector<int>& v, int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (v[j] == i) {
                cout << 'Q';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
    cout << endl;
}

void rec(vector<int>& v, int n, int i, vector<int>& used, vector<int>& used1, vector<int>& used2)
{
    if (i == n) {
        write(v, n);
    } else {
        for (int j = 0; j < n; ++j) {
            int d1 = i + j;
            int d2 = n - i + j - 1;
            if (not used[j] and not used1[d1] and not used2[d2]) {
                v[i] = j;
                used[j] = used1[d1] = used2[d2] = 1;
                rec(v, n, i + 1, used, used1, used2);
                used[j] = used1[d1] = used2[d2] = 0;
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
    vector<int> used1(2 * n - 1, 0);
    vector<int> used2(2 * n - 1, 0);
    rec(v, n, 0, used, used1, used2);
}
