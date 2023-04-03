class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> arrA;
        vector<int> arrB;
        for(int i = 0; i < n;i++){
            if(i < n/2)arrA.push_back(nums[i]);
            else arrB.push_back(nums[i]);
        }
        vector<int> sumA{0};
        vector<int> sumB{0};
        for(int bitmask = 0; bitmask < (1 << arrA.size()); bitmask++){
            int sum = 0;
            for(int j = 0; j <= 20; j++){
                if(bitmask & (1 << j))sum+=arrA[j];
            }
            sumA.push_back(sum);
        }
        for(int bitmask = 0; bitmask < (1 << arrB.size()); bitmask++){
            int sum = 0;
            for(int j = 0; j <= 20; j++){
                if(bitmask & (1 << j))sum+=arrB[j];
            }
            sumB.push_back(sum);
        }
        sort(sumA.begin(), sumA.end());
        sort(sumB.begin(), sumB.end());
        int ans = abs(goal);
        for(int i = 0; i < sumA.size(); i++){
            int left = 0, right = sumB.size() - 1;
            while(left <= right){
                int mid = (left + right)/2;
                int sum = sumA[i] + sumB[mid];
                ans = min(ans, abs(sum - goal));
                if(goal == sum)return 0;
                if(sum <= goal){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }
        return ans;
    }
};