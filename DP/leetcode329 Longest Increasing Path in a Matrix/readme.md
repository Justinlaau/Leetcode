# Brute force

<h2>Idea<h2>

<h4>
<h4>

<h3>
    Time complexity: O(N^3) <br>
    Space Complexity: O(N)
<h3>

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

