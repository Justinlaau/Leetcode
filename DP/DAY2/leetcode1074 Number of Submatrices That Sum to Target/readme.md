# Idea 


```
    When it is 1d array, how can we get the 
    number of subarray that sums up to target in O(n) time complexity?
    Actually, it is very easy, it just like two sum problem.
    Let say target is K.
    interval of [0:j] = [0:i] + [i + 1:j]
    this is very basic concept of prefix sum
    if K exist in [0:j], then we can change the formula as follow:
    [0:j] = [0:i] + K
    if [0:i] can be constructed by given array, then our ans should ++

    so convert to code
    int sum = 0;
    map<int, int>m;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        if(m.find(sum - target)!=m.end())res+=m[sum - target];
        m[sum]++;
    }

    Even in a 2d array, we can still adopt this method.
    for example, 
    [1, 1, 1, 2]
    [2, 3, 4, 1]

    we can add them togther
    [3, 4, 5, 3]
    then it is 1d array problem again.
    which means if we want to find all the submatrix possibilities.
    we just need to merge multiple array to 1d array.
    so the time complexity would be O(n^2 * m);
```

