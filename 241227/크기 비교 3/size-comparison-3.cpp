#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 32000;
int indegree[MAXN + 1];
vector<int> edges[MAXN + 1]; 

int n, m; 
void input() {
	cin >> n >> m; 
	for (int i = 0; i < m; i++) {
		int a, b; 
		cin >> a >> b;  // a < b 
		edges[a].push_back(b); 
		indegree[b]++; 
	}
}

struct cmp {
	bool operator()(const int left, const int right) const {
		return left > right; 
	}
};
int main() {
	input(); 

	priority_queue<int, vector<int>, greater<int>> pq; 
	for (int node = 1; node <= n; node++) {
		if (indegree[node] == 0) pq.push(node); 
	}

	vector<int> results;
	results.reserve(n); 
	while (!pq.empty()) {
		int now = pq.top(); 
		pq.pop(); 
		results.push_back(now); 

		for (int next : edges[now]) {
			indegree[next]--; 
			if (indegree[next] == 0) {
				pq.push(next); 
			}
		}
	}

	for (int num : results) {
		cout << num << " "; 
	}
	return 0;
}