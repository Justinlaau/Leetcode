# Idea
easy version of 1977
suffix array 
dp[i] the maximum steps needed to delete strings.
if(j - i + 1 > suffix Sum[i][j])
dp[i] = max(dp[i], dp[j] + 1) 
