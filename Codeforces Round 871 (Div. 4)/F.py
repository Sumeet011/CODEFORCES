#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <bitset>
#include <cmath>
#include <limits>
#include <list>


using namespace std;



void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    int x = -1, y = -1;
    for (int i = 1; i <= n; i++)
    {
        queue<int> bfs;
        vector<int> visited(n + 1);

        visited[i] = 1;
        for (int u : graph[i])
        {
            bfs.push(u);
            visited[u] = 1;
        }
        x = bfs.size();
        int p = bfs.size();
        while (p--)
        {
            int u = bfs.front(); bfs.pop();
            for (int v : graph[u])
            {
                if (!visited[v])
                {
                    bfs.push(v);
                }
            }
        }
        y = bfs.size();
        if (x > 0 && y > 0 && x + y + 1 == n)
        {
            // cout << "yes" << endl;
            break;
        }
    }

    cout << x << " " << (y / x) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--)
    {
        solve();
    }
}
