class Solution {
public:
    vector<vector<int>> vec;

    void fun(int st,int k,int n,vector<int> v) {
        if(k==0 && n==0)
        {
            vec.push_back(v);
            return;
        }
    
        if(k<=0) return;
    
        for(int i=st;i<=9;i++)
        {
            if(n>=i)
            {
                v.push_back(i);
                fun(i+1, k-1, n-i, v);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        fun(1,k,n,v);
        return vec;
    }
};