//#define 최대동전거슬러주기
#ifndef 최대동전거슬러주기

/*
문제 정의 : 금액 M 을 N 동전 종류들로 거슬러 줄 때, 최대 동전 개수를 구하시오 
dp[M] = N종류의 동전들의 최대 개수 

부분문제와의 관계
dp[M] = max(dp[M - coins[i]] + 1) 
(단, i는 동전의 종류를 나타낸다.) 

*/

#include <iostream>
#include <vector>
using namespace std; 

const int MAX_MONEY = 10000; 
int N, Money; 
std::vector<int> coins; 

int main() {
	int dp[MAX_MONEY + 1] = { 0 }; 
	cin >> N >> Money; 

	coins = vector<int>(N); // 동전 종류 
	for (int i = 0; i < N; ++i) {
		cin >> coins[i]; 
	}

	for (int m = 1; m <= Money; ++m) {
		for (int i = 0; i < N; ++i) {
			if (m - coins[i] < 0) continue; 
			dp[m] = std::max(dp[m - coins[i]] + 1, dp[m]); 
		}
	}
	if (dp[Money] == 0) cout << -1; 
	else cout << dp[Money];


}


#endif