//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   
	public:
	
	class DisjointSet{
	    
	    private:
	    vector<int>parent, size;
	    
	    public:
	    
	    DisjointSet(int n){
	        parent.resize(n+1);
	        for(int i=0; i<n+1; i++){
	            parent[i] = i;
	        }
	        size.resize(n+1,1);
	    }
	    
	    int findParent(int node){
	        if(node == parent[node])
	            return node;
	            
	       //path compression
	       return parent[node] = findParent(parent[node]);
	    }
	    
	    void Union(int u, int v){
	        int ulp_u = findParent(u);
	        int ulp_v = findParent(v);
	        
	        if(ulp_u == ulp_v)
	            return;
	        else if(size[ulp_u] > size[ulp_v]){
	            parent[ulp_v] = ulp_u;
	            size[ulp_v] += size[ulp_u];
	        }
	        else{
	            parent[ulp_u] = ulp_v;
	            size[ulp_u] += size[ulp_v];
	        }
	    }
	    
	    
	};
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       int cost = 0;
       
       vector<pair<int,pair<int,int>>>edges;
       
       for(int i=0; i<V; i++){
           
           for(auto it : adj[i]){
               int adjNode = it[0];
               int wt = it[1];
               int node = i;
               
               edges.push_back({wt,{node,adjNode}});
           }
       }
       
       //sort the edges acc to weight
       sort(edges.begin(), edges.end());
       //take one edge and form a mst
       DisjointSet ds(V);
       for(int i=0; i<edges.size(); i++){
           int u = edges[i].second.first;
           int v = edges[i].second.second;
           int w = edges[i].first;
           
           if(ds.findParent(u) != ds.findParent(v)){
               cost += w;
               ds.Union(u,v);
           }
       }
       
       return cost;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends