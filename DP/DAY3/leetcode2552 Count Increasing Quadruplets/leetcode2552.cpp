long long countQuadruplets(vector<int>& nums) {
    //great[x][k] how many numbers in the right handside of x, larger than k
    int n(nums.size());
    int great[4002][4002]{};
    for(int i = n - 2; i >= 0; i--){
        memcpy(great[i], great[i + 1], sizeof(great[i + 1]));
        for(int j = 1; j < nums[i + 1]; j++){
            great[i][j]++;
        }
    }
    long long sum = 0;
    for(int j = 1; j < n; j++){
        for(int k = j + 1; k < n; k++){
            if(nums[k] < nums[j]){
                int numberGreaterThanJ = great[k][nums[j]];
                int numberLessThanK = n - 1 - j - great[j][nums[k]];
                sum += numberGreaterThanJ * (nums[k] - numberLessThanK);
            }
        }
    }
    return sum;
}