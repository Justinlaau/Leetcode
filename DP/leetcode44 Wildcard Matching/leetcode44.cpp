bool isMatch(string s, string p) {
    int dp[2100][2100]{};
    //s前i 個字符能否匹配 p前j個字符
    dp[0][0] = 1;
    for(int i = 0; i < p.length() && p[i] == '*'; ++i){
        dp[0][i + 1] = 1;
    }
    for(int i = 1; i <= s.length(); i++){
        for(int j = 1; j <= p.length(); j++){
            if(p[j - 1] == '*'){
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1] ;
            }else if((p[j - 1] == s[i - 1])|| p[j - 1] == '?'){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return dp[s.length()][p.length()];
}

