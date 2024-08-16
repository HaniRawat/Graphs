//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      unordered_map<int,int>mp;
      
      for(int i=0; i<Edge.size(); i++){
          mp[Edge[i]] += i;
      }
      
      int mx = INT_MIN;
      int ans = 0;
      
      for(auto &i : mp){
          if(i.second > mx){
            mx = i.second;
            ans = i.first;
          }
      }
      
      return ans == -1? 0:ans;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends