#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct Node {
    int y;
    int x; 
};

int n, q; 
int temp[100][100]; 

int power(int N) {
    int ret = 1;
    for (int i = 0; i < N; i++) {
        ret *= 2; 
    }
    return ret; 
}

int arr[100][100]; 
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 }; 
int visited[100][100]; 
int ret = -1; 

void rotate(int y, int x, int size) {
    memset(temp, 0, sizeof(temp));
    int len = size / 2; 

    // 아래쪽에 있는걸 현재 위치에 임시 저장
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            temp[y+i][x+j] = arr[y+i+len][x+j]; 
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            arr[y+i+len][x+j] = arr[y+i+len][x+j+len]; 
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            arr[y+i+len][x+j+len] = arr[y+i][x+j+len]; 
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            arr[y+i][x+j+len] = arr[y+i][x+j];
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            arr[y+i][x+j] = temp[y + i][x + j];
        }
    }
    int de = 1; 
}

void dc(int y, int x, int lev, int size) {
    if (lev == size) {
        rotate(y, x, size); 
        return;
    }
    int len = size / 2; 
    dc(y, x, lev, len);
    dc(y, x + len,lev, len);
    dc(y + len, x, lev, len);
    dc(y + len, x + len, lev, len); 
}

void process(int lev, int N) {
    dc(0, 0, lev, N); 
}

int countVicinity(int y, int x) {
    int cnt = 0; 
    for (int i = 0; i < 4; i++) {
        int ny = y + ydir[i];
        int nx = x + xdir[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue; 
        if (arr[ny][nx] > 0)
            cnt++; 
    }
    if (cnt < 3)
        return 1;
    return 0;
}

void melt() {
    memset(temp, 0, sizeof(temp)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (countVicinity(i, j)) {
                temp[i][j] = 1; 
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (temp[i][j] == 1) {
                arr[i][j] = max(0, arr[i][j] - 1); 
            }
        }
    }
}

int ff(int y, int x) {
    queue<Node>q; 
    q.push({ y, x }); 
    visited[y][x] = 1;

    int size = 0; 

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        size++; 
        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                continue;
            if (visited[ny][nx] == 1)
                continue;
            if (arr[ny][nx] == 0)
                continue;
            visited[ny][nx] = 1;
            q.push({ ny, nx }); 
        }
    }
    return size; 
}

void countGlaciers() {
    int ret = -1; 
    int tot = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tot += arr[i][j]; 
            if (visited[i][j] == 0 && arr[i][j] > 0) {
                ret = max(ff(i, j), ret); 
            }
        }
    }
    cout << tot << '\n' << ret;
}

int main() {
    int de = -1; 
}