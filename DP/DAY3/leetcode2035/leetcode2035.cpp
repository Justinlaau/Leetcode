using LL = long long;
class Solution {
public:
    map<int, vector<LL>> genSum(vector<int> &arr){
        map<int, vector<LL>> ret;
        for(int bitmask = 0; bitmask < (1 << arr.size()); bitmask++){
            int oneBit = __builtin_popcount(bitmask);
            LL sum = 0;
            for(int i = 0; i < arr.size(); i++){
                if((1 << i) & bitmask)sum += arr[i];
            }
            ret[oneBit].push_back(sum);
        }
        for(auto &x : ret){
            sort(x.second.begin(), x.second.end());
        }
        return ret;
    }
    int minimumDifference(vector<int>& nums) {
        if(nums.empty())return 0;
        int N = nums.size();
        int n = N/2;
        vector<int> a1;
        vector<int> a2;
        for(int i = 0; i < N; i++){
            if(i < n)a1.push_back(nums[i]);
            else a2.push_back(nums[i]);
        }
        LL SUM = accumulate(nums.begin(), nums.end(), 0LL);
        map<int, vector<LL>> sum = genSum(a2);
        LL res = LLONG_MAX;
        for(int bitmask = 0; bitmask < (1 << n); bitmask++){
            int oneBit = __builtin_popcount(bitmask);
            LL x(0);
            for(int i = 0; i < n; i++){
                if((1 << i) & bitmask)x += a1[i];
            }
            int restOneBit = n - oneBit;
            auto bsIter = lower_bound(sum[restOneBit].begin(), sum[restOneBit].end(), SUM/2 - x);
            if(bsIter != sum[restOneBit].end())res = min(res, abs(SUM - 2* (*bsIter + x)));
            if(bsIter != sum[restOneBit].begin())res = min(res, abs(SUM - 2* (*prev(bsIter) + x)));
        }
        return res;
    }
};