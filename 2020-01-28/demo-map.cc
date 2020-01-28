#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> counter;

    string word;
    while (cin >> word) {
        ++counter[word];
    }

    for (auto pair : counter) {
        cout << pair.first << ' ' << pair.second << endl;
    }
}
