#include<iostream>
#include<cassert>
using namespace std; 

enum class eDir
{
	garo,sero,degak
};

int N; 
int Board[20][20]; 

bool CanGo(int row, int col)
{
	return Board[row][col] != 1; 
}

int answer; 
void dfs(int row, int col , const eDir d)
{
	if (row == N && col == N) {
		answer++; 
		return; 
	}

	if (CanGo(row + 1, col + 1) && CanGo(row + 1, col) && CanGo(row , col + 1)) {
		dfs(row + 1, col + 1, eDir::degak); 
	}
	if (d != eDir::sero) {
		if (CanGo(row , col + 1)) {
			dfs(row , col + 1, eDir::garo);
		}
	}
	if (d != eDir::garo) {
		if (CanGo(row + 1, col )) {
			dfs(row + 1, col , eDir::sero);
		}
	}
}
int main()
{

	cin >> N;
	for (int row = 0; row <= N + 1; row++) {
		for (int col = 0; col <= N + 1; col++) {
			Board[row][col] = 1;
		}
	}
	for (int row = 1; row <= N; row++) {
		for (int col = 1; col <= N; col++) {
			cin >> Board[row][col]; 
		}
	}

	dfs(1, 2, eDir::garo); 
	cout << answer; 
	return 0; 
}