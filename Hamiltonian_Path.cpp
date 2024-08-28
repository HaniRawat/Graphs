//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool dfs(int node, int count, unordered_map<int,list<int>>&adj, vector<int>vis){
        
        if(count == (vis.size()-1))
            return true;
            
        vis[node] = 1;
        count++;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, count, adj, vis))
                    return true;
            }
        }
        return false;
    }
    bool check(int N,int M,vector<vector<int>> edges)
    {
        unordered_map<int,list<int>>adj;
        
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int count = 1;
        vector<int>vis(N+1, 0);
        
        for(int i=1; i<=N; i++){
            if(dfs(i, count, adj, vis))
                return true;
        }
        
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends