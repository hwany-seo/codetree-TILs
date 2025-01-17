#include <iostream>

using namespace std;

int n, m;
int grid[100][100];


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Write your code here!

    int result = 0 ;

    // count by row 
    for(int row = 0; row < n; row ++) { 
        int val = -1;
        int cnt =  0;  
        for(int col = 0; col < n; col ++) { 
            if(val != grid[row][col]){
                cnt = 1;
                val = grid[row][col] ;
            }  
            else { 
                cnt ++; 
            }

            if(cnt >= m) break; 
        }

        if(cnt == m) result ++; 
    }

    // count by column
    for(int col = 0; col < n; col ++) { 
        int val = -1;
        int cnt =  0;  
        for(int row = 0; row < n; row ++) { 
            if(val != grid[row][col]){
                cnt = 1;
                val = grid[row][col] ;
            }  
            else { 
                cnt ++; 
            }

            if(cnt >= m) break; 
        }

        if(cnt == m) result ++; 
    }


    cout << result; 

    return 0;
}
