class Solution {
public:
    int findJudge(int n, vector<vector<int>>& vec) {
        // Initialize a count array to track trust relationships.
        vector<int> cnt(n+1, 0);

        // Edge case: If there's only one person, they are the judge by definition.
        if(n == 1) return 1;

        // Iterate over each trust pair.
        for (int i = 0; i < vec.size(); i++) {
            int u = vec[i][0]; // Person u trusts...
            int v = vec[i][1]; // Person v.

            // u trusts someone, so decrement their count.
            cnt[u]--;
            // v is trusted by someone, so increment their count.
            cnt[v]++;
        }

        // Find the person who is trusted by n-1 people and trusts no one.
        for (int i = 1; i <= n; i++) {
            if(cnt[i] == n-1) return i;
        }

        // If no such person is found, return -1 (no judge exists).
        return -1;

    }
};