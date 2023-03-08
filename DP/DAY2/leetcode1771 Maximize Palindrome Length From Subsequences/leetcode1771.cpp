int longestPalindrome(string word1, string word2) {
    string s = word1 + word2;
    int n = s.size();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    int res = 0;
    for(int len = 1; len <= n; len++){
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            if(len == 1){
                dp[i][i] = 1;
                continue;
            }
            if(s[i] == s[j]){
                dp[i][j] += dp[i + 1][j - 1] + 2;
                if(i < word1.size() && j >= word1.size())res = max(res, dp[i][j]);
            }else{
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return res;
}