#include <iostream>
#include <vector>
using namespace std;

void write(const vector<int>& v, int n, const vector<string>& words)
{
    bool first = true;
    cout << '{';
    for (int i = 0; i < n; ++i) {
        if (v[i] == 1) {
            if (first) {
                first = false;
            } else {
                cout << ',';
            }
            cout << words[i];
        }
    }
    cout << '}';
    cout << endl;
}

void rec(vector<int>& v, int n, int i, const vector<string>& words)
{
    if (i == n) {
        write(v, n, words);
    } else {
        v[i] = 0;
        rec(v, n, i + 1, words);
        v[i] = 1;
        rec(v, n, i + 1, words);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    vector<int> v(n);
    rec(v, n, 0, words);
}
