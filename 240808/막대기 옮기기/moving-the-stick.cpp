#include <iostream>
using namespace std;

int main() {
	const int MAXN = 6; 
	int n; 
	cin >> n;
	int stage[MAXN + 1][MAXN + 1] = { 0 }; 
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			cin >> stage[r][c]; 
		}
	}

	const int STATE = 3; // 0 : 가로 , 1 : 세로 , 2 : 대각 
	long long dp[MAXN + 1][MAXN + 1][STATE] = {0};
	if(stage[1][2] == 0 && stage[1][1] == 0) dp[1][2][0] = 1;
	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= n; col++) {
			if (row == 1 && col == 2)continue; 
			if (stage[row][col] != 0)continue; 
			dp[row][col][0] = dp[row][col - 1][0] + dp[row][col - 1][2]; 
			dp[row][col][1] = dp[row-1][col][1] + dp[row-1][col][2]; 
			if (stage[row - 1][col] != 0 || stage[row][col - 1] != 0)continue; 
			dp[row][col][2] = dp[row-1][col - 1][0] + dp[row-1][col - 1][1] + dp[row - 1][col - 1][2];
		}
	}
	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2] ; 
	return 0;
}