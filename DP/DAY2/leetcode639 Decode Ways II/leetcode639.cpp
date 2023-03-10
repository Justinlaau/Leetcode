const int maxN = 1e6;
const int mod = 1e9 + 7;
int numDecodings(string s) {
    int n = s.size();
    long long dp[100009]{1};
    set<string> st;
    for(int i = 1; i <= 26; ++i)st.insert(to_string(i));
    for(int i = 1; i <= n; i++){
        if(s[i - 1] == '*'){
            dp[i] += dp[i - 1]*9;
            if(i >= 2 && s[i - 2] == '1')dp[i] += 9*dp[i - 2];
            else if(i >= 2 && s[i - 2] == '2')dp[i] += 6*dp[i - 2];
            else if(i >= 2 && s[i - 2] == '*')dp[i] += 15*dp[i - 2];
        }else{
            if(st.find(string(1, s[i - 1])) != st.end()) dp[i] += dp[i - 1];
            if(i >= 2 && st.find(string(1,s[i - 2]) + string(1,s[i - 1]))!=st.end())dp[i] += dp[i - 2];
            else if(i >= 2 && s[i - 2] == '*'){
                if(s[i - 1] < '7'){
                    dp[i] += dp[i - 2] *2;
                }else{
                    dp[i] += dp[i - 2];
                }
            }
        }
        dp[i]%=mod;
    }
    return dp[n];
}