int longestValidParentheses(string s) {
    // res = return val, count = the difference of ')' and '(', pval = digit value of ')' and '('
    int res = 0, count =0, pval;
    vector<int> stack;
    // '(' = 1, ')' = -1
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(')pval = 1;
        if(s[i] == ')')pval = -1;
        //number of ')' > number of '('
        if(count + pval < 0){
            res = max(res, int(stack.size()));
            while(!stack.empty())stack.pop_back();
            count = 0;
        }else{
            stack.push_back(pval);
            count += pval;
        }
    }
    count  = 0; // count the difference of ')' and '('
    int tmp=0; // store the length of valid subarray
    //'(' > ')'
    while(!stack.empty()){
        count += stack.back();
        //stack-> [(( (()) , there are two superfluous openning parentheses, which count > 0. 
        if(count <= 0){
            tmp++;
            res = max(res, tmp);
        }else{
            tmp = 0;
            count = 0;
        }
        stack.pop_back();
    }
    return res;
}