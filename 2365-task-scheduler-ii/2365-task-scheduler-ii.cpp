class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long, long long> m;
        long long curr = 0;
        
        for(int i=0; i<tasks.size(); i++)
        {
            if(!m.count(tasks[i]))
            {
                m[tasks[i]] = 1 + space + curr;
                curr++;
            }
            else
            {
                if(m[tasks[i]] > curr)
                {
                    curr = m[tasks[i]];
                }
                
                m[tasks[i]] = 1 + space + curr;
                curr++;
            }
        }
        
        return curr;
    }
};