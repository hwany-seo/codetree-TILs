#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> edges[100001];
int indegree[100001];
void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		// a > b
		edges[a].push_back(b);
		indegree[b]++;
	}
}


int main() {
	init();

	queue<int> q;

	bool visited[100001] = { 0 };
	for (int node = 1; node <= n; node++) {
		if (indegree[node] == 0) {
			visited[node] = true;
			q.push(node);
		}
	}

	vector<int> results;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		results.push_back(now);
		for (int next : edges[now]) {
			if (visited[next])continue; 
			indegree[next]--;
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}

	// indegree가 
	if (results.size() != n) {
		cout << "Inconsistent";
	}
	else {
		cout << "Consistent"; 
	}
	return 0;
}