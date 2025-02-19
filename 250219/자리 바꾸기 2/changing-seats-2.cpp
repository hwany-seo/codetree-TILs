#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;


constexpr int N = 100000;
constexpr int K = 100000;

int arr[N + 1];
int a[K], b[K];

int main() {
	using Index = int;
	using PersonId = int;
	unordered_map<PersonId, unordered_set<Index>> m;

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		arr[i] = i;
		m[arr[i]].insert(i);
	}

	
	for (int i = 0; i < k; i++) {
		cin >> a[i] >> b[i];	
	}

	for (int outer = 0; outer < 3; outer++) {
		for (int i = 0; i < k; i++) {
			// a[i]th <-> b[i]th
			swap(arr[a[i]], arr[b[i]]); 
			
			// arr[a[i]] a[i]
			// arr[b[i]] b[i]
			m[arr[a[i]]].insert(a[i]); 
			m[arr[b[i]]].insert(b[i]); 

		}
	}

	for (int num = 1; num <= n; num++) {
		const auto& Set = m[num]; 
		cout << Set.size() << endl; 
	}
	return 0;
}