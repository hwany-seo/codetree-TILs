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
int countGold(int row, int col, int k) {
    if (k == 0) {
        int cnt = isGold(row, col) ? 1 : 0;
        return cnt;
    }
    int sRow = row - k + 1;
    int sCol = col - k + 1;
    int cnt = 0;
    for (int r = 0; r < 2 * k - 1; r++) {
        for (int c = 0; c < 2 * k - 1; c++) {
            int nr = sRow + r;
            int nc = sCol + c;
            if (!isPossible(nr, nc))continue;
            if (!isGold(nr, nc))continue;
            cnt += grid[nr][nc];
        }
    }

    int dr[] = { -1,1,0,0 };
    int dc[] = { 0,0,-1,1 };
    for (int t = 0; t < 4; t++) {
        int nr = dr[t] * k + row;
        int nc = dc[t] * k + col;
        if (!isPossible(nr, nc)) continue;
        if (!isGold(nr, nc)) continue;

        cnt += grid[nr][nc];

    }
    return cnt; 
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
    for (int k = 0; k < n; k++) {
        int drillCost = k * k + (k + 1) * (k + 1);
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int goldCnt = countGold(row, col, k);
                int goldCost = m * goldCnt;
                if (goldCost - drillCost > 0) {
                    maxGold = max(goldCnt, maxGold);
                }
            }
        }
    }
    cout << maxGold;
    return 0;
}
