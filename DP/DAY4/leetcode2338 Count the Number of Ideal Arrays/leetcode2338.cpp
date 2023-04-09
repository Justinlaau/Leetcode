class Solution {
public:
    void linear_seive(vector<int> &v, int N){
        bool vis[100000];
        memset(vis, 0, sizeof(vis));
        for (int i = 2; i <= N; ++i) {
            if (!vis[i]) {
              v.push_back(i);
            }
            for (auto p : v) {
                if (i * p > N) break;
                vis[i * p] = 1;
                if (i % p == 0) {
                  break;
                }
            }
        }
    }
    const int mod = 1e9 + 7;
    int idealArrays(int n, int maxValue) {
        vector<int> prime;
        linear_seive(prime, maxValue);
        long long dp[100005][30]{};
        //place k same things in n box, (you can place multiple in one box)
        //use dp to calculate it.
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i][0] = 1;
            for(int j = 1; j <= 14; j++){
                for(int k = 0; k <= j; k++){
                    (dp[i][j] += dp[i - 1][j - k]*1LL %mod)%=mod;
                }
            }
        }
        int res = 0;
        for(int i = 1; i <= maxValue; i++){
            long long tmp = 1, last_p = i;;
            for(auto p : prime){
                int count  = 0;
                while((last_p % p) == 0){
                    count++;
                    last_p/=p;
                }
                (tmp *= dp[n][count])%=mod;
            }
            (res += tmp%mod)%=mod;
        }
        return res;
    }
};