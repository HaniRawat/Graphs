//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int mod = (1e9+7);
        
        vector<pair<int,int>>adj[n];
        
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        
        pq.push({0,0});
        
        vector<long> dist(n, 1e18);
        vector<int> ways(n, 0);
        
        dist[0] = 0;
        ways[0] = 1;
        
        while(!pq.empty()){
            
            long distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto i : adj[node]){
                int adjNode = i.first;
                int weight = i.second;
                
                if(distance + weight < dist[adjNode]){
                    
                    dist[adjNode] = distance + weight;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node]%mod;
                    
                }
                else if(distance + weight == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        return (ways[n-1])%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends