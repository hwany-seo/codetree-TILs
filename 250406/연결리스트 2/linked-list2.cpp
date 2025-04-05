#include <iostream>
#include <cassert>
using namespace std; 

struct Node {
	int data; 
	Node* next = nullptr;
	Node* prev = nullptr; 
	Node(int data)
		:data{data}
	{ }
};
Node* nodes[100001]; // node pool

void insertNext(int i, int j) {
	// a<->b
	Node* a = nodes[i]; 
	Node* b = a->next; 
	Node* single = nodes[j]; 
	
	assert(single->next == nullptr); 
	assert(single->prev == nullptr); 

	if (b != nullptr)
	{
		b->prev = single;
		single->next = b; 
	}
	
	a->next = single; 
	single->prev = a; 
}

void insertPrev(int i, int j) {
	// a-b
	Node* b = nodes[i]; 
	Node* a = b->prev; 
	Node* single = nodes[j]; 
	// a-single-b

	assert(single->next == nullptr);
	assert(single->prev == nullptr); 

	if (a != nullptr) {
		a->next = single; 
		single->prev = a; 
	}

	single->next = b;
	b->prev = single; 

}

void printPrev(int i) {
	Node* prev = nodes[i]->prev; 
	if (prev == nullptr) {
		cout << "0" << " "; 
	}
	else {
		cout << prev->data << " ";
	}
}
void printNext(int i) {
	Node* next = nodes[i]->next; 
	if (next == nullptr) {
		cout << "0" << " "; 
	}
	else {
		cout << next->data << " "; 
	}
}

void makeSingle(int i) {
	Node* toBeSingle = nodes[i]; 
	Node* prevNode = toBeSingle->prev; 
	Node* nextNode = toBeSingle->next; 

	// prevNode-nextNode
	if(prevNode != nullptr)prevNode->next = nextNode; 
	if(nextNode != nullptr)nextNode->prev = prevNode; 

	toBeSingle->next = nullptr; 
	toBeSingle->prev = nullptr; 
}
int main() {
	//freopen_s(new FILE*, "Text2.txt", "r", stdin); 
	int N, Q; 
	cin >> N >> Q; 

	for (int node = 1; node <= N; node++) {
		nodes[node] = new Node(node); 
	}

	for (int t = 0; t < Q; t++) {
		int cmd; 
		cin >> cmd; 

		if (cmd == 1) {
			// makeSingle (delete)
			int i; 
			cin >> i; 
			makeSingle(i); 
		}
		if (cmd == 2) {
			int i, j; 
			cin >> i >> j; 
			insertPrev(i, j); 
		}
		if (cmd == 3) {
			int i, j; 
			cin >> i >> j; 
			insertNext(i, j); 
		}
		if (cmd == 4) {
			int i; 
			cin >> i; 
			printPrev(i); 
			printNext(i); 
			cout << endl; 
		}
	}
	for (int node = 1; node <= N; node++) {
		printNext(node); 
	}
	return 0; 
}
