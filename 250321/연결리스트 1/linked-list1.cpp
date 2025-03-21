#include <iostream>

using namespace std;

string S_init;
int N;
int command[250000];
string S_value[250000];

struct Node {
    string value;
    Node* next;
    Node* prev;

    Node(string value, Node* next, Node* prev)
        : value{ value }, next{ next }, prev{ prev }
    {    }
};

Node* cur;
void createNodeAndinsertToCurNext(string value) {
    // cur-> new 
    Node* ptr = new Node{ value ,nullptr, nullptr }; 
    ptr->prev = cur; 
    ptr->next = cur->next; 
    cur->next = ptr; 
}
void createNodeAndinsertToCurPrev(string value) {
    // new -> cur
    Node* ptr = new Node{ value, nullptr, nullptr };
    ptr->next = cur;
    ptr->prev = cur->prev; 
    cur->prev = ptr; 
}

void printCurInfo() {
    if (cur->prev != nullptr) {
        cout << cur->prev->value << " "; 
    }
    else {
        cout << "(Null)" << " "; 
    }

    cout << cur->value << " "; 

    if (cur->next != nullptr) {
        cout << cur->next->value << " "; 
    }
    else {
        cout << "(Null)" << " "; 
    }

    cout << endl; 
}

int main() {
    cin >> S_init;
    cin >> N;

    cur = new Node(S_init,nullptr, nullptr);

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == 1 || command[i] == 2) {
            cin >> S_value[i];
        }
    }

    // Please write your code here.
    for (int i = 0; i < N; i++) {
        int cmd = command[i];
        if (cmd == 1) { // new -> cur 
            string value = S_value[i];
            createNodeAndinsertToCurPrev(value); 
        }
        if (cmd == 2) {
            string value = S_value[i]; 
            createNodeAndinsertToCurNext(value); 
        }
        if (cmd == 3) {
            if (cur->prev != nullptr) {
                cur = cur->prev; 
            }
        }
        if (cmd == 4) {
            if (cur->next != nullptr) {
                cur = cur->next; 
            }
        }

        printCurInfo(); 
    }
    return 0;
}
