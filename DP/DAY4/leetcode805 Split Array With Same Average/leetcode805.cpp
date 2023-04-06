class Solution {
public:
    bool splitArraySameAverage(vector<int> &nums) {
        int N = nums.size(), SUM = accumulate(nums.begin(), nums.end(), 0);

        //we dont want floating point here
        // a - SUM/N => a*N - SUM -> would not affect the average
        for(auto & a : nums){
            a = a * N - SUM;
        }
        if(N == 1)return 0;

        vector<int> arrA;
        vector<int> arrB;
        for(int i = 0; i < N; i++){
            if(i < N/2)arrA.push_back(nums[i]);
            else arrB.push_back(nums[i]);
        } 
        set<int> s;
        for(int bitmask = 1; bitmask < (1 << arrB.size()); bitmask++){
            int sum = 0;
            for(int i = 0; i < arrB.size(); i++){
                if((1 << i) & bitmask)sum+=arrB[i];
            } 
            if(sum == 0)return 1;
            s.insert(sum);
        }
        int lsum = accumulate(arrA.begin(), arrA.end(), 0);
        for(int bitmask = 1; bitmask < (1 << arrA.size()); bitmask++){
            int sum = 0;
            for(int i = 0; i < arrA.size(); i++){
                if((1 << i) & bitmask)sum+=arrA[i];
            }
            // as we would have a rsum + lsum = 0, rsum = -lsum, the question ask us to form two array
            // so we cannot pick all the element in arrA and arrB, if sum == lsum, we pick every element 
            // from arr1, at the same time, if we find -lsum in arr2, that means we also pick every element,
            // in arr2
            /*
            右边全选了，和为 rsum，我们希望在左边找到一些元素，它们的和为 -rsum。但是呢，处理后的整个数组的和为0，所以lsum = -rsum。你会发现，
            我们需要在左边找到一些元素，它们的和为 lsum 。根据充要条件，左边这时候会被全选。
            （左边不全选，和还为 lsum 的话，左边的补集和就为0，这种情况下程序已经返回了，不会执行到这一步）
            */
            if(sum == 0 || (lsum != sum && s.find(-sum) != s.end())){
                return 1;
            }
        }
    
        return 0;
    }
};