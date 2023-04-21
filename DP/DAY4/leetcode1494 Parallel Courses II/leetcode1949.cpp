int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
    /*
    dp[i] = the bitmask i needs how many semster to finish
    cnt[i] = how many 1 in the bitmask
    */
    int graph[20]{};
    for(const auto&p : relations){
        int prereg = p[0] - 1;
        int reg = p[1] - 1;
        graph[reg] |= 1<<prereg;
    }
    int totalState = 1<<n;
    vector<int> dp(totalState, 100);
    dp[0] = 0;
    for(int taken = 0; taken < totalState; taken++){
        if(dp[taken] > n)continue;
        //courses we can reg
        int reg_able = 0;
        for(int i = 0; i < n; i++){
            //we want to reg i, so check all the prereg
            if((((1<<i)&taken) == 0) && ((graph[i] & taken) == graph[i])){
                reg_able |= (1<<i);
            }
        }
        // try to reg, and see the result is better or not
        for(int i = reg_able; i != 0; i = i-1 & reg_able){
            if(__builtin_popcount(i) <= k){
                dp[taken|i] = min(dp[taken|i], dp[taken]+1);
            }
        }
    }
    return dp[totalState- 1];
}