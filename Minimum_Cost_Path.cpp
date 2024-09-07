//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        
        vector<vector<int>> dist(n, vector<int>(n,1e9));
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>>pq;
        
        pq.push({grid[0][0], {0,0}});
        
        vector<int> d = {0,1,0,-1,0};
        
        while(!pq.empty()){
            auto it = pq.top();
            
            pq.pop();
            
            for(int i=0; i<4; i++){
                int x = it.second.first + d[i];
                int y = it.second.second + d[i+1];
                
                if(x < 0 || y < 0 || x == n || y == n)
                    continue;
                    
                int dis = it.first + grid[x][y];
                
                if(dis < dist[x][y]){
                    pq.push({dis, {x,y}});
                    dist[x][y] = dis;
                }
            }
        }
        
        return dist[n-1][n-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends