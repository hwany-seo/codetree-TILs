#include <iostream>
using namespace std;
int dp[10001][100] = { 0 }; 
int main() {
	int N; 
	int M; 
	cin >> N >> M; 
	int arr[100]; 
	for (int i = 0; i < N; ++i) cin >> arr[i]; 

	// dp table 초기화 
	for (int m = 1; m <= M; ++m) {
		for (int i = 0; i < N; ++i) {
			dp[m][i] = 1e9; 
		}
	}

	// dynamic go 
	for (int m = 1; m <= M; ++m) { 
		for (int i = 0; i < N; ++i) {
			// dp[m][i]: 합이 m이 되고 arr[i] 원소를 포함하는 부분수열 中 최소길이 
			if (arr[i] == m) dp[m][i] = 1; 
			int result = 1e9; 
			for (int j = 0; j < i; ++j) {
				if (m - arr[i] < 1)continue; 
				result = std::min(dp[m - arr[i]][j] + 1, result);
			}
			dp[m][i] = std::min(result, dp[m][i]);
		}
	}

	int result = 1e9; 
	for (int i = 0; i < N; ++i) {
		result = std::min(dp[M][i], result); 
	}

	if (result == 1e9) {
		cout << -1; 
	}
	else {
		cout << result; 
	}

	return 0; 
}