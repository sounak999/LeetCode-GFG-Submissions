class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int largest = -1;
        
        for(int i = n-2; i >= 0; i--)
        {
            if(arr[i] > arr[i+1]) 
            {
                largest = i; 
                break;
            }
        }
        
        if(largest==-1) 
            return arr;
        
        int smallest = largest+1;
        
        for(int i=n-1; i>=0; i--)
        {
            if(arr[i]<arr[largest])
            {
                smallest = i; 
                break;
            }
        }
        
        for(int i=smallest-1; i>=0; i--)
        {
            if(arr[smallest] != arr[i]) 
            {
                smallest = i+1; 
                break;
            }
        }
        
        swap(arr[smallest], arr[largest]);
        return arr;
    }
};