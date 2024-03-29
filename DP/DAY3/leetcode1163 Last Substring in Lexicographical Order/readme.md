# brute force

find all the substring and sort them, return the max one

```
    string lastSubstring(string s) {
        //brute force 
        vector<string> res;
        for(int len = 0; len < s.length(); len++){
            for(int i = 0; i + len < s.length(); i++){
                res.push_back(s.substr(i, len + 1));
            }
        }
        sort(res.begin(), res.end());
        return res.back();
    }
```

# O(N) solution

The answer must have max character at the begining and the longest length<br>
<li> step1: find the first occurences of max character, we mark the index as pos.
<li> step2: find the next occurences of max character's index cloest to the pos.
<li> step3: use a while to do comparasion
<li> repeat all these steps until all the maxChar have been looped once

```
//mark the index first
if(s[cur] == maxChar){
    int firstString = pos + 1, secondString = cur + 1;
    while(firstString < cur && secondString < n){
        if(s[firstString] < s[secondString]){
            pos = cur;
            cur = cur + 1;
            break;
        }else if(s[firstString] > s[secondString]){
            cur = secondString + 1;
            break;
        }else{
            firstString++;
            secondString++;
        }
    }
}

```