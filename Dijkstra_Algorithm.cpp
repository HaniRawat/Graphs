//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V, 1e9);
        set<pair<int,int>>st; //stores in ascending order and does not allow duplicates
        
        dist[S] = 0;
        st.insert({0,S});
        
        while(!st.empty()){
            auto it = *(st.begin()); //"it" is an iterator and "*" gives the value at "it"
            int d = it.first;
            int node = it.second;
            
            st.erase(it);
            
            for(auto i : adj[node]){
                int edgewt = i[1];
                int adjNode = i[0];
                
                if(d + edgewt < dist[adjNode]){
                    if(dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});
                        
                    dist[adjNode] = d + edgewt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends