class Solution {
public:
    bool step(string a, string b) {
        bool flag = false;
        
        for (int k=0; k<a.size(); k++) {
            if (a[k] != b[k]) {
                if (flag) return false;
                else flag = true;
            }
        }

        return true;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size()-1, target = -1, cur;
        vector<vector<bool>> dict(n+1, vector<bool>(n+1, false));
        vector<bool> used(n+1, false);
        queue<int> q;
        
        for (int i=0; i<=n; i++) {

            if (wordList[i] == endWord) target = i;
            for (int j=i+1; j<=n; j++) {

                if (step(wordList[i], wordList[j])) {
                    dict[i][j] = true;
                    dict[j][i] = true;
                }
            }
        }
        
        if (target<0) return false;
        
        q.push(n);
        used[n] = true;
        int count = 0, qsize;
        
        
        while (!q.empty()) {
            qsize = q.size();
            count++;
            for (int i=0; i<qsize; i++) {
                cur = q.front();
                q.pop();
                for (int j=0; j<=n; j++) {
                    if (dict[cur][j] && !used[j]) {
                        if (j == target) return count+1;
                        q.push(j);
                        used[j] = true;
                    }
                }
            }
        }
        
        return 0;
    }
};