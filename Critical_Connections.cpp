//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    void dfs(int node, vector<int>adj[], vector<vector<int>>&ans,
    vector<int>&lowTime, int& timer, int parent){
        
        lowTime[node] = timer;
        int parentTime = timer;
        
        timer++;
        
        for(auto it : adj[node]){
            if(it == parent)
                continue;
            else if(!lowTime[it]){
                dfs(it, adj, ans, lowTime, timer, node);
            }
            
            lowTime[node] = min(lowTime[node], lowTime[it]);
            if(parentTime < lowTime[it]){
                if(node < it){
                    ans.push_back({node, it});
                }
                else{
                    ans.push_back({it, node});
                }
            }
        }
    }
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    vector<vector<int>>ans;
	    int timer = 1;
	    
	    vector<int>lowTime(v, 0);
	    dfs(0, adj, ans, lowTime, timer, -1);
	    sort(ans.begin(), ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends