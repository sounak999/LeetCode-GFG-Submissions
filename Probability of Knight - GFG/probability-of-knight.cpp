// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	double findInBoardCount(int N,int x, int y, int K, vector<vector<vector<double>>>& lookup)
{
    double count = 0;
    if (x >= 0 && x < N && y >= 0 && y < N) //Inside board
    {
        if (lookup[x][y][K] != -1)
            return lookup[x][y][K];
            
        if (K == 0)
            return 1;
        //1
        count += findInBoardCount(N, x-2, y-1, K-1, lookup);
        //2
        count += findInBoardCount(N, x-2, y+1, K-1, lookup);
        //3
        count += findInBoardCount(N, x+2, y-1, K-1, lookup);
        //4
        count += findInBoardCount(N, x+2, y+1, K-1, lookup);
        //5
        count += findInBoardCount(N, x-1, y-2, K-1, lookup);
        //6
        count += findInBoardCount(N, x-1, y+2, K-1, lookup);
        //7
        count += findInBoardCount(N, x+1, y-2, K-1, lookup);
        //8
        count += findInBoardCount(N, x+1, y+2, K-1, lookup);
        lookup[x][y][K] = count;
    }
    return count;
}
	double findProb(int N,int start_x, int start_y, int steps)
	{
	     vector<vector<vector<double>>> lookup(N, vector<vector<double>> (N, vector<double>(steps+1, -1)));
	     double total = pow(8, steps);
	     double count = findInBoardCount(N, start_x, start_y, steps, lookup);
	     return count/total;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends