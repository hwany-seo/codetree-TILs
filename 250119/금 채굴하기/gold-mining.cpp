#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

bool isPossible(int row, int col) {
    if (row < 0 || col < 0) return false;
    if (row >= n || col >= n) return false;
    return true;
}
bool isGold(int row, int col) {
    return grid[row][col] == 1;
}

int countLineGold(int row, int col, int cnt) {
    int result = 0;
    if(isPossible(row,col))
        result += grid[row][col]; 
    for (int i = 1; i <= cnt / 2; i++) {
        if (!isPossible(row, col - i))
            continue; 
        result += grid[row][col-i]; 
    }
    for (int i = 1; i <= cnt / 2; i++) {
        if (!isPossible(row, col + i))
            continue;
        result += grid[row][col + i];
    }
    return result; 
}
int countGold(int row, int col, int k) {
    int result = 0; 
    int cnt = 1; 
    for (int r = row - k; r < row ; r++) {
        result += countLineGold(r, col, cnt);
        cnt += 2; 
    }
   
    result += countLineGold(row, col, cnt); 
    cnt -= 2; 

    for (int r = row + 1; r <= row + k; r++) {
        result += countLineGold(r, col, cnt); 
        cnt -= 2; 
    }
    return result; 
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }



    int maxGold = 0;
    // Write your code here!
    for (int k = 0; k <= 2 * n + 1; k++) {
        int drillCost = k * k + (k + 1) * (k + 1);
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int goldCnt = countGold(row, col, k);
                int goldCost = m * goldCnt;
                if (goldCost - drillCost >= 0) {
                    maxGold = max(goldCnt, maxGold);
                }
            }
        }
    }
    cout << maxGold;
    return 0;
}
