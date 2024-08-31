//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool solve(int per, vector<vector<int>>&G, vector<int>&vis, vector<int>&match){
        for(int job=0; job<G[0].size(); job++){
            if(G[per][job] && !vis[job]){
                vis[job] = 1;
                if(match[job] == -1 || solve(match[job], G, vis, match)){
                    match[job] = per;
                    return true;
                }
            }
        }
    }
	int maximumMatch(vector<vector<int>>&G){
	    int p = G.size();
	    int j = G[0].size();
	    
	    vector<int>match(j,-1);
	    int count = 0;
	    
	    for(int i=0; i<p; i++){
	        vector<int>vis(j,0);
	        if(solve(i, G, vis, match))
	            count++;
	    }
	    return count;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends