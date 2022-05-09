class Solution {
    void solve(string input, int idx, string output, vector<string> &ans, string mapping[]) {
        if(idx == input.length())
        {
            if(output.length() > 0)
                ans.push_back(output);
            
            return ;
        }
        
        int digit = input[idx] - '0';
        string word = mapping[digit];
        
        for(int i=0; i<word.length(); i++) {
            output += word[i];
            solve(input, idx+1, output, ans, mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string output;
        vector<string> ans;
        
        solve(digits, 0, output, ans, mapping);
        
        return ans;
    }
};