#include <iostream>
#include <unordered_set>

using namespace std; 

int main() {
	int n; 
	cin >> n; 

	unordered_set<int> s{}; 
	for (int i = 0; i < n; i++) {
		int val; 
		cin >> val; 
		s.insert(val); 
	}

	int m; 
	cin >> m; 
	for (int i = 0; i < m; i++) {
		int val; 
		cin >> val; 
		if (s.find(val) == s.end()) {
			cout << 0 << endl; 
		}
		else {
			cout << 1 << endl; 

		}
	}
	
	return 0; 
}