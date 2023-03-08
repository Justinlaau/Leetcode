const int mod = 1e9 + 7;
int beautifulPartitions(string s, int k, int minL) {
    auto isPrime = [](char x)->bool{
        return (x == '2' || x == '3' || x == '5' || x == '7');
    };
    int dp[1004][1004]{};
    int n = s.size();
    
    dp[0][0] = 1;
    for(int j = 1; j <= k; j++){
        int preSum = 0;
        for(int i = 1; i <= n; i++){
            int lastPartitionBeginIdx = i - minL;
            if(lastPartitionBeginIdx == 0 && isPrime(s[0])){
                (preSum += dp[0][j - 1] %mod)%=mod;
            }else if(lastPartitionBeginIdx > 0 && isPrime(s[lastPartitionBeginIdx]) && !isPrime(s[lastPartitionBeginIdx - 1])){
                (preSum += dp[lastPartitionBeginIdx][j - 1] % mod)%=mod;
            }
            if(!isPrime(s[i - 1])){
                dp[i][j] = preSum;
            }
        }
    }
    return dp[n][k];
}