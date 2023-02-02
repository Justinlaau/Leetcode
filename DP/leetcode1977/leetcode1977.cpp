#include<iostream>
#include<vector>
using namespace std;
//only compare the digit after the common prefix
int compare(int i, int j, int len, vector<vector<int> >&same, string &s){
	int common(same[i][j]);
	if(common >= len)return 1;
	if(s[i + common] < s[j + common])return 1;
	else return 0;
}
int numberOfCombination(string num){
	int n(num.length());
	//edge case
	if(num[0]=='0')return 0;
	vector<vector<int> >same(n + 1, vector<int>(n + 1, 0));
	//same[i][j] = the length of the common prefix of num[0:i] and num[0:j]
	for(int i(n - 1); i >= 0; --i){
		for(int j(n - 1); j >= 0; --j){
			if(num[i] == num[j]){
				same[i][j] = same[i + 1][j + 1] + 1;
			}	
		}
	}
	return 1;
}
	
int main(){
	string s("1283192381923891");
	cout << numberOfCombination(s) << endl;
}

