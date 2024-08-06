#include <iostream>
using namespace std; 

int memo[1001]; 

void initMemo() {
	for (int i = 0; i < 1001; i++) {
		memo[i] = -1; 
	}
}
int NumberOfCase(int n) {
	if (memo[n] != -1) return memo[n]; 
	if (n == 0 || n == 2 || n == 3) return 1; 
	return memo[n] = (NumberOfCase(n - 2) % 10007+ NumberOfCase(n - 3) % 10007) % 10007;
}
int main() {
	int n;
	cin >> n; 

	initMemo(); 
	cout << NumberOfCase(n); 
	/*int dp[1001] = { 0 }; 
	dp[0] = 0; dp[1] = 0; 
	dp[2] = 1; 
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 3]; 
	}

	cout << dp[n] % 10007;*/


	return 0; 
}