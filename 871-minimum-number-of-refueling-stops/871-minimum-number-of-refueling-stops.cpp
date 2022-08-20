class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int maxReach = startFuel, idx = 0, count = 0;
        priority_queue<int> pq;
        sort(stations.begin(), stations.end());
        
        while(maxReach < target)
        {
            while(idx < stations.size() && stations[idx][0] <= maxReach)
            {
                pq.push(stations[idx][1]);
                idx++;
            }
            
            if(pq.empty())
                return -1;
            
            maxReach += pq.top();
            pq.pop();
            count++;
        }
        
        return count;
    }
};