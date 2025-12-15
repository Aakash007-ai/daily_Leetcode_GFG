#include <bits/stdc++.h>
using namespace std;

const int MAXP = 20; // max port value

int n;
vector<vector<int>> adj;
vector<int> ports;
vector<int> subtreeCount;

// DFS to count number of nodes with current port in each subtree
int dfsCount(int u, int parent, int p) {
    int cnt = (ports[u] == p) ? 1 : 0;
    for (int v : adj[u]) {
        if (v == parent) continue;
        cnt += dfsCount(v, u, p);
    }
    subtreeCount[u] = cnt;
    return cnt;
}

// DFS to calculate bandwidth contribution for edges
void dfsSum(int u, int parent, int totalCount, long long &sum) {
    for (int v : adj[u]) {
        if (v == parent) continue;
        long long sub = subtreeCount[v];
        // each pair between subtree(v) and rest passes through this edge once
        sum += sub * (totalCount - sub);
        dfsSum(v, u, totalCount, sum);
    }
}

long long findTotalBandwidth(
    int network_nodes,
    const vector<int>& network_from,
    const vector<int>& network_to,
    const vector<int>& port
) {
    n = network_nodes;
    ports.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) ports[i] = port[i - 1];

    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        int u = network_from[i], v = network_to[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long total = 0;
    subtreeCount.assign(n + 1, 0);

    // For each possible port value, do a DFS
    for (int p = 1; p <= MAXP; p++) {
        int totalCount = dfsCount(1, -1, p);
        if (totalCount <= 1) continue; // no pairs for this port

        dfsSum(1, -1, totalCount, total);
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> network_from(n - 1), network_to(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> network_from[i] >> network_to[i];
    }

    vector<int> port(n);
    for (int i = 0; i < n; i++) cin >> port[i];

    cout << findTotalBandwidth(n, network_from, network_to, port) << "\n";
    return 0;
}
