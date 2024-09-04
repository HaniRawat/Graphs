//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	//Using BFS and cycle detection method
bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[V];
	    for(auto it : prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    
	    int indegree[V] = {0};
	    for(int i = 0; i<V; i++){
	        for(auto it: adj[i])
	        indegree[it]++;
	    }
	    
	    queue<int> q;
	    for(int i = 0; i<V; i++){
	        if(indegree[i] == 0)
	        q.push(i);
	    }
	    
	    int count = 0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        count++;
	        
	        for(auto it: adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    
	    if(count == V)
	    return 1;
	    
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends