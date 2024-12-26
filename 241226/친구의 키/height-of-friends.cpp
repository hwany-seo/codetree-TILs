#include <iostream>
#include <vector>
#include <tuple>
#include <stack>

using namespace std;

int n, m;
//vector<pair<int, int>> given_edges; 
vector<int> edges[100'001];
bool isNoRoot[100'001];
void initTopologicalSort() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		isNoRoot[b] = true;
	}
}

stack<int> results;
bool visited[100'001];
void dfs(int now) {
	for (int next : edges[now]) {
		if (visited[next])continue;
		visited[next] = true;
		dfs(next);
	}

	results.push(now);
}
int main() {
	initTopologicalSort();

	// dfs
	for (int node = 1; node <= n; node++) {
		if (isNoRoot[node])continue;
		visited[node] = true;
		dfs(node);
	}

	while (!results.empty()) {
		cout << results.top() << " ";
		results.pop(); 
	}
	return 0;

}