# Idea

At the first time, I was thinking increasing subsequence with length 4 and do little modification. However, the time complexity is too high and very complicated.

What i noticed is that if we can find a pair of number, that is reversed pair, and we can use O(1) to get the how many number on the left handside smaller, and larger than a certain number, we can easily solve this problem in O(n^2).

I came up an idea to use merge sort to find all the reversed pair, but i noticed one thing, even though i find the reversed pair, i cannot find how many number smaller or larger than the reversed pair's number.

if reversed pair is (x, y), then number of quarplets is #lessX * #greatY

Precomputation needed !!!!

We can use something similar to suffix sum or prefix sum.

Let's define greater[i][j] where right handside of index i, the amount of number larger than j.

```    
int great[4002][4002]{};
for(int i = n - 2; i >= 0; i--){
    memcpy(great[i], great[i + 1], sizeof(great[i + 1]));
    for(int j = 1; j < nums[i + 1]; j++){
        great[i][j]++;
    }
}
```

we can use the same method to get the less.

```
int less[4002][4002]{};
for(int i = 2; i < n; i++){
    memcpy(less[i], less[i - 1], sizeof(less[i - 1]));
    for(int j = nums[i - 1] + 1; j <= n; j--){
        great[i][j]++;
    }
}
```

Once we can get the great and less in O(1), the rest of things is just find reversed pair in O(n^2)

```
int res = 0;
for(int i = 2; i < n; i++){
    for(int j = i + 1; j < n; j++){
        //found reversed pairs
        if(nums[i] > nums[j]){
            res+= great[j][nums[i]] * less[i][nums[j]];
        }
    }
}
```

# Futher optimization

As the question said nums is a permutation of n, Which means every number would only occur once. 

Great array can help us to find the less number.

1. There are only x number not larger than x
2. There are only n - j - 1 number behind j
3. There are only n - j - 1 - great[j][x] not larger than x right handside of j
4. as x's postition is behind j, thus x - n - j - 1 - great[j][x], is the number not less than x in the left handside of j 