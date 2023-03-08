vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int preMaxSum[20000 + 2]{nums[0]};
    int preMaxIdx[20000 + 2]{0};
    int ptmp = nums[0];
    for(int i = 1; i < n - k + 1; i++){
        if(i < k){
            preMaxSum[i] += preMaxSum[i - 1]+nums[i];
            preMaxIdx[i] = preMaxIdx[i - 1];
            ptmp+= nums[i];
        }
        else{
            ptmp += nums[i] - nums[i - k];
            if(ptmp > preMaxSum[i - 1]){
                preMaxIdx[i] = i - k + 1;
                preMaxSum[i] = ptmp;
            }else{
                preMaxIdx[i] = preMaxIdx[i - 1];
                preMaxSum[i] = preMaxSum[i - 1];
            }
        }
    }
    int suffMaxSum[20000 + 2]{};
    suffMaxSum[n - 1] = nums[n - 1];
    int suffMaxIdx[20000 + 2]{};
    suffMaxIdx[n - 1] = n - 1;
    int tmp = nums[n - 1];
    for(int i = n - 2; i >= 0; i--){
        if(i >= n - k){
            suffMaxSum[i] += suffMaxSum[i + 1]+nums[i];
            suffMaxIdx[i] = i;
            tmp += nums[i];
        }
        else{
            tmp += nums[i] - nums[i + k];
            if(tmp >= suffMaxSum[i + 1]){
                suffMaxIdx[i] = i;
                suffMaxSum[i] = tmp;
            }
            else{
                suffMaxIdx[i] = suffMaxIdx[i + 1];
                suffMaxSum[i] = suffMaxSum[i + 1];
            }
        }
    }
    int midSum = 0;
    for(int i = k; i < k + k; i++){
        midSum += nums[i];
    }
    int mtmp = midSum;
    int midMaxSum = midSum + preMaxSum[k - 1] + suffMaxSum[2*k];
    vector<int> res{0, k, suffMaxIdx[2*k]};
    for(int i = k + 1; i < n - k; i++){
        mtmp = mtmp - nums[i - 1] + nums[i + k - 1];
        if(preMaxSum[i - 1] + suffMaxSum[i + k] + mtmp > midMaxSum){
            res[1] = i;
            res[0] = preMaxIdx[i - 1];
            res[2] = suffMaxIdx[i + k];
            midMaxSum = preMaxSum[i - 1] + suffMaxSum[i + k] + mtmp;
        }
    }
    return res;
}