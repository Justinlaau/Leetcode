int maxCoins(vector<int>& tnums) {
    vector<int> nums = {1};
    for(auto a : tnums)nums.push_back(a);
    nums.push_back(1);
    int dp[303][303]{};
    int n = nums.size();
    for(int len = 3; len <= n; len++){
        for(int left = 0; left <= n - len; left++){
            int right = left + len - 1;
            for(int mid = left + 1; mid < right; mid++){
                dp[left][right] = max(dp[left][right], dp[left][mid] + dp[mid][right] + nums[left]*nums[mid]*nums[right]);
            }
        }
    }
    return dp[0][n - 1];
}
