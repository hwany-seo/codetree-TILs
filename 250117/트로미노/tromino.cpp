#include <iostream>

using namespace std;

int n, m;
int grid[200][200];


int firstblocks[4][2][2] = { 
    {
     1,0,
     1,1
    },
    {
     1,1,
     1,0
    },
    {
     1,1,
     0,1
    },
    {
     0,1,
     1,1
    },
};

int secondblocks[4][3][3] = { 
    {
        1,1,1,
        0,0,0,
        0,0,0
    },
    {
        0,0,1,
        0,0,1,
        0,0,1
    },
    {
        0,0,0,
        0,0,0,
        1,1,1
    },
    {
        1,0,0,
        1,0,0,
        1,0,0
    },
}; 


int MaxMaskingFirst(int row, int col) { 
    int answer = 0; 
    for(int i = 0 ;i < 4; i ++) { 
        int result = 0; 
        for(int r = 0 ; r < 2; r ++) { 
            for(int c = 0 ;c  < 2; c ++) { 
                if(firstblocks[i][r][c] == 1){ 
                    result += grid[row + r][col + c]; 
                }
            }
        }
        answer = max(result, answer); 
    }
    return answer; 
}

int MaxMaskingSecond(int row, int col) { 
    int answer = 0 ;
    for(int i = 0 ; i < 4; i ++){ 
        int result =0 ; 
        for(int r = 0 ; r < 3; r ++) { 
            for(int c =0 ; c < 3; c ++) { 
                if(secondblocks[i][r][c] == 1) { 
                    result += grid[row + r][col + c]; 
                }
            }
        }
        answer = max(result, answer); 
    }
    return answer; 
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
        for(int col = 0; col < m; col ++) { 
            if(row + 1 < n && col + 1 < m){ 
                result = max(result, MaxMaskingFirst(row,col)); 
            }
            if(row + 2 < n && col + 2 < m){ 
                result = max(result, MaxMaskingSecond(row,col)); 
            }
        }
    }

    cout << result; 
    return 0;
}
