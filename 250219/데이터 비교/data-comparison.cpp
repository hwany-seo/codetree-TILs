#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;
int arr1[100000];
int arr2[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    unordered_set<int> s; 
    for(int i = 0 ; i < n; i ++) { 
        s.insert(arr1[i]); 
    }    
    for(int i = 0 ; i < m; i ++) { 
        if(s.find(arr2[i]) != s.end()){ 
            cout << 1 << " " ; 
        }
        else { 
            cout << 0 << " " ;
        }
    }
    return 0;
}
