# Brute force

<h2>Idea<h2>

<h4>

```
The question only require us to find palidromic susequence with length with 5.

{i, j, k, j, i}

from the above example, we know if we can compute the possibilities of {i, j} subsequences before k, we can multiple to the possibilities of {j, i} after k, to get the combinations

With this idea, we can find a brute force method, loop over the string, and set the current idx to be k, and use 2 for loop to find all the possibilies of all number, store the answer in dp_l, and do the same thing with after k, store the answer in dp_r.

return value sum(dp[k][i][j] * dp[k][j][i])





    Time complexity: O(N^3) <br>
    Space Complexity: O(N)
```
<h4>

```
Solution: 
    const int mod = 1e9 + 7;
    int n;
    int dp_l[10005][11][11]{};
    int dp_r[10005][11][11]{};
    int countPalindromes(string s) {
        n = s.size();
        for(int k = 2; k < n; k++){
            for(int i = 0; i < k; i++){
                for(int j = i + 1; j < k; j++){
                    (dp_l[k][s[i] - '0'][s[j] - '0'] += 1)%=mod;
                }
            }
        }
        for(int k = n - 1; k >= 2; k--){
            for(int i = n - 1; i > k; i--){
                for(int j = i - 1; j > k; j--){
                    (dp_r[k][s[i] - '0'][s[j] - '0'] += 1)%=mod;
                }
            }
        }
        int res = 0;
        for(int k = 2; k < n - 2; k++){
            for(int i = 0; i < 11; i++){
                for(int j = 0; j < 11; j++){
                    (res += (dp_l[k][i][j] * dp_r[k][i][j])%mod)%=mod;
                }
            }
        }
        return res;
    }
```

# How to optimize the solution? 

<h4>

    you would notice that finding combination of {i, j} is not difficult at all.
    if we know the occurences of each digit before j.
    for example, "12141236" 
                         ^
                         j
    
    if we know 1 occurs 3 times, then {1, 6} is 3, {2, 6} is 2, the combination of {i, j} depends on the occurences of i.

    so, we use a prefix sum to store the occurences of each digits in certain position. 

<h4>
