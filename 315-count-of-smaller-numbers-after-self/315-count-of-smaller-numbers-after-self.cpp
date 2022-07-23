class Solution {
    
    void merge(vector<int> &ans, vector<pair<int, int>>& v, int left, int right)
    {
        vector<pair<int,int>> temp(right-left+1);
        int mid = left + (right-left)/2;
        int i=left;
        int j=mid+1;
        int k=0;
        
        while(i<=mid && j<=right) {
            // descending order
            if(v[i].first <= v[j].first)
            {
                temp[k++] = v[j++];
            } else {
                int index = v[i].second;
                ans[index] += (right - j + 1);
                temp[k++] = v[i++];
            }
        }
        
        while(i <= mid) {
            temp[k++] = v[i++];
        }
        
        while(j <= right) {
            temp[k++] = v[j++];
        }
        
        for(int i=left; i<=right; i++) {
            v[i] = temp[i-left];
        }
    }
    
    void mergeSort(vector<int>& ans, vector<pair<int, int>>& v, int s, int e)
    {
        if(s >= e)
            return ;
        
        int mid = s + (e-s)/2;
        mergeSort(ans, v, s, mid);
        mergeSort(ans, v, mid+1, e);
        merge(ans, v, s, e);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> idx(n, {0, 0});
        for(int i=0; i<n; i++) {
            idx[i] = {nums[i], i};
        }
        
        vector<int> ans(n, 0);
        mergeSort(ans, idx, 0, n-1);
        return ans;
    }
};