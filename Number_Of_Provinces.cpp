//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node ,vector<bool>&visited,vector<int> ad[])
  {
      visited[node]=1;
      for(int j=0;j<ad[node].size();j++)
      {
          if(!visited[ad[node][j]])
          dfs(ad[node][j],visited,ad);
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> ad[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                ad[i].push_back(j);
                ad[j].push_back(i);
                }
            }
        }
        vector<bool> visited(V,0);
        int provinces=0;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                
                dfs(i,visited,ad);
                provinces++;
            }
            
        }
        return provinces;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends