int Solution::solve(string A, string B, vector<string> &C) {
    
    unordered_set<string> s(C.begin(),C.end());
    queue<pair<int,string>> q;
    q.push({0,A});
    
    while(!q.empty()){
        int steps = q.front().first;
        string word = q.front().second;
        
        s.erase(word);
        
        if(word == B) return steps+1;
        
        q.pop();
        
        for(int i = 0 ; i < word.size() ; i++){
            char temp = word[i];
            for(int j = 'a' ; j <= 'z' ; j++){
                word[i] = j;
                if(s.find(word) != s.end()){
                    q.push({steps+1,word});
                    s.erase(word);
                }
            }
            word[i] = temp;
        }
    }
    return -1;
}