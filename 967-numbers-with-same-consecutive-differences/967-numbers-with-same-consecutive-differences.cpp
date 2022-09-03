class Solution {
    void solve(string str, int idx, int n, int k, vector<int> &res)
    {
        if(idx == n-1)
        {
            if(str.length() > 1)
                res.push_back(stoi(str));
            
            return ;
        }
        
        for(int i=0; i<=9; i++)
        {
            int num = str[idx] - '0';
            int diff = abs(num - i);
            if(diff == k)
            {
                str += to_string(i);
                solve(str, idx+1, n, k, res);
                str.pop_back();
            }
        }
    
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        string str = "";
        vector<int> res;
        for(int i=1; i<=9; i++)
        {
            str = to_string(i);
            solve(str, 0, n, k, res);
        }
        
        return res;
    }
};