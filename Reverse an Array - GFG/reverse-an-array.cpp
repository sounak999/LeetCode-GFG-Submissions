#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}    

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n; //Array size
        cin>>n;
        int arr[n]; //Array
        // For loop to input array
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        reverseArray(arr, 0, n-1);
        
        // For loop to output reversed array
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        
        cout<<endl;
    }

    return 0;
}