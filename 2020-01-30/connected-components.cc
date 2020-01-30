#include <iostream>
#include <string>
#include <vector>
using namespace std;

using Graph = vector<vector<int>>;

void explore(const Graph& G, int v, vector<bool>& visited)
{
    visited[v] = true;
    for (int u : G[v]) {
        if (not visited[u]) {
            explore(G, u, visited);
        }
    }
}

int main()
{
    // read the graph
    int n, m;
    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // count the number of connected components
    int ncc = 0;
    vector<bool> visited(n, false);
    for (int v = 0; v < n; ++v) {
        if (not visited[v]) {
            ++ncc;
            explore(G, v, visited);
        }
    }
    cout << ncc << endl;
}
