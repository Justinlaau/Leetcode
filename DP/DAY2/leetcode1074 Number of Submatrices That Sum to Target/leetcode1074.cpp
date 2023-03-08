int numSubmatrixSumTarget(vector<vector<int>>& nums, int target) {
    int n = nums.size(), m = nums.back().size();
    int res = 0;
    for(int i = 0; i < n; i++){
        vector<int> temp(m, 0);
        for(int j = i; j < n; j++){
            map<int, int> cnt;
            cnt[0] = 1;
            int iSum = 0;
            for(int k = 0; k < m; k++){
                temp[k] += nums[j][k];
                iSum += temp[k];
                if(cnt.find(iSum - target) != cnt.end()) res += cnt[iSum - target];
                if(cnt.find(iSum) == cnt.end())cnt[iSum] = 0;
                cnt[iSum]++;
            }
        }
    }
    return res;
}