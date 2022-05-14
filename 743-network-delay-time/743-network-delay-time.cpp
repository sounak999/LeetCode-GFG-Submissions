class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {

        // assume the distance to from origin node to ith node is infinite
        vector<int> dist(N + 1, INT_MAX);
        dist[0] = 0;
        dist[K] = 0;

        // traverse all destinations, N is the worest case
        for (int i = 0; i < N; i++) {
            vector<int> old_dist = dist;
            for (vector<int> edge : times) {
                int u = edge[0], v = edge[1], w = edge[2];
                // if the source node u is visited, then update the distance to target node v
                if (dist[u] != INT_MAX){
                    dist[v] = min(dist[v], dist[u] + w);
                }
            }
            // status can not be changed in the future loop
            if (old_dist == dist){
                break;
            }
        }

        int longest_dist = 0;
        for (int i = 1; i <= N; i++) {
            longest_dist = max(longest_dist, dist[i]);
        }

        if (longest_dist == INT_MAX) {
            return -1;
        }

        return longest_dist;
    }
};