#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

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
        
        // For loop to reverse the array
        for(int i=0;i<n/2;i++)
        {
            int temp = arr[i];
            arr[i] = arr[n-1-i];
            arr[n-1-i] = temp;
        }
        
        // For loop to output reversed array
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        
        cout<<endl;
    }

    return 0;
}