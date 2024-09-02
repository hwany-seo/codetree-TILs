#include <iostream>
using namespace std; 

int N, M; 
int board[51][51];
int dp[51][51]; 
void init() {
	cin >> N >> M; 
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < M; ++col) {
			cin >> board[row][col]; 
		}
	}

	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < M; ++col) {
			dp[row][col] = 0; 
		}
	}
}
int main() {
	init(); 
	dp[0][0] = 1; 
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < M; ++col) {
			for (int inner_row = row - 1; inner_row >= 0; --inner_row) {
				for (int inner_col = col - 1; inner_col >= 0; --inner_col) {
					if (dp[inner_row][inner_col] == 0)
						continue; 
					if (board[inner_row][inner_col] >= board[row][col])
						continue; 
					
					dp[row][col] = std::max(dp[inner_row][inner_col] + 1, dp[row][col]); 
				}
			}
		}
	}

	int result = 0; 
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < M; ++col) {
			result = std::max(result, dp[row][col]); 
		}
	}
	cout << result; 

	return 0; 
}