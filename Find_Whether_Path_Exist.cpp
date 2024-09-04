//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1){
                    
                    q.push({i,j});
                    vis[i][j]=1;
                    
                }
            }
        }
        
        int delrow[]={1,0,-1,0};
        int delcol[]={0,1,0,-1};
        
        while(!q.empty()){
            
            int row=q.front().first;
            int col=q.front().second;
            
            q.pop();
            
            if(grid[row][col]==2){
                return true;
            }
            
            for(int i=0;i<4;i++){
                
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]!=0
                and !vis[nrow][ncol]){
                    
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                    
                }
            }
            
        }
        return false;
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
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends