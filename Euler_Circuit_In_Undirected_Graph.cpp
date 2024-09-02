//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    for(int i =0; i<v; i++){
	        if(adj[i].size() & 1)
	            return 0;
	    }
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
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void dfs(int node, vector<int>adj[], vector<int>&vis){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(vis[it] == 0)
                dfs(it, adj, vis);
        }
    }
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    
	    vector<int>vis(v+1,0);
	    dfs(0, adj, vis);
	    
	    int count = 0;
	    
	    for(int i=0; i<v; i++){
	        if(vis[i] == 0 && adj[i].size() > 0)
	            return false;
	        if(adj[i].size() &1)
	            count++;
	    }
	    
	    if(count > 0)
	        return false;
	    else
	        return true;
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
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends