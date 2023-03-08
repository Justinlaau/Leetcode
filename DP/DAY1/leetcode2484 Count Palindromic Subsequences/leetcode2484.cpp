const int mod = 1e9 + 7;
int n;
int dp_l[10005][11][11]{};
int dp_r[10005][11][11]{};
int prefix_sum[10005][11]{};
int suffix_sum[10005][11]{};
/*
as the question only require us to find length of 5
{i, j, k, j, i}
dp_l[k][i][j] = how many (i, j) subsequences before index k
dp_r[k][i][j] = how many (i, j) subsequences after index k
return sum(dp_l[k][i][j] * dp_r[k][j][i])
1. we use prefix sum and suffix sum to precompute the amount of each elements.
2. loop over the string
3. we inherent everything from the previous layer 
4. as the mid element s[k], can make many new subsequences (i, s[k]), we use prefix sum to get the amoumt of i, and pass to next layer
*/
int countPalindromes(string s) {
    if(s.length() < 5)return 0;
    n = s.size();
    prefix_sum[0][s[0] - '0'] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 11; j++)prefix_sum[i][j] += prefix_sum[i - 1][j];
        prefix_sum[i][s[i] - '0']+= 1;
    }
    suffix_sum[n - 1][s[n - 1] - '0'] = 1;
    for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j < 10; j++)suffix_sum[i][j] += suffix_sum[i + 1][j];
        suffix_sum[i][s[i] - '0']+=1;
    }
    //k is the mid of the palindrome
    for(int k = 1; k < n; k++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                dp_l[k][i][j] += dp_l[k - 1][i][j];
            }
        }
        //prefix_sum tells us how many number before k
        //and the current digit s[k] can form exactly the same number of combination as prefix_sum
        //but, it included the k, our dp state is only for combination before k and excluded k
        //so, who would use this result? the next layer, so dp_l[k + 1] !!
        for(int i = 0; i < 10; i++)dp_l[k + 1][i][s[k] - '0'] += prefix_sum[k - 1][i];
    }
    //k is the mid of the palindrome
    for(int k = n - 1; k >= 2; k--){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                dp_r[k][i][j] += dp_r[k + 1][i][j];
            }
        }
        for(int i = 0; i < 10; i++)dp_r[k - 1][s[k] - '0'][i] += suffix_sum[k + 1][i];
    }
    int res = 0;
    for(int k = 2; k < n - 2; k++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                (res += ((long long)dp_l[k][i][j] * (long long)dp_r[k][j][i])%mod)%=mod;
            }
        }
    }
    return res;
}