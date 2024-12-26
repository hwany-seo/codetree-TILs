#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std; 

int n, m; 
//vector<pair<int, int>> given_edges; 
vector<int> edges[100'001]; 
int indegree[100'001]; 

void initTopologicalSort() {
	cin >> n >> m; 
	for (int i = 0; i < m; ++i) {
		int a, b; 
		cin >> a >> b; 
		edges[a].push_back(b); 
		indegree[b]++; 
	}
}
int main() {
	initTopologicalSort(); 
	queue<int> qu; 

	for (int node = 1; node <= n; node++) {
		if (indegree[node] == 0)
			qu.push(node); 
	}

	vector<int> results; 
	while (!qu.empty()) {
		int now = qu.front();  
		qu.pop(); 
		results.push_back(now); 
		
		for (int next : edges[now]) {
			indegree[next]--; 
			if (indegree[next] == 0) {
				qu.push(next); 
			}
		}
	}

	for (int node : results) {
		cout << node << " "; 
	}
	return 0;

}