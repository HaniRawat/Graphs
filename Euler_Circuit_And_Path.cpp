//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isEulerCircuit(int V, vector<int>adj[]){
	    
	    int cnt = 0;
	    int node = -1;
	    
	    for(int i=0; i<V; i++){
	        if(adj[i].size() & 1)
	            cnt++;
	        if(adj[i].size() > 0)
	            node = i;
	    }
	    
	    vector<int> vis(V,0);
	    vis[node]=1;
	    
	    queue<int>q;
	    q.push(node);
	    
	    while(!q.empty()){
	        int root = q.front();
	        q.pop();
	        
	        for(auto it : adj[root]){
	            if(!vis[it]){
	                vis[it]=1;
	                q.push(it);
	            }
	        }
	    }
	    
	    for(int i=0; i<V; i++){
	        if(vis[i] == 0 && adj[i].size() > 0)
	            return 0;
	    }
	    
	    if(cnt > 2)
	        return 0;
	    else if(cnt == 0)
	        return 2;
	    else
	        return 1;
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
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends