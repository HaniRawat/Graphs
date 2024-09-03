//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    
    void dfs(int i, int j, vector<vector<char>>&grid, vector<vector<int>>&visited, int n, int m){
        
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j] != 0 || grid[i][j] == 'O')
            return;;
            
        visited[i][j] = 1;
            
        dfs(i+1, j, grid, visited, n, m);
        dfs(i-1, j, grid, visited, n, m);
        dfs(i, j+1, grid, visited, n, m);
        dfs(i, j-1, grid, visited, n, m);
    }
    int xShape(vector<vector<char>>& grid) 
    {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>visited(n, vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'X' && !visited[i][j]){
                    cnt++;
                    dfs(i,j,grid,visited,n,m);
                }
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends