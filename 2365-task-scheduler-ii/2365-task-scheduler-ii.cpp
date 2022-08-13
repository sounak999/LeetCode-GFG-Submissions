class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long, long long> mp;
        long long day = 0;
        
        for(int i=0; i<tasks.size(); i++)
        {
            // day++;
            if(mp.count(tasks[i]) == 0)
            {
                mp[tasks[i]] = day;
                
            }
            else
            {
                // task has been encountered
                int diff = day - mp[tasks[i]];
                if(diff > space)
                {
                    mp[tasks[i]] = day;
                }
                else
                {
                    day += mp[tasks[i]] + space + 1 - day;
                    mp[tasks[i]] = day;
                }
            }
            
            day++;
        }
        
        return day;
    }
};