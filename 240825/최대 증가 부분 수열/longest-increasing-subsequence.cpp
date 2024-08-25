#include <iostream>
#include <vector>
using namespace std; 

int main() {
	int N; 
	cin >> N; 
	vector<int> numbers(N);
	for (int i = 0; i < N; ++i) {
		cin >> numbers[i]; 
	}

	const int MAXN = 1000; 
	int dp[MAXN] = { 0 }; 
	// dp[i] 는 i 번째 원소가 포함된 
	// 가장 긴 증가하는 부분 수열의 길이
	// dp[i] = max dp[k] + 1
	dp[0] = 1;
	for (int i = 0; i < N; ++i) {
		dp[i] = 1;
		for (int k = 0; k < i; ++k) {
			if (numbers[i] <= numbers[k])continue; 
			dp[i] = std::max(dp[i], dp[k] + 1); 
		}
	}
	
	int result = -1;
	for (int i = 0; i < N; ++i) {
		result = std::max(result, dp[i]); 
	}
	cout << result; 

	return 0; 
}