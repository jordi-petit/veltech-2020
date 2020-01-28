#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    int x;
    while (cin >> x) {
        q.push(x);
    }

    while (not s.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
}
