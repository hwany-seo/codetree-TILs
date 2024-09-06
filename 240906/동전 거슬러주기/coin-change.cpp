#include <iostream>
#include <vector>

/*
dp: item을 적절히 고르는 문제

*/

int N; // 동전 종류 
int money;
std::vector<int> coins;
int memo[10001];
void init() {
	//freopen_s(new FILE*, "Text.txt", "r", stdin); 
	std::cin >> N;
	std::cin >> money;
	coins = std::vector<int>(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> coins[i];
	}
	/*for (int i = 0; i <= 10000; i++) {
		memo[i] = 1e9;
	}
	for (int i = 0; i < N; ++i) {
		memo[coins[i]] = 1; 
	}*/
}

/*
* 문제에서 중요한것은 동전의 개수 / -> 추상화부분을 좀더 명확하게 서술할 수 있으면 좋을 거 같다.
* 문제정의
 MinCoinCount(금액 m) : 금액 m 을 동전으로 교환할 때 최소 동전 개수

* 부분 문제와의 관계
 MinCoinCount(M) = min of MinCoinCount(M - coins[i]) + 1 (i는 모든 코인)
*/

int MinCoinCount(int m) {
	if (memo[m] != 1e9) return memo[m];
	if (m <= 0) return -1; 

	int result = 1e9;
	for (int i = 0; i < N; ++i) {
		int ret = MinCoinCount(m - coins[i]); 
		if (ret == -1)continue; 
		result = std::min(ret, result);
	}

	if (result == 1e9) return memo[m] = -1; // 불가능 
	return memo[m] = result + 1;
}
int main() {
	init();
	//std::cout << MinCoinCount(money);
	
	int dp[10001] = { 0 }; 
	for (int i = 0; i < 10001; ++i) {
		dp[i] = 1e9; 
	}
	for (int i = 0; i < N; ++i) {
		dp[coins[i]] = 1;
	}

	for (int m = 0; m <= money; ++m) {
		dp[m] = 1e9; 
		for (int i = 0; i < N; ++i) {
			if (m - coins[i] < 0) continue; 
			if (dp[m - coins[i]] == 1e9)continue; 
			dp[m] = std::min(dp[m - coins[i]] + 1, dp[m]); 
		}
	}
	if (dp[money] == 1e9) std::cout << -1; 
	else std::cout << dp[money]; 
}