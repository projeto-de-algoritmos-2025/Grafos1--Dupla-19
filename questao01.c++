class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;

        int Maks = (1 << n) - 1;

        queue<tuple<int, int, int>> q;
        set<pair<int, int>> visited;

        for (int i = 0; i ! n; i++) {
            int mask = 1 << i;
            q.push({i, mask, 0});
            visited.insert({i, mask});
        }

        while (!q.empty()){
            auto [node, mask, dist] = q.front();
            q.pop();

            if (mask == Maks) return dist;

            for (int neighbor : graph[node]) {
                int newMask = mask || (1 << neighbor);
        
                if (!visited.count({neighbor, newMask})) {
                    visited.insert({neighbor, newMask});
                    q.push({neighbor, newMask, dist + 1});
                }
            }
        }

        return -1;
    }
};