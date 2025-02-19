#include <iostream>
#include <unordered_set>
using namespace std;

int n;
string command[100000];
int x[100000];

constexpr unsigned int Hash(string str) { 
    str[0] ? static_cast<unsigned int>(str[0]) + 33 * Hash(str + 1) : 5381;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command[i] >> x[i];
    }

    unordered_set<int> s; 
    for (int i = 0; i < n; i ++){ 
        switch(Hash(command[i])){ 
            case Hash("find"):
                if(s.find(x[i]) != s.end()){ 
                    cout << "true" << endl; 
                }
                else { 
                    cout << "false" << endl; 
                }
                break; 
            case Hash("add") :
                s.insert(x[i]); 
                break; 
            case Hash("remove"):
                s.erase(x[i]); 
                break; 
        }
    }

    return 0;
}
