//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    
    void dfs(int r, int c, vector<vector<int>>&visited,vector<vector<int>>&mat,int dr[], int dc[]) {
        visited[r][c] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<4;i++) {
            int nrow = r + dr[i];
            int ncol = c + dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && mat[nrow][ncol]==1) {
                dfs(nrow,ncol,visited,mat,dr,dc);
            }
            
        }
    }
    
    int closedIslands(vector<vector<int>>& mat, int n, int m) {
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        for(int i=0; i<m; i++){
            if(!vis[0][i] && mat[0][i] == 1){
                dfs(0,i,vis,mat,drow,dcol);
            }
            
            if(!vis[n-1][i] && mat[n-1][i] == 1){
                dfs(n-1, i, vis, mat, drow, dcol);
            }
        }
        
        for(int i=0; i<n; i++){
            if(!vis[i][0] && mat[i][0] == 1){
                dfs(i,0,vis,mat,drow,dcol);
            }
            if(!vis[i][m-1] && mat[i][m-1] == 1){
                dfs(i,m-1,vis,mat,drow,dcol);
            }
        }
        
        int count = 0;
        
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++) {
               if(!vis[i][j] && mat[i][j]==1) {
                  dfs(i,j,vis,mat,drow,dcol);
                  count++;
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends