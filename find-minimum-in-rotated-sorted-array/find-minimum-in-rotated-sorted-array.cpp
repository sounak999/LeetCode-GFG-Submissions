class Solution {
    int getPivot(vector<int>& nums, int s, int e) 
    {
        int mid = s + (e-s)/2;
        while(s <= e)
        {
            if(mid < e && nums[mid] > nums[mid+1])
                return mid;
            
            if(mid > s && nums[mid-1] > nums[mid])
                return mid-1;
            
            if(nums[s] < nums[mid])
                s = mid + 1;
            else
                e = mid - 1;
                
            mid = s + (e-s)/2;
        }
        
        return nums.size()-1;
    }
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int pvtIdx = getPivot(nums, 0, n-1);
        
        if(pvtIdx == n-1)
            return nums[0];
        
        return min(nums[0], nums[pvtIdx+1]);
    }
};