//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    void dfs(int node, vector<pair<int,int>>adj[], vector<int>& vis, int &endNode, int& minWt){
        vis[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it.first]){
                minWt = min(minWt, it.second);
                endNode = it.first;
                dfs(it.first, adj, vis, endNode, minWt);
            }
        }
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        vector<pair<int,int>>adj[n+1];
        vector<int> indegree(n+1, 0);
        
        for(int i=0; i<p; i++){
            int u = a[i];
            int v = b[i];
            int wt = d[i];
            
            adj[u].push_back({v,wt});
            indegree[v]++;
        }
        
        int tanksAndTaps = 0;
        
        for(int i=1; i<=n; i++){
            if(indegree[i] == 0)
                tanksAndTaps++;
        }
        
        vector<vector<int>>ans;
        vector<int> vis(n+1, 0);
        
        for(int i=1; i<=n; i++){
            int endNode = -1;
            int minWt = INT_MAX;
            
            if(!vis[i] && indegree[i] == 0 && adj[i].size() > 0){
                dfs(i, adj, vis, endNode, minWt);
                ans.push_back({i, endNode, minWt});
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends