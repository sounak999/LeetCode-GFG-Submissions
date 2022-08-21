class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        //Go in reverse direction from target  to seq
        string seq(target.length(),'?');
        vector<int>res;
        while(target != seq)
        {
            int matching_id = isMatching(target,stamp);
            if(matching_id == -1){return {};}//return an empty array
            res.push_back(matching_id);
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    int isMatching(string &target,string stamp){
        //naive pattern matching algorithm
        for(int i=0;i<target.length();i++)
        {
            int j = 0;
            int matches = 0;//atleast 1 char should match along with '?'
            for(j = 0;j<stamp.length();j++)
            {
                if(target[i+j] == stamp[j]){matches++;}
               else if(target[i+j] == '?'){continue;}
                else break;//mismatch
            }
            
            if(j == stamp.length() && matches != 0)
            {
                for(j = 0;j<stamp.length();j++){
                    target[i + j] = '?';
                }
                 return i;
            }
        }
        //no matches at all 
        return -1;
    }
};