//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int color = image[sr][sc];
        if(color == newColor)
            return image;
            
        int row = image.size();
        int col = image[0].size();
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc] = newColor;
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            int x = front.first;
            int y = front.second;
            
            int dx[4] = {0,-1,0,1};
            int dy[4] = {-1,0,1,0};
            
            for(int i=0; i<4; i++){
                int r = x+dx[i];
                int c = y+dy[i];
                
                if(r >= 0 && r < row && c >= 0 && c < col
                && image[r][c] == color){
                    image[r][c] = newColor;
                    q.push({r,c});
                }
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends