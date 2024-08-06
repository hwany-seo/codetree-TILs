#include <iostream>
using namespace std; 

int main() {
	int n;
	cin >> n; 

	long long dp[1001] = { 0 }; 
	dp[0] = 0; dp[1] = 0; 
	dp[2] = 1; 
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 2] % 10007 + dp[i - 3] % 10007) % 10007; 
	}

	cout << dp[n] % 10007;


	return 0; 
}