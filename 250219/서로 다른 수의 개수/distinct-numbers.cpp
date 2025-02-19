#include <iostream>
#include <unordered_set>

using namespace std; 

int main() {
	int n; 
	cin >> n; 

	unordered_set<int> s; 
	for (int i = 0; i < n; i++) {
		int val; 
		cin >> val; 
		s.insert(val); 
	}

	cout << s.size(); 
	
	
	return 0; 
}