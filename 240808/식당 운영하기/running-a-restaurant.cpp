#include <iostream>
#include <queue>
#include <algorithm>
using namespace std; 

struct Node {
	int price; 
	int delayTime; 
	bool operator<(const Node& other) const {
		return price < other.price;
	}
};

bool cmp(const Node& left, const Node& right) {
	return left.delayTime > right.delayTime; 
}
int main() {
	int n, p, d; 
	cin >> n; 
	vector<Node> arr; 
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		arr.push_back({ p,d }); 
	}

	std::sort(arr.begin(), arr.end(), cmp); 

	priority_queue<Node> pq; 
	
	int index = 0; 
	long long result = 0; 
	for (int limitTime = arr[0].delayTime; limitTime >= 1; limitTime--) {
		while (index < arr.size() && limitTime <= arr[index].delayTime) {
			pq.push(arr[index]); 
			index++; 
		}
		if (pq.empty()) continue; 
		result += pq.top().price;
		pq.pop(); 
	}

	cout << result; 
	return 0; 
}