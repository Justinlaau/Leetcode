# Idea

```
we have done many grid and maze problem before, for example, from (1,1) to (n, m) shortest path...
Actually, they are the same as this question. 
The only difference place is where to start and where to end.

In fact the recursion would help us to stop, if there were no any near point smaller than (x, y).
we can try to start with any point, you would notice that the time complexity is pretty high, because some of the paths you went before and you went it again and again. Start with different point wouldn't make a point's accessible length larger or shorter, so, we cache the point's accessible length. It significantly reduce our time complexity.
```

