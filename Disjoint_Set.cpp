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