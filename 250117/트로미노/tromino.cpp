#include <iostream>

using namespace std;

int n, m;
int grid[200][200];

int FirstBlockCount(int row, int col) { 
    int sum = 0 ; 
    for(int r = 0 ; r < 2; r ++) { 
        for(int c = 0 ; c < 2; c ++) { 
            sum += grid[row + r][col + c]; 
        }
    }
    
    int result = 0; 
    result = max(result, sum - grid[row][col]); 
    result = max(result, sum - grid[row+1][col]); 
    result = max(result, sum - grid[row][col+1]); 
    result = max(result, sum - grid[row+1][col+1]); 
    return result; 
}

int SecondBlockGaroCount(int row , int col) { 
    int garoSum = 0; 
    for(int c = 0 ; c < 3; c ++) { 
        garoSum += grid[row][col + c]; 
    }

    return garoSum; 
}

int SecondBlockSeroCount(int row, int col){ 
    int seroSum = 0;
    for(int r = 0; r < 3; r ++) { 
        seroSum += grid[row + r][col]; 
    } 
    return seroSum;
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Write your code here!
    int result = 0; 

    for(int row = 0; row < n; row ++) { 
        for(int col = 0; col < m; col ++){ 
            if(row + 1 >= n || col + 1 >= n)continue; 
            result = max(result, FirstBlockCount(row, col));       
        }
    }

    for(int row = 0; row < n; row ++) { 
        for(int col = 0; col < m; col ++){ 
            if(row + 2 >= n)continue; 
            result = max(result, SecondBlockSeroCount(row, col));       
        }
    }

    
    for(int row = 0; row < n; row ++) { 
        for(int col = 0; col < m; col ++){ 
            if(col + 2 >= m)continue; 
            result = max(result, SecondBlockGaroCount(row, col));       
        }
    }

    cout << result; 
    return 0;
}
