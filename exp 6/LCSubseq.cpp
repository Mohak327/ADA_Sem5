#include<iostream>
#include<string>
#include<vector>

using namespace std;

void LCS(string s1,string s2){
	int n = s1.length();
	int m = s2.length();

	vector<vector<int>> dp(n+1,vector<int>(m+1,0));

	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 || j==0){
				dp[i][j] = 0;
			}
			else{
				if(s1[i-1] == s2[j-1]){
					dp[i][j] = dp[i-1][j-1]+1;
				}
				else{
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
	}
	cout << "Length of longest common subsequence is: " << dp[n][m] << endl;
	string ans = "";
	int i = n;
	int j = m;

	while(i>0 && j>0){
		if(s1[i-1] == s2[j-1]){
			ans = s1[i-1] + ans;
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]) {
			i--;
		}
		else{
			j--;
		}
	}
	cout << "Longest common subsequence is: " << ans << endl;
	return ;
}

int main() {
	string s1,s2;
	cout << "\nEnter string 1: ";
	cin>>s1;
	cout << "Enter string 2: ";
	cin>>s2;
	LCS(s1,s2);
	return 0;
}