//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> A, int X, int Y) {
        if(A[0][0] != 1)
            return -1;
        if(A[X][Y] != 1)
            return -1;
            
        if(X == 0 && Y == 0)
            return 0;
            
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        
        queue<pair<int,int>>q;
        q.push({0,0});
        int count = 0;
        
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        
        while(!q.empty()){
            int size = q.size();
            count++;
            
            while(size--){
                pair<int,int>p = q.front();
                q.pop();
                
                int x = p.first;
                int y = p.second;
                
                for(int i=0; i<4; i++){
                    int newX = x+dx[i];
                    int newY = y+dy[i];
                    
                    if(newX == X && newY == Y)
                        return count;
                    if(newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && A[newX][newY] == 1){
                        q.push({newX, newY});
                        visited[newX][newY] = 1;
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends