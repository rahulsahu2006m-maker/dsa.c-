class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            indegree[e[1]]++;
        }

        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &p : adj[u]) {
                if (--indegree[p.first] == 0)
                    q.push(p.first);
            }
        }

        auto check = [&](int x) {
            const long long INF = 4e18;
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF) continue;
                if (u != 0 && u != n - 1 && !online[u]) continue;

                for (auto &p : adj[u]) {
                    int v = p.first;
                    int w = p.second;

                    if (w < x) continue;
                    if (v != n - 1 && !online[v]) continue;

                    dist[v] = min(dist[v], dist[u] + (long long)w);
                }
            }

            return dist[n - 1] <= k;
        };

        int mx = 0;
        for (auto &e : edges)
            mx = max(mx, e[2]);

        int ans = -1;
        int lo = 0, hi = mx;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
