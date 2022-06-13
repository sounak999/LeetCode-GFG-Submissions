class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> ans;
        for(int i=0; i<exp.length(); i++)
        {
            if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*')
            {
                vector<int> leftAns = diffWaysToCompute(exp.substr(0, i));
                vector<int> rightAns = diffWaysToCompute(exp.substr(i+1));
                
                for(auto j: leftAns)
                {
                    for(auto k: rightAns)
                    {
                        if(exp[i] == '+')
                            ans.push_back(j+k);
                        else if(exp[i] == '-')
                            ans.push_back(j-k);
                        else
                            ans.push_back(j*k);
                    }
                }
            }
        }
        
        if(ans.size() == 0)
            ans.push_back(stoi(exp));
            
        return ans;    
    }
};