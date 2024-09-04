#include<iostream>
using namespace std; 

int n; 
int arr[1000]; 
int dp[1000]; 
int dp_reverse[1000]; 
/*
	* 문제 정의 
	dp_incr[i] : 
	배열의 인덱스 오름차순에서 증가하는 부분수열에서 
	i번째 숫자를 선택하였을때,
	최장 부분수열의 크기 

	* 부분 문제와의 관계식 
	dp_incr[i] = max of dp_incr[k] + 1, k < i 

	dp_reverse 는 마지막 원소부터 dp_incr를 거꾸로 구하는
	방식으로 구할 수 있다. 

	* 문제 정의
	배열의 인덱스 내림차순에서 증가하는 부분수열에서

*/

/* 
	문제 풀이 key idea 
	dp_incr[i] + dp_reverse[i] - 1의 최대값을 구한다
*/
void init() {
	cin >> n; 
	for (int i = 0; i < n; ++i) {
		cin >> arr[i]; 
	}
}
int main() {
	init(); 
	for (int i = 0; i < n; ++i) {
		dp[i] = 1; 
		//  [----]i i 이전범위 중
		for (int k = 0; k < i; ++k) {
			if (arr[i] <= arr[k]) continue; 
			dp[i] = std::max(dp[k] + 1, dp[i]); 
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		dp_reverse[i] = 1; 
		// i[----] i 이후 범위 중 
		for (int k = i + 1; k < n; ++k) {
			if (arr[i] <= arr[k]) continue;
			dp_reverse[i] = std::max(dp_reverse[k] + 1, dp_reverse[i]);
		}
	}

	int answer = 0; 
	for (int i = 0; i < n; ++i) {
		answer = std::max(dp[i] + dp_reverse[i] - 1, answer); 
	}
	cout << answer; 
	return 0; 
}