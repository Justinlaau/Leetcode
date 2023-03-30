#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;
const int n_ = 1e5 + 7;
bool cmp(int a, int b){
    return a >= b;
}
int minScore(string s, string t){
    int n = s.size(), m = t.size();
    vector<int> suf(n + 1, 0);
    suf[n] = m;
    for(int i = n - 1, j = m - 1; i >= 0; i--){
        if(j >= 0 && s[i] == t[j])j--;
        suf[i] = j + 1;
    }
    int ans = suf[0];
    if(ans == 0)return 0;
    for(int i = 0, j = 0; i < n; i++){
        if(s[i] == t[j]){
            ans = min(ans, suf[i + 1] - ++j);
        }
    }
    return ans;
}
int main(){
    cout << minScore("asdas", "dasdasd") << endl;
    return 0;
}