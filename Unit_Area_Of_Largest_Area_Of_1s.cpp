//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void bfs(int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &vis, int &area){
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            area++;
            
            for(int delrow = -1; delrow<=1; delrow++){
                for(int delcol = -1; delcol<=1; delcol++){
                    int nrow = row+delrow;
                    int ncol = col+delcol;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
    }
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int ans = INT_MIN;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int area = 0;
                if(!vis[i][j] && grid[i][j] == 1){
                    bfs(i, j, grid, vis, area);
                }
                ans = max(ans, area);
            }
        }return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends