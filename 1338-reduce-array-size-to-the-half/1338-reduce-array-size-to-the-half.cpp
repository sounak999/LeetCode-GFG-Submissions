class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++)
            mp[arr[i]]++;
        
        priority_queue<int> pq;
        for(auto i: mp)
            pq.push(i.second);
        
        int cnt = 0, size = 0;
        while(!pq.empty())
        {
            cnt++;
            size += pq.top();
            if(size >= n/2)
                return cnt;
            
            pq.pop();
        }
        
        return 0;
    }
};