class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> res;
        map<int, int> mp;
        
        for(auto v: items1)
            mp[v[0]] += v[1];
        
        for(auto v: items2)
            mp[v[0]] += v[1];
        
        for(auto i: mp)
            res.push_back({i.first, i.second});
        
        return res;
    }
};