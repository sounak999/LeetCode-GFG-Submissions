class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int m = horizontalCuts.size(), n = verticalCuts.size();
        int maxH = INT_MIN;
        for(int i=0; i<m; i++)
        {
            int height = (i == 0)? horizontalCuts[0]: horizontalCuts[i]-horizontalCuts[i-1];
            maxH = max(maxH, height);         
        }
        
        maxH = max(h-horizontalCuts.back(), maxH);
        
        int maxW = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int width = (i == 0)? verticalCuts[0]: verticalCuts[i]-verticalCuts[i-1];
            maxW = max(maxW, width);         
        }
        
        maxW = max(w-verticalCuts.back(), maxW);
        
        return (1LL*maxH*maxW)%1000000007;
    }
};