#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;

    int x;
    while (cin >> x) {
        pq.push(x);
    }

    while (not pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
}
