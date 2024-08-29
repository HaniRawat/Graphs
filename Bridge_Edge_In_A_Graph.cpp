//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    void dfs(int node, vector<int> update[], vector<int> &visited)
    {

        // function for dfs 
        visited[node] = 1;
        for(auto nbr:update[node])
        {
            if(!visited[nbr])
            {
                dfs(nbr, update, visited);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> update[V]; // new adjacency list
        for(int i = 0; i < V; i++)
        {
            for(auto j:adj[i])
            {

               // excluding c-d edge in update list
               if((i == c && j == d) || (i == d && j == c))
            {
                continue;
            }
            update[i].push_back(j);
               
            }
        }
        
        vector<int> visited(V, 0); // to store the visited nodes of actual adj list.

        // count1 for components of actual adj list and count2 for components of update list.

        int count1 = 0, count2 = 0;
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                dfs(i, adj, visited);
                count1++; // incrementing the component
            }
        }
        vector<int> vis(V,0);
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                dfs(i, update, vis);
                count2++;
            }
        }

        // if components of update are more than components of  adj then it means that c-d edge was bridge and it divided the graph in two components.
        return (count1 < count2);
        
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
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends