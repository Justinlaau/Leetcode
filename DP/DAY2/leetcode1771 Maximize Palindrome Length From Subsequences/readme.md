```
This is the solution of longest palidromic subsequence.

int longestPalindromeSubseq(string s) {
    int n = s.size();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for(int len = 1; len <= n; len++){
        for(int i = 0; i < n - len + 1; i++){
            int j = i + len- 1;
            if(len == 1){
                dp[i][i] = 1;
                continue;
            }
            if(s[i] == s[j]){
                dp[i][j] = dp[i + 1][j - 1]+ 2;
            }else{
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}


The only difference is that we are now given two string.
We have to pick at least one char from both array to form a palidrom.

So, the idea is to combine two string to be one single string, and use the longest palidromic 
subsequence method to find the maximum palidrome we can construct.

But how to ensure that we have picked at least one char from both string.
Try to think about the dp state, our dp state is in the range of i to j, the longest palidrome we get, 
then if i and j is located in same string, which means this palidrome haven't used another string to 
construct the answer.

By this, we know making few changes in the above code can solve this question easily.

When we need to count the answer, we just check if i and j in different string.
```