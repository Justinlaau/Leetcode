# Idea

```
This is a NP-complete problem, we cannot use any greedy here.
So, we consider brute force.
Use bitmask to store the relations.

    int graph[20]{};
    for(const auto&p : relations){
        int prereg = p[0] - 1;
        int reg = p[1] - 1;
        graph[reg] |= 1<<prereg;
    }

we use dp to do brute force.
dp[i] represent the bitmask i needs to use how many sem to finish

there are few steps to check if the course was avaliable to reg or not

    1. prereq fullfilled or not
    2. the couse i we want to reg, havent taken before.
        int reg_able = 0;
        for(int i = 0; i < n; i++){
            //we want to reg i, so check all the prereg
            if((((1<<i)&taken) == 0) && ((graph[i] & taken) == graph[i])){
                reg_able |= (1<<i);
            }
        }
        reg i and see the result is better or not
            for(int i = reg_able; i != 0; i = i-1 & reg_able){
            if(__builtin_popcount(i) <= k){
                dp[taken|i] = min(dp[taken|i], dp[taken]+1);
            }
        }
    
```