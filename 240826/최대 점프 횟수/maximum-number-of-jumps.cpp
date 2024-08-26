#include <iostream>
#include <vector>
using namespace std; 

const int MAXN = 1000; 
int N; 
vector<int> stages; 
void init() {
	cin >> N; 
	stages = vector<int>(N); 
	for (int i = 0; i < N; i++) {
		cin >> stages[i]; 
	}
}

int memo[MAXN]; 
void initMemo() {
	for (int i = 0; i < N; i++) {
		memo[i] = -1;
	}
	memo[0] = 0; 
}
int MaxJumpCount(int index) {
	if (memo[index] != -1)return memo[index]; 
	int result = -1; 
	for (int i = 0; i < index; i++) {
		if (stages[i] + i < index)continue; 
		result = std::max(MaxJumpCount(i) +1, result);
	}

	return memo[index] = result; 
}
int main() {
	init(); 
	initMemo(); 
	
	MaxJumpCount(N - 1); 
	
	int result = -1; 
	for (int i = 0; i < N; ++i)result = max(result, memo[i]); 
	cout << result; 

	return 0; 
}