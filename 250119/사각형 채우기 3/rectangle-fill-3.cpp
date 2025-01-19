#include <iostream>

using namespace std;

int n;

// dp[3] = dp[2] * 2 (한칸 채우는 방법) + dp[1] * 3(두 칸 채우는 방법)
// dp[n] = dp[n-1] * 2 + dp[n - 2] * 3; 
int main() {
    cin >> n;
    int dp[1001] = { 0 } ; 
    dp[0] = 1;
    dp[1] = 2; 
    dp[2] = 7; 

    const int DIV = 1000000007;
    for(int i = 3; i <= n; i ++) { 
        dp[i] = (dp[i-1] * 2 % DIV+ dp[i-2] * 3 % DIV + dp[i-3] * 2% DIV)% DIV; 
    } 

    cout << dp[n];

    return 0;
}
