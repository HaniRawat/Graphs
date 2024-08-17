class Solution {
public:
//Intuition1
//Only the center node appears more than once in the edges array.

//Approach
//1.Check if edges[0][0] appears twice, if it does return it else return edges[0][1].
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        return edges[0][1];
    }
};

// Intuition2
// In a star graph, the center node is the only node that connects directly to all other nodes.
// This means that if there are n nodes, the center node will have exactly n-1 edges.

// Approach:
// We use a map mpp to count the occurrences of each node in the edges.
// Iterate through each edge and update the counts for both nodes in the edge.
// After processing all edges, we count the number of unique nodes.
// We then iterate through the map to find the node that has exactly nodes-1 edges. This node is the center of the star graph.

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>mpp;
        for(int i =0 ;i<edges.size();i++){
            mpp[edges[i][0]]++;
            mpp[edges[i][1]]++;

        }
        int nodes = 0 ;
        for(auto it:mpp){
            nodes++;
        }
        for(auto it:mpp){
          if(it.second==nodes-1)return it.first;
        }
        return 1;
    }
};