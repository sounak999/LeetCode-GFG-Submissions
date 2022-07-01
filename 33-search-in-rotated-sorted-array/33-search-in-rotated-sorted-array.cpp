class Solution {
    
    int binarySearch(vector<int>& nums, int s, int e, int target)
    {
        int mid = s + (e-s)/2;
        while(s <= e)
        {
            if(nums[mid] == target)
                return mid;
            if(target < nums[mid])
                e = mid - 1;
            else 
                s = mid + 1;
            
            mid = s + (e-s)/2;
        }
        
        return -1;
    }
    
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
        
        // this line will execute whenever the whole array 
        // is sorted with 0 rotations, so return last index
        return nums.size() - 1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivotIdx = getPivot(nums, 0, n-1);
        
        if(target >= nums[0] && target <= nums[pivotIdx])
            return binarySearch(nums, 0, pivotIdx, target);
        
        return binarySearch(nums, pivotIdx + 1, n - 1, target);
    }
};