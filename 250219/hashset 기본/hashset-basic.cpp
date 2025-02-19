#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int n;
string command[100000];
int x[100000];

constexpr unsigned int Hash(const char* str) {
    unsigned int hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) + *str++;
    }
    return hash;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command[i] >> x[i];
    }

    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        switch (Hash(command[i].c_str())) {
        case Hash("find"):
            if (s.find(x[i]) != s.end()) {
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
            break;
        case Hash("add"):
            s.insert(x[i]);
            break;
        case Hash("remove"):
            s.erase(x[i]);
            break;
        }
    }

    return 0;
}