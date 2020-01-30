#include <iostream>
#include <set>
#include <vector>
using namespace std;

using Sudoku = vector<vector<set<int>>>;

Sudoku read()
{
    Sudoku s(9, vector<set<int>>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char c;
            cin >> c;
            if (c == '.') {
                s[i][j] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            } else {
                s[i][j] = { c - '0' };
            }
        }
    }
    return s;
}

void write(const Sudoku& s)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << "[";
            for (int k = 1; k <= 9; ++k) {
                if (s[i][j].count(k)) {
                    cout << k;
                } else {
                    cout << ' ';
                }
            }
            cout << "]";
        }
        cout << endl;
    }
    cout << endl;
}

void propogate(Sudoku& s, int i, int j)
{
    if (s[i][j].size() == 1) {
        int e = *s[i][j].begin();

        // remove e from the cells in the same row
        for (int k = 0; k < 9; ++k) {
            if (k != j) {
                s[i][k].erase(e);
            }
        }

        // remove e from the cells in the same column
        for (int k = 0; k < 9; ++k) {
            if (k != i) {
                s[k][j].erase(e);
            }
        }

        // remove e from the cells in the same box
        int ib = (i / 3) * 3;
        int jb = (j / 3) * 3;
        for (int ii = ib; ii < ib + 3; ++ii) {
            for (int jj = jb; jj < jb + 3; ++jj) {
                if (ii != i or jj != j) {
                    s[ii][jj].erase(e);
                }
            }
        }
    }
}

void propogate_all(Sudoku& s)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            propogate(s, i, j);
        }
    }
}

void simplify(Sudoku& s)
{
    Sudoku s2 = s;
    propogate_all(s);
    if (s != s2) {
        write(s);
        simplify(s);
    }
}

int main()
{
    Sudoku s = read();
    write(s);
    simplify(s);
    write(s);
}
