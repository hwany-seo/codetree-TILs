#include <iostream>
using namespace std;

int n;
int dp[1000];
/*
dp[i]  : i 번째까지 선택을 고려했을 때, i 번째를 포함하는 선택에서 최대 선분수
k < i 인 모든 k에 대해서 i번째 선분과 안겹치는 dp[k] 중 최대 값 + 1

*/
struct Line {
	int x1;
	int x2;
};
Line arr[1000];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].x1 >> arr[i].x2;
	}

	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		// dp[i] 
		for (int k = 0; k < i; ++k) {
			if (arr[i].x1 <= arr[k].x1 && arr[k].x1 <= arr[i].x2) {
				continue;
			}
			if (arr[k].x1 <= arr[i].x1 && arr[i].x1 <= arr[k].x2) {
				continue;
			}
			dp[i] = std::max(dp[i], dp[k] + 1);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i){
		ans = std::max(dp[i], ans); 
	}
	cout << ans; 
	return 0;
}