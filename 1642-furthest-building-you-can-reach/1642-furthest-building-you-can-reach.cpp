class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int totalBr = 0;
        priority_queue<int> brUsed;
        
        int i = 0;
        for(; i<n-1; i++)
        {
            if(heights[i] >= heights[i+1])
                continue;
            
            int diff = heights[i+1] - heights[i];
            
            if(totalBr + diff <= bricks)
            {
                totalBr += diff;
                brUsed.push(diff);
            }
            else if(ladders > 0)
            {
                if(!brUsed.empty() && brUsed.top() > diff)
                {
                    totalBr = totalBr - brUsed.top() + diff;
                    brUsed.pop();
                    brUsed.push(diff);
                }
                
                ladders--;
            }
            else
                break;
        }
        
        return i;
    }
};