class Solution {
public:
    int mySqrt(int x) {
        int s = 0, e = x;
        int mid = s + (e - s)/2;
        
        int ans = 0;
        while(s <= e)
        {
            if(x == 1LL*mid*mid)
                return mid;
            
            if(x < 1LL*mid*mid)
                e = mid - 1;
            else
            {
                ans = mid;
                s = mid + 1;
            }
            
            mid = s + (e - s)/2;
        }
        
        return ans;
    }
};