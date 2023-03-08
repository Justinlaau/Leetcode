//dp[i][j] is how many ways ending with number nums[i:j]
//dp[i][j] = dp[i - j + i - 1][i - 1] + dp[j - i][i - 1] + dp[j - i - 1][i - 1] + ..... dp[i - 1][i - 1]
//time complexity would be O(n^3)
//how to optimize it?
//use prefix_sum, but this prefix_sum is 2d, the first dimension represents the layer, second is the sum to j
//if(nums[j - i + 1 : i - 1] <= nums[i : j])dp[i][j] = (prefix_sum[i][i - 1] - prefix_sum[i][j - i + 1 - 1])  
const int mod = 1e9 + 7;
int compare(int i, int j, int len, vector<vector<int>>&same, string &s){
    //returns true if s[i: i+len-1] <= s[i+len,i+2*len-1] 
    
    int common = same[i][j];   
    if(common >= len) return 1;              //equal substrings
    if(s[i+common] < s[j+common]) return 1;  //first substring is smaller
    else return 0;
}
int numberOfCombinations(string num) {
    if(num[0] == '0')return 0;
    int n = num.length();
    vector<vector<int>>same(n + 1, vector<int>(n + 1, 0));
    //init same 
    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(num[i] == num[j]){
                same[i][j] = same[i + 1][j + 1] + 1;
            }
        }
    }
    
    vector<vector<int> > pref(n + 1, vector<int>(n + 1, 0));
    //pref used to fast cal the sum from dp[0][0] to dp[0][j]
    //init pref
    for(int j=0; j<n; ++j) pref[0][j] = 1;
    for(int i = 1; i < n; i++){
        //if leading 0, inherent previous layer
        if(num[i] == '0'){
            pref[i] = pref[i - 1];
            continue;
        }
        for(int j = i; j < n; j++){
            //len the length of second last number
            int len = j - i + 1;
            int prevStart = i - len, count = 0;
            //it can only build one number
            if(prevStart < 0){
                count = pref[i - 1][i - 1]%mod;
            }else{
                //it can build multi number before num[i:j]
                count = pref[i - 1][i - 1]%mod - pref[prevStart][i - 1]%mod;
                if(compare(prevStart, i, len, same, num)){
                    int cnt = !prevStart ? pref[prevStart][i-1]%mod:pref[prevStart][i - 1]%mod - pref[prevStart - 1][i - 1]%mod;
                    (count += cnt%mod)%=mod;
                }
            }
            pref[i][j] = (pref[i - 1][j] + (long long)count)%mod;
        }
    }
    return pref[n - 1][n - 1];
}