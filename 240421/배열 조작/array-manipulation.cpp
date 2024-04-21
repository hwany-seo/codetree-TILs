/*
코드 트리 문제

문제)
배열에 다음 두 가지 연산을 적용할 수 있습니다.

R : 배열의 순서를 뒤집습니다.
D : 가장 앞의 원소를 버립니다. 원소가 없을 때 원소를 버리는 경우 에러가 발생합니다.
배열의 초기값과 수행할 연산이 주어졌을 때, 최종 결과를 구하는 프로그램을 작성해보세요.

*/

#include <deque>
#include <iostream>
using namespace std; 

int n; 
deque<int> deq; 
string cmd; 
void input() { 
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0); 

	//freopen_s(new FILE*, "input.txt", "r", stdin); 
	cin >> cmd; 
	cin >> n; 
	for (int i = 0; i < n; i++) {
		int val; 
		cin >> val; 
		deq.push_back(val); 
	}
}


void solve() {
	bool isReversed = false; 
	for (char ch : cmd) {
		if (ch == 'R') {
			// 배열의 순서를 뒤집는다. 
			isReversed = isReversed ? false : true; 
		}
		if (ch == 'D') {
			// 가장 앞의 원소를 버린다. 즉, s 가 가리키는 원소를 제거  
			if (deq.empty()) {
				cout << "error"; 
				return; 
			}
			if (isReversed) {
				deq.pop_back(); 
			}
			else {
				deq.pop_front();
			}
		}
	}
	
	if (isReversed) {
		for (auto it = deq.rbegin(); it != deq.rend(); ++it) {
			cout << *it << " "; 
		}
	}
	else {
		for (auto it = deq.begin(); it != deq.end(); ++it) {
			cout << *it << " "; 
		}
	}
}
int main() {
	input(); 
	solve(); 
}