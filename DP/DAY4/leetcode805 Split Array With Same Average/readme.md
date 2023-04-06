# Idea
we know sum(arrA)/na = sum(arrB)/nb is the requirment we need to find.<br>
we can simply it to 
```
sum(arrA)/na = (SUM - sum(arrA))/(N - na)
(N - na)*sum(arrA) = (SUM - sum(arrA))*na
N*sum(arrA) - sum(arrA) * na = SUM*na - sum(arrA)*na
N*sum(arrA) = SUM*na
sum(arrA)/na = SUM/N
```

you can see, average(arrA) == average(arr) == average(arrB)<br>
we can now deduct all the element in the arr by average(arr)<br>
now the average(arrA) == 0 == average(arr) == average(arrB) <br>
if the average is 0, that means the sum(arr) or sum(arrA) is 0, so, we just need to<br>
find a subsequence that sums up to be 0, use the idea of meet in middle and bitmask<br>
can solve this question easily, if you have done the question in day3 you would know <br>
how to solve it.