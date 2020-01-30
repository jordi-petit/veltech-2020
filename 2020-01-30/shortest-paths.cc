#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

using WArc = pair<int, int>; // cost, dest
using WGraph = vector<vector<WArc>>;

const int infinity = 10000000;

vector<int> dijkstra(const WGraph& G, int s)
{
    int n = G.size();
    vector<int> d(n, infinity);
    d[s] = 0;
    vector<bool> opt(n, false);
    priority_queue<WArc, vector<WArc>, greater<WArc>> Q;
    Q.push(WArc(0, s));

    while (not Q.empty()) {
        WArc a = Q.top();
        Q.pop();
        int u = a.second;
        if (not opt[u]) {
            opt[u] = true;
            for (WArc uv : G[u]) {
                int w = uv.first;
                int v = uv.second;
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    Q.push({ d[v], v });
                }
            }
        }
    }

    return d;
}

int main()
{
    // read the graphs
    int n, m;
    while (cin >> n >> m) {
        WGraph G(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            G[u].push_back({ w, v });
        }

        // read source and target
        int x, y;
        cin >> x >> y;

        // call dijkstra
        vector<int> d = dijkstra(G, x);
        int r = d[y];
        if (r != infinity) {
            cout << r << endl;
        } else {
            cout << "no path from " << x << " to " << y << endl;
        }
    }
}
