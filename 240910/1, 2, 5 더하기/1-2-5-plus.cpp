//#define SKIP_THIS_FILE3
#ifndef SKIP_THIS_FILE3

/*
정수 N을 1,2,5 더하기로 만들기 (코드트리)

더하는 조합의 수를 구하는 문제 

문제 정의 : N 을 1,2,5 의 덧셈으로 나타낼 수 있는 경우의 수를 구한다.
dp[number] : 1,2,5 로 나타낼 수 있는 경우의 수 

부분문제와의 관계
dp[number] = dp[number - 1] + dp[number - 2] + dp[number - 5];
(number는 1부터 1000)
*/
#include <iostream>
using namespace std; 

int main() {
	int dp[1001] = { 0 }; 
	dp[1] = 1; 	dp[2] = 1; 	dp[5] = 1;  // init

	int N; 
	cin >> N; 

	int target[3] = { 1,2,5 }; 
	for (int num = 1; num <= N; ++num) {
		for (int t = 0; t < 3; ++t) {
			if (num - target[t] < 1)continue; 
			if (dp[num - target[t]] == 0)continue; 

			dp[num] += dp[num - target[t]] % 10007; 
		}
		dp[num] %= 10007; 
	}

	cout << dp[N]; 
	return 0; 
}

#endif