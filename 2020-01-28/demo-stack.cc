#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    int x;
    while (cin >> x) {
        s.push(x);
    }

    while (not s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}
