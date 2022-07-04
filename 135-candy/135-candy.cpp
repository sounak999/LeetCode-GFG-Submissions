class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> aux(n, 1);
        
        for(int i=1; i<n; i++)
        {
            if(ratings[i-1] < ratings[i])
                aux[i] = aux[i-1] + 1;
        }
        
        int res = 0;
        for(int i=n-2; i>=0; i--)
        {
            if(ratings[i+1] < ratings[i])
                aux[i] = max(aux[i+1] + 1, aux[i]);
        }
        
        for(auto c: aux)
        {
            res += c;
        }
        
        return res;
    }
};